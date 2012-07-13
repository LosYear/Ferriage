#include "qraft.h"

QRaft::QRaft(QWidget *parent) :
    QLabel(parent)
{
}


void QRaft::setPostion(QString name, QPoint value)
{
    if (name == "leftSide"){
        leftPosition = value;
    }
    else{
        rightPosition = value;
    }
}

void QRaft::setPostion(QString name, int xpos, int ypos)
{
    QPoint value(xpos, ypos);
    if (name == "leftSide"){
        leftPosition = value;
    }
    else{
        rightPosition = value;
    }
}

void QRaft::setState(QString state)
{
    this->state = state;
    if (state == "leftSide"){
        this->move(this->leftPosition);
    }
    else{
        this->move(this->rightPosition);
    }
}

void QRaft::mousePressEvent(QMouseEvent *ev)
{
    this->offset = ev->pos();
}

void QRaft::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton)
    {
        this->move(mapToParent(ev->pos() - offset));
        this->setPostion(this->state, mapToParent(ev->pos() - offset));
    }
}
