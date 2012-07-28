#include "qclass.h"

QClass::QClass()
{
    this->setEdited(false);
    this->setPainted(false);
}

void QClass::setName(QString name)
{
    this->name = name;
}

QString QClass::getName()
{
    return this->name;
}

void QClass::setCount(int count)
{
    this->count = count;
}

int QClass::getCount()
{
    return this->count;
}

void QClass::setImgs(QVector<QPixmap> imgs)
{
    this->imgs = imgs;
}

QPixmap QClass::getImg(int index)
{
    return this->imgs[index];
}

bool QClass::getPainted()
{
    return this->isPainted;
}

void QClass::setPainted(bool isPainted)
{
    this->isPainted = isPainted;
}

bool QClass::getEdited()
{
    return this->isEdited;
}

void QClass::setEdited(bool isEdited)
{
    this->isEdited = isEdited;
}
