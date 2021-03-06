#ifndef QMANAGER_H
#define QMANAGER_H

#include <QObject>
#include <QLabel>
#include <QString>
#include <qclass.h>
#include <QVector>
#include <qrule.h>
#include <qsprite.h>
#include <qraft.h>
#include <qdeletearea.h>

class QManager : public QObject
{
    Q_OBJECT
public:
    explicit QManager(QObject *parent = 0, QWidget* parentWidget = 0);

    void setName (QString name);
    void setTask (QString task);

    void setBackground (QString filename);
    QLabel* getBackground();

    void addType (QString name, int count, QPixmap stdImg, QVector<QPixmap> imgs);
    void addType (QClass type);

    QString getName();
    QString getTask();

    void addRule(QString object1, QString object2, QString rule);
    void addRule(QString object1, QString object2, QString rule, QString adv_rule, QString adv_obj);

    int typesSize();
    int spritesSize();
    QClass* getTypesItem(int id);
    QVector<QClass>::iterator getTypesBeginIterator();
    QVector<QClass>::iterator getTypesEndIterator();

    void addSprite(QSprite* sprite);
    QSprite* getSprite(int id);

    QRaft* getRaft();
    void setRaft(QRaft* raft);

    void saveToFile(QString path);
    void loadFromFile(QString path);

    void rulesClear();
    void toLeftSide();
    void toRightSide();

    // ������� �������� � ��������
    void move(QString side);
    bool checkForbid(QRule r, bool isMovable, QString side);
    bool checkAdvancedForbid(QRule r, bool isMovable, QString side);
    int countObjectsWithState(QString state);
    int countObjects(QString state, QString className);
    bool checkMoreOrEqually(QRule r, bool isMovable, QString side);

signals:
    
public slots:
    void spriteToRaft(int id);
    void deleteAreaShow();
    void returnToSide(int id);

private:
    QWidget* pWidget;

//    �������� ���������
    QString name;

//    ������� ���������
    QString task;

//    ��� ����� ����
    QString fBackground;

//    ������� ��������
    QLabel* bg;   

//    �������
    QVector <QRule*> rules;

//    �������
    QVector <QSprite*> sprites;

//    ���� ��������
    QVector <QClass> types;

//    ����������
    QRaft* raft;

    QDeleteArea* delArea;
};

#endif // QMANAGER_H
