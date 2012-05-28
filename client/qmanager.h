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

//    -- ������ --
    void loadObjects(QString dir, QLabel* image);
//    ������ ���������
    void setActive(int n);
//    �������� ���������
    int getActive();
//    ����� ������
    bool changeSide(int side);
//    ������ ������������ ���������� ��������
    void setMaxActive( int active );
//    �������� ���������� �������� ������
    int getActiveCount();
//    �������� ���������� �����
    int getSteps();
//    �������� ������ �����
    QStringList getList();
//    �������
    QString task;

public slots:
    void spriteClicked(int n);
    void raftClicked();

private:
//    -- ���������� --

//    ���������
    QSprite** objects;
//    ����� �����
    QRaft* raft;
//    ���������� ����������
    int sprites;
//    ������������ ������
    QWidget *parent;
//    �������
    QVector < QVector < int > > rules;
//    ��������
    int active;
//    ������������ ���������� ��������
    int maxActive;
//    ���������� ��������� �����
    int steps;
//    ���
    QListView log;
//    ������ �����
    QStringList list;

//    -- ������ --

    void setSprites(int spritesNumber);
    int getSprites();
    void setParent(QWidget *parent);


//    �������� ��������
    void loadImages(QString dir, QLabel *image);
//    �������� ������
    void loadRules(QString dir);
};

