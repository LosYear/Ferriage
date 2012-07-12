#include "qraft.h"

QRaft::QRaft(QWidget *parent) :
    QLabel(parent)
{
}

void QRaft::setSide(bool isLeftSide)
{
    this->isLeftSide = isLeftSide;
}

bool QRaft::getSide()
{
    return this->isLeftSide;
}

void QRaft::setPostion(QString name, QPoint value)
{
    if (name == "left"){
        leftPosition = value;
    }
    else{
        rightPosition = value;
    }
}

void QRaft::setPostion(QString name, int xpos, int ypos)
{
    QPoint value(xpos, ypos);
    if (name == "left"){
        leftPosition = value;
    }
    else{
        rightPosition = value;
    }
}
