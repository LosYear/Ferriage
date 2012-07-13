#include "qmanager.h"
#include "qclass.h"

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

void QManager::addRule(QString object1, QString object2, QString rule)
{

    QRule* _tmp = new QRule(object1, object2, rule);
    this->rules.push_back(_tmp);
}

void QManager::addRule(QString object1, QString object2, QString rule, QString advanced)
{
    QRule* _tmp = new QRule(object1, object2, rule, advanced);
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
