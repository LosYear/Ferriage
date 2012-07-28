#include "qraft.h"
#include <QMessageBox>

QRaft::QRaft(QWidget *parent) :
    QLabel(parent)
{
    this->setAcceptDrops(true);
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

QPoint QRaft::getPosition(QString name)
{
    if( name == "leftSide"){
        return this->leftPosition;
    }
    else{
        return this->rightPosition;
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

QString QRaft::getState()
{
    return this->state;
}

void QRaft::setItems(int items)
{
    this->itemsOnIt = items;
}

int QRaft::getItems()
{
    return this->itemsOnIt;
}

void QRaft::setMovable(bool value)
{
    this->isMovable = value;
}

bool QRaft::getMovable()
{
    return this->isMovable;
}

QString QRaft::getDefaultSide()
{
    return this->defaultSide;
}

void QRaft::setDefaultSide(QString side)
{
    this->defaultSide = side;
}

void QRaft::dropEvent(QDropEvent *ev)
{
    if (ev->mimeData()->text().contains("!")){
        return;
    }
    ev->acceptProposedAction();

    emit this->spriteDroped(ev->mimeData()->text().toInt());
}

void QRaft::dragEnterEvent(QDragEnterEvent *ev)
{
    ev->acceptProposedAction();
}
