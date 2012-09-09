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

    // ������������
    if ( this->bg == 0 ){
        // ������ ���������

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

    // ������� ���������� ������
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
    // �������� �����������
    // �����, ���������� ������ � JSON

    this->bg->pixmap()->save(path+"/background.png", "PNG");

    json.insert("background", "background.png");

    // ���������� � ���������
    json.insert("title", this->getName());
    json.insert("task", this->getTask());

    // ����
    QVariantMap jRaft;

    this->raft->pixmap()->save(path+"/raft.png", "PNG");
    jRaft.insert("picture", "raft.png");
    jRaft.insert("activeItems", this->raft->getItems());

    // ��������� �����
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

    // ������
    QVariantList classes;
    for (int i = 0; i<this->types.size(); i++){
        QVariantMap _class;
        _class.insert("name", this->types[i].getName());
        _class.insert("children", this->types[i].getCount());
        _class.insert("defaultImage", this->types[i].getName()+"_defaultImage.png");
        this->types[i].getImg(0).save(path+"/"+this->types[i].getName()+"_defaultImage.png");

        // ��������� ������ ��������
        QVariantList _sprites;
        int k = 0;
        for ( int j = 0; j<this->sprites.size(); j++){
            if (this->types[i].getName() == this->sprites[j]->getClassName()){
                QVariantMap sprite;
                this->sprites[j]->pixmap()->
                        save(path+"/"+this->types[i].getName()+"_"+QString::number(k)+".png",
                             "PNG");
                sprite.insert("pixmap", this->types[i].getName()+"_"+QString::number(k)+".png");
                sprite.insert("defaultSide", "leftSide"); // �������� �������� � ����������

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

    // �������
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

    // ��������� � ���� JSON
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
        msg.setText(QString::fromLocal8Bit("������ ������. �������� ���� ���������"));
        msg.exec();
    }

    // ��������� � �������
    this->setName(result["title"].toString());
    this->setTask(result["task"].toString());

    // ���
    this->bg = new QLabel(this->pWidget);
    bg->setPixmap(QPixmap(path+"/"+result["background"].toString()).scaled(QSize(800,600),
                                                                           Qt::KeepAspectRatio, Qt::SmoothTransformation));
    bg->setGeometry(0, 0, 800, 600);
    bg->show();

    // ��������
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

    // ������
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
            __sprite->setPostion("onRaftLeft", QPoint(_sprite["geometry"].toMap()["onRaftPositionLeft"].toMap()["x"].toInt(),
                                                    _sprite["geometry"].toMap()["onRaftPositionLeft"].toMap()["y"].toInt()));
            __sprite->setPostion("onRaftRight", QPoint(_sprite["geometry"].toMap()["onRaftPositionRight"].toMap()["x"].toInt(),
                                                    _sprite["geometry"].toMap()["onRaftPositionRight"].toMap()["y"].toInt()));
            __sprite->resize(QSize(_sprite["geometry"].toMap()["width"].toInt(), _sprite["geometry"].toMap()["height"].toInt()));
            __sprite->setClassName(_item["name"].toString());
            __sprite->setState(_sprite["defaultSide"].toString());
            __sprite->setMovable(_sprite["isMovable"].toBool());

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

    // �������
    QVariantList rulesList = result["rules"].toList();
    foreach (QVariant rule, rulesList) {
        QVariantMap _rule = rule.toMap();

        if(_rule["advRule"].toString() != "" && _rule["advObject"].toString() != ""){
            this->addRule(_rule["object1"].toString(),
                          _rule["object2"].toString(),
                          _rule["rule"].toString(),
                          _rule["advRule"].toString(),
                          _rule["advObject"].toString());
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
        // ���� �����������
        // ������, ��������� ������ �����, �� �������� ���������

        for (int i = 0; i<this->rules.size(); i++){
            QRule *el = this->rules[i];

            if (el->getRule() == "forbid"){
                if (!this->checkForbid(*el, this->raft->getMovable(), "rightSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;
                }
            }
            else if (el->getRule() == "advanced forbid"){
                if (!this->checkAdvancedForbid(*el, this->raft->getMovable(), "rightSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;

                }
            }
            else if(el->getRule() == ">="){
                if (!checkMoreOrEqually(*el, this->raft->getMovable(), "rightSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;

                }
            }
        }
    } else{
        if(this->countObjectsWithState("onRaftRight") <= 0){
            QMessageBox msg;
            msg.setText(QString::fromLocal8Bit("���� ����"));
            msg.setIconPixmap(QPixmap(":/main/warning"));
            msg.exec();
            return;
        }

        bool can = false;

        for (int i = 0; i<this->sprites.size(); i++){
            if(this->sprites[i]->getState() == "onRaftRight" && this->sprites[i]->getMovable()){
                can = true;
            }
        }

        if(!can){
            QMessageBox msg;
            msg.setIconPixmap(QPixmap(":/main/sad"));
            msg.setText(QString::fromLocal8Bit("�������� ����������"));
            msg.exec();

            return;
        }

        // ��������� ��� ������
        for (int i = 0; i<this->rules.size(); i++){
            QRule *el = this->rules[i];

            if (el->getRule() == "forbid"){
                if (!this->checkForbid(*el, this->raft->getMovable(), "leftSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;
                }
            } else if (el->getRule() == "advanced forbid"){
                if (!this->checkAdvancedForbid(*el, this->raft->getMovable(), "leftSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;

                }
            }
            else if(el->getRule() == ">="){
                if (!checkMoreOrEqually(*el, this->raft->getMovable(), "leftSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;

                }
            }
        }
    }
    // ������
    // ����� �����
    this->move("leftSide");
    return;
}

void QManager::toRightSide(){
    if(this->raft->getMovable()){
        // ���� �����������
        // ������, ��������� ������ �����, �� �������� ���������

        for (int i = 0; i<this->rules.size(); i++){
            QRule *el = this->rules[i];

            if (el->getRule() == "forbid"){
                if (!this->checkForbid(*el, this->raft->getMovable(), "leftSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;
                }
            }
            else if (el->getRule() == "advanced forbid"){

                if (!this->checkAdvancedForbid(*el, this->raft->getMovable(), "leftSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;

                }
            }
            else if(el->getRule() == ">="){
                if(!this->checkMoreOrEqually(*el, this->raft->getMovable(), "leftSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;
                }
            }
        }
    } else{
        // ������� ������� �������� �� �����

        if(this->countObjectsWithState("onRaftLeft") <= 0){
            QMessageBox msg;
            msg.setText(QString::fromLocal8Bit("���� ����"));
            msg.setIconPixmap(QPixmap(":/main/warning"));
            msg.exec();
            return;
        }

        bool can = false;

        for (int i = 0; i<this->sprites.size(); i++){
            if(this->sprites[i]->getState() == "onRaftLeft" && this->sprites[i]->getMovable()){
                can = true;
            }
        }

        if(!can){
            QMessageBox msg;
            msg.setIconPixmap(QPixmap(":/main/sad"));
            msg.setText(QString::fromLocal8Bit("�������� ����������"));
            msg.exec();

            return;
        }

        // ��������� ��� ������
        for (int i = 0; i<this->rules.size(); i++){
            QRule *el = this->rules[i];

            if (el->getRule() == "forbid"){

                if (!this->checkForbid(*el, this->raft->getMovable(), "")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;
                }
            } else if (el->getRule() == "advanced forbid"){

                if (!checkAdvancedForbid(*el, this->raft->getMovable(), "rightSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;

                }
            }
            else if( el->getRule() == ">="){
                if(!this->checkMoreOrEqually(*el, this->raft->getMovable(), "rightSide")){
                    QMessageBox msg;
                    msg.setIconPixmap(QPixmap(":/main/sad"));
                    msg.setText(QString::fromLocal8Bit("�������� ����������"));
                    msg.exec();

                    return;
                }
            }
        }
    }

    this->move("rightSide");
}

void QManager::move(QString side)
{
    // ������ ������� �� ����� side
    this->raft->setState(side);

    for (int j = 0; j<this->sprites.size(); j++){
        if(this->sprites[j]->getState() == "onRaftLeft"
                || this->sprites[j]->getState() == "onRaftRight" ){
            this->sprites[j]->setState(side);
        }
    }
}

bool QManager::checkForbid(QRule r, bool isMovable, QString side)
{
    if(r.getRule() == "forbid"){
        if(isMovable){
            // ���� ��������� ���, ��������� ������ ���� �����
            bool obj1 = false;
            bool obj2 = false;
            for (int i = 0; i<this->sprites.size(); i++){
                if( this->sprites[i]->getState() == side ){
                    if(this->sprites[i]->getClassName() == r.getObject1()){
                        obj1 = true;
                    } else if(this->sprites[i]->getClassName() == r.getObject2()){
                        obj2 = true;
                    }
                }
            }
            if (obj1 & obj2){
                return false;
            }
        }
        else{
            // ��������� ��� ������
            bool lObj1 = false;
            bool lObj2 = false;

            bool rObj1 = false;
            bool rObj2 = false;


            for (int i = 0; i<this->sprites.size(); i++){
                QString left, right;
                if( side == "rightSide"){
                    right = this->sprites[i]->getState();
                } else{
                    left = this->sprites[i]->getState();
                }

                if( this->sprites[i]->getState() == "leftSide" ||
                        left == "onRaftLeft" || left == "onRaftRight" ){
                    if(this->sprites[i]->getClassName() == r.getObject1()){
                        lObj1 = true;
                    } else if(this->sprites[i]->getClassName() == r.getObject2()){
                        lObj2 = true;
                    }
                }
                else if(this->sprites[i]->getState() == "rightSide"
                        || right == "onRaftLeft" || right == "onRaftRight"){
                    if(this->sprites[i]->getClassName() == r.getObject1()){
                        rObj1 = true;
                    } else if(this->sprites[i]->getClassName() == r.getObject2()){
                        rObj2 = true;
                    }
                }
            }
            if ((lObj1 && lObj2) || (rObj1 && rObj2)){
                return false;
            }
        }
    }

    return true;
}

bool QManager::checkAdvancedForbid(QRule r, bool isMovable, QString side)
{
    if(r.getRule() == "advanced forbid"){
        if(isMovable){
            bool obj1 = false;
            bool obj2 = false;
            bool ex = false;

            for (int i = 0; i<this->sprites.size(); i++){
                if( this->sprites[i]->getState() == side){
                    if(this->sprites[i]->getClassName() == r.getObject1()){
                        obj1 = true;
                    } else if(this->sprites[i]->getClassName() == r.getObject2()){
                        obj2 = true;
                    }
                    else if (this->sprites[i]->getClassName() == r.getAdvObject()){
                        ex = true;
                    }
                }
            }

            if ((obj1 && obj2) && !ex){
                return false;

            }
        } else{
            bool lObj1 = false;
            bool lObj2 = false;
            bool lEx = false;

            bool rObj1 = false;
            bool rObj2 = false;
            bool rEx = false;

            for (int i = 0; i<this->sprites.size(); i++){
                QString left, right;
                if( side == "rightSide"){
                    right = this->sprites[i]->getState();
                } else{
                    left = this->sprites[i]->getState();
                }
                if( this->sprites[i]->getState() == "leftSide" ||
                        left == "onRaftLeft" || left == "onRaftRight" ){
                    if(this->sprites[i]->getClassName() == r.getObject1()){
                        lObj1 = true;
                    } else if(this->sprites[i]->getClassName() == r.getObject2()){
                        lObj2 = true;
                    }
                    else if (this->sprites[i]->getClassName() == r.getAdvObject()){
                        lEx = true;
                    }
                } else if(this->sprites[i]->getState() == "rightSide"
                          || right == "onRaftRight" || right == "onRaftLeft"){
                    if(this->sprites[i]->getClassName() == r.getObject1()){
                        rObj1 = true;
                    } else if(this->sprites[i]->getClassName() == r.getObject2()){
                        rObj2 = true;
                    }
                    else if (this->sprites[i]->getClassName() == r.getAdvObject()){
                        rEx = true;
                    }
                }
            }

            if ( ((lObj1 && lObj2) && !lEx) || ((rObj1 && rObj2) && !rEx)){
                return false;

            }
        }
    }

    return true;
}

int QManager::countObjectsWithState(QString state)
{
    int count = 0;
    for (int i = 0; i<this->sprites.size(); i++){
        if(this->sprites[i]->getState() == state){
            count++;
        }
    }

    return count;
}

int QManager::countObjects(QString state, QString className)
{
    int count = 0;
    for(int i = 0; i<this->sprites.size(); i++){
        if((this->sprites[i]->getClassName() == className) && (this->sprites[i]->getState() == state) ){
            count++;
        }
    }
    return count;
}

bool QManager::checkMoreOrEqually(QRule r, bool isMovable, QString side)
{
    if( r.getRule() == ">="){
        if(isMovable){
            int obj1 = countObjects(side, r.getObject1());
            int obj2 = countObjects(side, r.getObject2());
            if(obj2>obj1 && obj1 != 0 && obj2 != 0){
                return false;
            }
        }
       else{
            int lObj1 = countObjects("leftSide", r.getObject1());
            int lObj2 = countObjects("leftSide", r.getObject2());

            int rObj1 = countObjects("rightSide", r.getObject1());
            int rObj2 = countObjects("rightSide", r.getObject2());

            int oObj1 = countObjects("onRaftLeft", r.getObject1())
                    + countObjects("onRaftRight", r.getObject1());
            int oObj2 = countObjects("onRaftLeft", r.getObject2())
                    + countObjects("onRaftRight", r.getObject2());

            if(side == "leftSide"){
                lObj1 += oObj1;
                lObj2 += oObj2;
            }
            else{
                rObj1 += oObj1;
                rObj2 += oObj2;
            }

            if((lObj2>lObj1 && lObj2 != 0 && lObj1 != 0)
                    || (rObj2>rObj1 && rObj1 != 0 && rObj2 !=0)){
                return false;
            }
       }
    }
    return true;
}

void QManager::spriteToRaft(int id)
{
    int active = 0;
    for (int i = 0; i<this->sprites.size(); i++){
        if (this->sprites[i]->getState() == "onRaftLeft"
                || this->sprites[i]->getState() == "onRaftRight"){
            ++active;
        }
    }

    if(active >= this->raft->getItems()){
        QMessageBox msg;
        msg.setText(QString::fromLocal8Bit("���� ����������"));
        msg.exec();
        return;
    }

    if(this->sprites[id]->getState() == this->raft->getState()){
        if(this->raft->getState() == "leftSide"){
            this->sprites[id]->setState("onRaftLeft");
            return;
        }
        else{
            this->sprites[id]->setState("onRaftRight");
            return;
        }
        /*if ((this->raft->getState() == this->sprites[id]->getDefaultSide())){
            this->sprites[id]->setState("onRaft");
            return;
        }
        else{
            // �������� �� X
            int diffX = 0;
            diffX = max(this->sprites[id]->getPosition("onRaft").x(),
                        this->raft->getPosition(this->sprites[id]->getDefaultSide()).x())
                    - min(this->sprites[id]->getPosition("onRaft").x(),
                          this->raft->getPosition(this->sprites[id]->getDefaultSide()).x());

            // �������� �� Y
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


        }*/

    }
    else{
        QMessageBox msg;
        msg.setText(QString::fromLocal8Bit("������ � ���� ��������� �� ������ �������"));
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
