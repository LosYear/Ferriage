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

    void rulesClear();

signals:
    
public slots:

private:
    QWidget* pWidget;

//    Название переправы
    QString name;

//    Условия переправы
    QString task;

//    Имя файла фона
    QString fBackground;

//    Фоновая картинка
    QLabel* bg;   

//    Правила
    QVector <QRule*> rules;

//    Спрайты
    QVector <QSprite*> sprites;

//    Виды объектов
    QVector <QClass> types;

//    Перевозчик
    QRaft* raft;
};

#endif // QMANAGER_H
