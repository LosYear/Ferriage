#ifndef QMANAGER_H
#define QMANAGER_H

#include <QObject>

class QManager : public QObject
{
    Q_OBJECT
public:
    explicit QManager(QObject *parent = 0);

    void setName (QString name);
    void setTask (QString task);
    
signals:
    
public slots:

private:
//    �������� ���������
    QString name;

//    ������� ���������
    QString task;
};

#endif // QMANAGER_H
