#include "qmanager.h"
#include "qclass.h"
#include <QDir>
#include <QMessageBox>
#include <QJson/Serializer>
#include <QJson/Parser>
#include <QFile>
#include <qdeletearea.h>
#include "qrule.h"

QManager::QManager(QObject *parent, QWidget* parentWidget) :
    QObject(parent)
{
    this->bg = 0;
    this->pWidget = parentWidget;
    this->raft = 0;
    this->delArea = 0;
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
    this->sprites.push_back(sprite);
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
    leftRaftPosition.insert("x", this->raft->getPosition("leftSide").x());
    leftRaftPosition.insert("y", this->raft->getPosition("leftSide").y());

    QVariantMap rightRaftPosition;
    rightRaftPosition.insert("x", this->raft->getPosition("rightSide").x());
    rightRaftPosition.insert("y", this->raft->getPosition("rightSide").y());

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
                sprite.insert("defaultSide", "leftSide"); // Добавить кнопочку в интерфейсе

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

                QVariantMap sRaft;
                sRaft.insert("x", this->sprites[j]->getPosition("onRaft").x());
                sRaft.insert("y", this->sprites[j]->getPosition("onRaft").y());
                sGeometry.insert("onRaftPosition", sRaft);
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

void QManager::loadFromFile(QString path)
{
    QJson::Parser parser;
    QFile file(path+"/info.txt");
    file.open(QIODevice::ReadOnly);
    bool ok;

    QVariantMap result = parser.parse(&file, &ok).toMap();

    if (!ok){
        QMessageBox msg;
        msg.setText(QString::fromLocal8Bit("Ошибка чтения. Возможно файл поврежден"));
        msg.exec();
    }

    // Заголовок и условие
    this->setName(result["title"].toString());
    this->setTask(result["task"].toString());

    // Фон
    this->bg = new QLabel(this->pWidget);
    bg->setPixmap(QPixmap(path+"/"+result["background"].toString()).scaled(QSize(800,600),
                                                                           Qt::KeepAspectRatio, Qt::SmoothTransformation));
    bg->setGeometry(0, 0, 800, 600);
    bg->show();

    // Паромщик
    QVariantMap raftMap = result["raft"].toMap();
    this->raft = new QRaft(this->pWidget);
    this->raft->setItems(raftMap["activeItems"].toInt());
    this->raft->setPixmap(QPixmap(path+"/"+raftMap["picture"].toString()).
                          scaled(QSize(raftMap["geometry"].toMap()["width"].toInt(), raftMap["geometry"].toMap()["height"].toInt()),
                                 Qt::KeepAspectRatio, Qt::SmoothTransformation));
    this->raft->resize(QSize(raftMap["geometry"].toMap()["width"].toInt(), raftMap["geometry"].toMap()["height"].toInt()));
    this->raft->setPostion("leftSide", QPoint(raftMap["geometry"].toMap()["leftPostion"].toMap()["x"].toInt(),
                                              raftMap["geometry"].toMap()["leftPostion"].toMap()["y"].toInt()));
    this->raft->setPostion("rightSide", QPoint(raftMap["geometry"].toMap()["rightPostion"].toMap()["x"].toInt(),
                                               raftMap["geometry"].toMap()["rightPostion"].toMap()["y"].toInt()));
    this->raft->setDefaultSide(raftMap["defaultSide"].toString());
    this->raft->setState(raftMap["defaultSide"].toString());
    this->raft->setMovable(raftMap["isMovable"].toBool());
    this->raft->show();

    connect(this->raft, SIGNAL(spriteDroped(int)), this, SLOT(spriteToRaft(int)));

    // Классы
    QVariantList classes = result["classes"].toList();
    int id = 0;
    foreach (QVariant item, classes) {
        QVariantMap _item = item.toMap();
        QVector<QPixmap> imgs;
        QVariantList spritesList = _item["sprites"].toList();
        foreach (QVariant sprite, spritesList) {
            QVariantMap _sprite = sprite.toMap();
            QSprite* __sprite = new QSprite(this->pWidget);
            __sprite->setDefaultSide(_sprite["defaultSide"].toString());
            __sprite->setPostion("leftSide", QPoint(_sprite["geometry"].toMap()["leftPosition"].toMap()["x"].toInt(),
                                                    _sprite["geometry"].toMap()["leftPosition"].toMap()["y"].toInt()));
            __sprite->setPostion("rightSide", QPoint(_sprite["geometry"].toMap()["rightPosition"].toMap()["x"].toInt(),
                                                    _sprite["geometry"].toMap()["rightPosition"].toMap()["y"].toInt()));
            __sprite->setPostion("onRaft", QPoint(_sprite["geometry"].toMap()["onRaftPosition"].toMap()["x"].toInt(),
                                                    _sprite["geometry"].toMap()["onRaftPosition"].toMap()["y"].toInt()));
            __sprite->resize(QSize(_sprite["geometry"].toMap()["width"].toInt(), _sprite["geometry"].toMap()["height"].toInt()));
            __sprite->setClassName(_item["name"].toString());
            __sprite->setState(_sprite["defaultSide"].toString());

            QPixmap* pix = new QPixmap(path+"/"+_sprite["pixmap"].toString());
            __sprite->setPixmap(*pix);
            __sprite->setId(id);
            __sprite->show();
            connect(__sprite, SIGNAL(deleteDrop(int)), this, SLOT(deleteAreaShow()));
            imgs.push_back(*pix);

            this->addSprite(__sprite);
            id++;
        }

        imgs.remove(0, 1);

        this->addType(_item["name"].toString(),
                      _item["children"].toInt(),
                      QPixmap(path+"/"+_item["defaultImage"].toString()),
                      imgs);
    }

    // Правила
    QVariantList rulesList = result["rules"].toList();
    foreach (QVariant rule, rulesList) {
        QVariantMap _rule = rule.toMap();

        if(_rule["advRule"].toString() != "" && _rule["advObject"].toString() != 0){
            this->addRule(_rule["object1"].toString(),
                          _rule["object2"].toString(),
                          _rule["rule"].toString(),
                          _rule["advRule"].toString(),
                          _rule["ruleadvObject"].toString());
        }
        else{
            this->addRule(_rule["object1"].toString(),
                          _rule["object2"].toString(),
                          _rule["rule"].toString());
        }
    }
    return;
}

void QManager::rulesClear()
{
    this->rules.clear();
}

void QManager::toLeftSide()
{
    if(this->raft->getMovable()){
        // Плот наблюдатель
        // Значит, проверяем только берег, от которого отъезжаем

        for (int i = 0; i<this->rules.size(); i++){
            QRule *el = this->rules[i];

            if (el->getRule() == "forbid"){
                bool obj1 = false;
                bool obj2 = false;
                for (int j = 0; j<this->sprites.size(); j++){
                    if( this->sprites[j]->getState() == "rightSide" ){
                        if(this->sprites[j]->getClassName() == el->getObject1()){
                            obj1 = true;
                        } else if(this->sprites[j]->getClassName() == el->getObject2()){
                            obj2 = true;
                        }
                    }
                }
                if (obj1 & obj2){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("Действие невозможно"));
                    msg.exec();

                    return;
                }
                else{
                    // Можно ехать
                    this->raft->setState("leftSide");

                    for (int j = 0; j<this->sprites.size(); j++){
                        if(this->sprites[j]->getState() == "onRaft"){
                            this->sprites[j]->setState("leftSide");
                        }
                    }
                    return;
                }
            }
        }
    } else{
        // Проверять оба берега
        for (int i = 0; i<this->rules.size(); i++){
            QRule *el = this->rules[i];

            if (el->getRule() == "forbid"){
                bool lObj1 = false;
                bool lObj2 = false;

                bool rObj1 = false;
                bool rObj2 = false;

                // Проверяем левый берег

                for (int j = 0; j<this->sprites.size(); j++){
                    if( this->sprites[j]->getState() == "leftSide" ){
                        if(this->sprites[j]->getClassName() == el->getObject1()){
                            lObj1 = true;
                        } else if(this->sprites[j]->getClassName() == el->getObject2()){
                            lObj2 = true;
                        }
                    }
                    else{
                        if(this->sprites[j]->getClassName() == el->getObject1()){
                            rObj1 = true;
                        } else if(this->sprites[j]->getClassName() == el->getObject2()){
                            rObj2 = true;
                        }
                    }
                }
                if ((lObj1 && lObj2) || (rObj1 && rObj2)){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("Действие невозможно"));
                    msg.exec();

                    return;
                }
                else{
                    // Можно ехать
                    this->raft->setState("leftSide");

                    for (int j = 0; j<this->sprites.size(); j++){
                        if(this->sprites[j]->getState() == "onRaft"){
                            this->sprites[j]->setState("leftSide");
                        }
                    }
                    return;
                }
            }
        }
    }
}

void QManager::toRightSide()
{
    if(this->raft->getMovable()){
        // Плот наблюдатель
        // Значит, проверяем только берег, от которого отъезжаем

        for (int i = 0; i<this->rules.size(); i++){
            QRule *el = this->rules[i];

            if (el->getRule() == "forbid"){
                bool obj1 = false;
                bool obj2 = false;
                for (int j = 0; j<this->sprites.size(); j++){
                    if( this->sprites[j]->getState() == "leftSide" ){
                        if(this->sprites[j]->getClassName() == el->getObject1()){
                            obj1 = true;
                        } else if(this->sprites[j]->getClassName() == el->getObject2()){
                            obj2 = true;
                        }
                    }
                }
                if (obj1 & obj2){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("Действие невозможно"));
                    msg.exec();

                    return;
                }
                else{
                    // Можно ехать
                    this->raft->setState("rightSide");

                    for (int j = 0; j<this->sprites.size(); j++){
                        if(this->sprites[j]->getState() == "onRaft"){
                            this->sprites[j]->setState("rightSide");
                        }
                    }
                    return;
                }
            }
        }
    } else{
        // Проверять оба берега
        for (int i = 0; i<this->rules.size(); i++){
            QRule *el = this->rules[i];

            if (el->getRule() == "forbid"){
                bool lObj1 = false;
                bool lObj2 = false;

                bool rObj1 = false;
                bool rObj2 = false;

                // Проверяем левый берег

                for (int j = 0; j<this->sprites.size(); j++){
                    if( this->sprites[j]->getState() == "leftSide" ){
                        if(this->sprites[j]->getClassName() == el->getObject1()){
                            lObj1 = true;
                        } else if(this->sprites[j]->getClassName() == el->getObject2()){
                            lObj2 = true;
                        }
                    }
                    else{
                        if(this->sprites[j]->getClassName() == el->getObject1()){
                            rObj1 = true;
                        } else if(this->sprites[j]->getClassName() == el->getObject2()){
                            rObj2 = true;
                        }
                    }
                }
                if ((lObj1 && lObj2) || (rObj1 && rObj2)){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("Действие невозможно"));
                    msg.exec();

                    return;
                }
                else{
                    // Можно ехать
                    this->raft->setState("rightSide");

                    for (int j = 0; j<this->sprites.size(); j++){
                        if(this->sprites[j]->getState() == "onRaft"){
                            this->sprites[j]->setState("rightSide");
                        }
                    }
                    return;
                }
            }
        }
    }
}

void QManager::spriteToRaft(int id)
{
    int active = 0;
    for (int i = 0; i<this->sprites.size(); i++){
        if (this->sprites[i]->getState() == "onRaft"){
            ++active;
        }
    }

    if(active >= this->raft->getItems()){
        QMessageBox msg;
        msg.setText(QString::fromLocal8Bit("Плот переполнен"));
        msg.exec();
        return;
    }

    if(this->sprites[id]->getState() == this->raft->getState()){
        if (this->raft->getState() == this->sprites[id]->getDefaultSide()){
            this->sprites[id]->setState("onRaft");
            return;
        }
        else{
            // Смещение по X
            int diffX = 0;
            diffX = max(this->sprites[id]->getPosition("onRaft").x(),
                        this->raft->getPosition(this->sprites[id]->getDefaultSide()).x())
                    - min(this->sprites[id]->getPosition("onRaft").x(),
                          this->raft->getPosition(this->sprites[id]->getDefaultSide()).x());

            // Смещение по Y
            int diffY = 0;
            diffY = max(this->sprites[id]->getPosition("onRaft").y(),
                        this->raft->getPosition(this->sprites[id]->getDefaultSide()).y())
                    - min(this->sprites[id]->getPosition("onRaft").y(),
                          this->raft->getPosition(this->sprites[id]->getDefaultSide()).y());

            int newX = 0;
            int newY = 0;

            if(this->sprites[id]->getPosition("onRaft").x() >
                    this->raft->getPosition(this->sprites[id]->getDefaultSide()).x()){
                newX = this->raft->getPosition(this->raft->getState()).x() + diffX;
            }
            else{
                newX = this->raft->getPosition(this->raft->getState()).x() - diffX;
            }

            if(this->sprites[id]->getPosition("onRaft").y() >
                    this->raft->getPosition(this->sprites[id]->getDefaultSide()).y()){
                newY = this->raft->getPosition(this->raft->getState()).y() + diffY;
            }
            else{
                newY = this->raft->getPosition(this->raft->getState()).y() - diffY;
            }

            this->sprites[id]->setState("onRaft");
            this->sprites[id]->move(newX, newY);

            return;


        }
    }
    else{
        QMessageBox msg;
        msg.setText(QString::fromLocal8Bit("Объект и плот находятся на разных берегах"));
        msg.setIconPixmap(QPixmap(":/main/warning"));
        msg.exec();
    }
}

void QManager::deleteAreaShow()
{
    if (delArea == 0){
        delArea = new QDeleteArea(this->pWidget);
    }
    delArea->setGeometry(0, 460, 140, 140);
    delArea->setStyleSheet("border: 2px dashed #555; border-radius:10px;");
    delArea->raise();
    delArea->show();

    connect(delArea, SIGNAL(returnToSide(int)), this, SLOT(returnToSide(int)));
}

void QManager::returnToSide(int id)
{
    this->sprites[id]->setState(this->raft->getState());
    this->delArea->hide();
}
