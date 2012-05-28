#include "QObject"
#include "qsprite.h"
#include "qraft.h"
#include <vector>
#include <QListView>

class QManager : public QObject
{
    Q_OBJECT
public:
    QManager(QWidget *parent);

//    -- Методы --
    void loadObjects(QString dir, QLabel* image);
//    Задаем активного
    void setActive(int n);
//    Получаем активного
    int getActive();
//    Смена берега
    bool changeSide(int side);
//    Задаем максимальное количество активных
    void setMaxActive( int active );
//    Получаем количество активных сейчас
    int getActiveCount();
//    Получаем количество ходов
    int getSteps();
//    Получить список ходов
    QStringList getList();
//    Условие
    QString task;

public slots:
    void spriteClicked(int n);
    void raftClicked();

private:
//    -- Переменные --

//    Персонажи
    QSprite** objects;
//    Объет плота
    QRaft* raft;
//    Количество персонажей
    int sprites;
//    Родительский виджет
    QWidget *parent;
//    Правила
    QVector < QVector < int > > rules;
//    Активный
    int active;
//    Максимальное количество активных
    int maxActive;
//    Количество сделанных ходов
    int steps;
//    Лог
    QListView log;
//    Список ходов
    QStringList list;

//    -- Методы --

    void setSprites(int spritesNumber);
    int getSprites();
    void setParent(QWidget *parent);


//    Загрузка объектов
    void loadImages(QString dir, QLabel *image);
//    Загрузка правил
    void loadRules(QString dir);
};

