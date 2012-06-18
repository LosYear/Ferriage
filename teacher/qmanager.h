#ifndef QMANAGER_H
#define QMANAGER_H

#include <QObject>
#include <QLabel>
#include <QString>
#include <qclass.h>
#include <QMap>
#include <QVector>

class QManager : public QObject
{
    Q_OBJECT
public:
    explicit QManager(QObject *parent = 0, QWidget* parentWidget = 0);

    void setName (QString name);
    void setTask (QString task);
    void setBackground (QString filename);

    void addType (QString name, int count, QPixmap stdImg, QVector<QPixmap> imgs);
    void addType (QClass type);

    QString getName();

    //    ���� ��������
    QVector <QClass> types;
signals:
    
public slots:

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
};

#endif // QMANAGER_H
