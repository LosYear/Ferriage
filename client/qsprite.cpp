// ############################
// ##                        ##
// ##                        ##
// ##      THIS FILE WILL    ##
// ##           BE           ##
// ##       INCLUDED TO      ##
// ##       CLIENT VERSION   ##
// ##                        ##
// ##                        ##
// ##                        ##
// ##                        ##
// ############################

#include "qsprite.h"
#include <QMessageBox>
QSprite::QSprite(QWidget *parent) :
    QLabel(parent)
{
}

void QSprite::setPostion(QString name, QPoint value)
{
    if ( name == "leftSide" ){
        this->leftSide = value;
    } else if ( name == "rightSide"){
        this->rightSide = value;
    }
    else if ( name == "onRaftLeft"){
        this->rLeft = value;
    }
    else{
        this->rRight = value;
    }
}

void QSprite::setPostion(QString name, int xpos, int ypos)
{
    setPostion(name, QPoint(xpos, ypos));
}

QPoint QSprite::getPosition(QString name)
{
    if ( name == "leftSide" ){
        return this->leftSide;
    } else if ( name == "rightSide"){
        return this->rightSide;
    }
    else if ( name == "onRaftLeft"){
        return this->rLeft;
    }
    else{
        return this->rRight;
    }
}

void QSprite::setState(QString state)
{
    this->state = state;
    if(state == "leftSide"){
        this->move(this->leftSide);
    } else if (state == "rightSide"){
        this->move(this->rightSide);
    }
    else if(state == "onRaftLeft"){
        this->move(this->rLeft);
    }
    else{
        this->move(this->rRight);
    }
}

QString QSprite::getState()
{
    return this->state;
}

void QSprite::setClassName(QString name)
{
    this->className = name;
}

QString QSprite::getClassName()
{
    return this->className;
}

QString QSprite::getDefaultSide()
{
    return this->defaultSide;
}

void QSprite::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton){
        QDrag* drag = new QDrag(this);
        QMimeData* mime = new QMimeData;

        if (this->state == "onRaftLeft" || this->state == "onRaftRight" ){
            mime->setText("!"+QString::number(this->id));
            emit deleteDrop(this->id);
        }
        else{
            mime->setText(QString::number(this->id));
        }
        drag->setMimeData(mime);
        drag->setPixmap(*this->pixmap());


        Qt::DropAction dropAction = drag->exec();
    }
}

void QSprite::mouseMoveEvent(QMouseEvent *ev)
{

}

void QSprite::mouseReleaseEvent(QMouseEvent *ev)
{
    QMessageBox msg;msg.setText("123");


    msg.exec();
}


void QSprite::setDefaultSide(QString defaultSide)
{
    this->defaultSide = defaultSide;
}

void QSprite::setId(int id)
{
    this->id = id;
}

int QSprite::getId()
{
    return this->id;
}

void QSprite::setMovable(bool val)
{
    this->isMovable = val;
}


bool QSprite::getMovable()
{
    return this->isMovable;
}
