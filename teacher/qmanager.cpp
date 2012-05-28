#include "qmanager.h"

QManager::QManager(QObject *parent) :
    QObject(parent)
{
}

void QManager::setName(QString name)
{
    this->name = name;
}

void QManager::setTask(QString task)
{
    this->task = task;
}
