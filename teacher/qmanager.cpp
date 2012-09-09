#include "qmanager.h"
#include "qclass.h"
#include <QDir>
#include <QMessageBox>
#include <QJson/Serializer>
#include <QFile>
#include "spritedialog.h"

QManager::QManager(QObject *parent, QWidget* parentWidget) :
    QObject(parent)
{
    this->bg = 0;
    this->pWidget = parentWidget;
    this->raft = 0;
}

void QManager::setName(QString name)
{
    this->name = name;
}

void QManager::setTask(QString task)
{
    this->task = task;

}

void QManager::setBackground(QString filename)
{
    this->fBackground = filename;

    // Отрисовываем
    if ( this->bg == 0 ){
        // Полная отрисовка

        this->bg = new QLabel(pWidget);
    }

    QPixmap* pix = new QPixmap(filename);
    pix->scaled(800, 600, Qt::IgnoreAspectRatio);

    this->bg->setPixmap(*pix);
    this->bg->adjustSize();
    this->bg->setGeometry(0,0, 800, 600);
    this->bg->show();

    this->bg->lower();

}

QLabel *QManager::getBackground()
{
    return this->bg;
}

void QManager::addType(QString name, int count, QPixmap stdImg, QVector<QPixmap> imgs)
{
    QClass tmp;
    tmp.setCount(count);
    tmp.setName(name);

    // Создаем корректный вектор
    QVector <QPixmap> allImgs;

    allImgs.clear();
    allImgs.insert(0, stdImg);

    for ( int i = 0; i < count-1; i++)
    {
        allImgs.insert(i+1, imgs[i]);
    }

    tmp.setImgs(allImgs);

    for ( int i = 0; i < types.size(); i++){
        if (name == types[i].getName()){
            tmp.setPainted(true);
            tmp.setEdited(true);
            types[i] = tmp;
            return;
        }
    }
    this->types.push_back(tmp);
}

void QManager::addType(QClass type)
{
    this->types.push_back(type);
}

QString QManager::getName()
{
    return this->name;
}

QString QManager::getTask()
{
    return this->task;
}

void QManager::addRule(QString object1, QString object2, QString rule)
{

    QRule* _tmp = new QRule(object1, object2, rule);
    this->rules.push_back(_tmp);
}

void QManager::addRule(QString object1, QString object2, QString rule, QString adv_rule, QString adv_obj)
{
    QRule* _tmp = new QRule(object1, object2, rule, adv_rule, adv_obj);
    this->rules.push_back(_tmp);
}

int QManager::typesSize()
{
    return this->types.size();
}

int QManager::spritesSize()
{
    return this->sprites.size();
}

QClass *QManager::getTypesItem(int id)
{
    return &this->types[id];
}


QVector<QClass>::iterator QManager::getTypesBeginIterator()
{
    return this->types.begin();
}

QVector<QClass>::iterator QManager::getTypesEndIterator()
{
    return this->types.end();
}

void QManager::addSprite(QSprite *sprite)
{
    sprite->setId(this->sprites.size());
    sprite->setDefaultSide("leftSide");
    sprite->setMovable(true);
    this->sprites.push_back(sprite);

    connect(sprite, SIGNAL(doubleClicked(int)), this, SLOT(spriteDoubleClicked(int)));
}

QSprite *QManager::getSprite(int id)
{
    return this->sprites[id];
}

QRaft *QManager::getRaft()
{
    return this->raft;
}

void QManager::setRaft(QRaft *raft)
{
    this->raft = raft;
}

void QManager::saveToFile(QString path)
{
    QDir* dir = new QDir(path);

    if (!dir->exists(path)){
        dir->mkdir(path);
    }

    QVariantMap json;
    // Начинаем копирование
    // Также, записываем данные в JSON

    this->bg->pixmap()->save(path+"/background.png", "PNG");

    json.insert("background", "background.png");

    // Информация о переправе
    json.insert("title", this->getName());
    json.insert("task", this->getTask());

    // Плот
    QVariantMap jRaft;

    this->raft->pixmap()->save(path+"/raft.png", "PNG");
    jRaft.insert("picture", "raft.png");
    jRaft.insert("activeItems", this->raft->getItems());

    // Геометрия плота
    QVariantMap raftGeometry;
    raftGeometry.insert("width", this->raft->width());
    raftGeometry.insert("height", this->raft->height());

    QVariantMap leftRaftPosition;
    leftRaftPosition.insert("x", this->raft->getPositon("leftSide").x());
    leftRaftPosition.insert("y", this->raft->getPositon("leftSide").y());

    QVariantMap rightRaftPosition;
    rightRaftPosition.insert("x", this->raft->getPositon("rightSide").x());
    rightRaftPosition.insert("y", this->raft->getPositon("rightSide").y());

    raftGeometry.insert("leftPostion", leftRaftPosition);
    raftGeometry.insert("rightPostion", rightRaftPosition);

    jRaft.insert("geometry",raftGeometry);
    jRaft.insert("isMovable", this->raft->getMovable());
    jRaft.insert("defaultSide", this->raft->getDefaultSide());

    json.insert("raft", jRaft);

    // Классы
    QVariantList classes;
    for (int i = 0; i<this->types.size(); i++){
        QVariantMap _class;
        _class.insert("name", this->types[i].getName());
        _class.insert("children", this->types[i].getCount());
        _class.insert("defaultImage", this->types[i].getName()+"_defaultImage.png");
        this->types[i].getImg(0).save(path+"/"+this->types[i].getName()+"_defaultImage.png");

        // Формируем список спрайтов
        QVariantList _sprites;
        int k = 0;
        for ( int j = 0; j<this->sprites.size(); j++){
            if (this->types[i].getName() == this->sprites[j]->getClassName()){
                QVariantMap sprite;
                this->sprites[j]->pixmap()->
                        save(path+"/"+this->types[i].getName()+"_"+QString::number(k)+".png",
                             "PNG");
                sprite.insert("pixmap", this->types[i].getName()+"_"+QString::number(k)+".png");
                sprite.insert("defaultSide", this->sprites[j]->getDefaultSide()); // Добавить кнопочку в интерфейсе
                sprite.insert("isMovable", this->sprites[j]->getMovable());

                QVariantMap sGeometry;
                sGeometry.insert("width", this->sprites[j]->width());
                sGeometry.insert("height", this->sprites[j]->height());

                QVariantMap sLeft;
                sLeft.insert("x", this->sprites[j]->getPosition("leftSide").x());
                sLeft.insert("y", this->sprites[j]->getPosition("leftSide").y());
                sGeometry.insert("leftPosition", sLeft);

                QVariantMap sRight;
                sRight.insert("x", this->sprites[j]->getPosition("rightSide").x());
                sRight.insert("y", this->sprites[j]->getPosition("rightSide").y());
                sGeometry.insert("rightPosition", sRight);

                QVariantMap sRaftL;
                sRaftL.insert("x", this->sprites[j]->getPosition("onRaftLeft").x());
                sRaftL.insert("y", this->sprites[j]->getPosition("onRaftLeft").y());

                QVariantMap sRaftR;
                sRaftR.insert("x", this->sprites[j]->getPosition("onRaftRight").x());
                sRaftR.insert("y", this->sprites[j]->getPosition("onRaftRight").y());

                sGeometry.insert("onRaftPositionLeft", sRaftL);
                sGeometry.insert("onRaftPositionRight", sRaftR);

                sprite.insert("geometry", sGeometry);
                k++;
                _sprites.push_back(sprite);
            }
        }

        _class.insert("sprites", _sprites);
        classes.push_back(_class);

    }
    json.insert("classes", classes);

    // Правила
    QVariantList jRules;
    for (int i=0; i<this->rules.size(); i++){
        QVariantMap rule;
        rule.insert("object1", this->rules[i]->getObject1());
        rule.insert("rule", this->rules[i]->getRule());
        rule.insert("object2", this->rules[i]->getObject2());

        if(this->rules[i]->getAdvRule() != ""){
            rule.insert("advRule", this->rules[i]->getAdvRule());
            rule.insert("advObject", this->rules[i]->getAdvObject());
        }
        jRules.push_back(rule);
    }

    json.insert("rules", jRules);

    // Сохраняем в файл JSON
    QFile file(path+"/info.txt");
    file.open(QIODevice::WriteOnly);

    QJson::Serializer serializer;
    serializer.serialize(json, &file);
}

void QManager::rulesClear()
{
    this->rules.clear();
}

void QManager::spriteDoubleClicked(int id)
{
    SpriteDialog* dialog = new SpriteDialog(id, this);
    dialog->exec();

    this->sprites[id]->setPixmap(this->sprites[id]->fullImg.scaled(
                                     this->sprites[id]->width(),
                                     this->sprites[id]->height(),
                                     Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation));
}
