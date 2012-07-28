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
    else if ( name == "onRaft"){
        this->onRaft = value;
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
    else if ( name == "onRaft"){
        return this->onRaft;
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
    else{
        this->move(this->onRaft);
    }
}

void QSprite::setClassName(QString name)
{
    this->className = name;
}

QString QSprite::getClassName()
{
    return this->className;
}

void QSprite::mousePressEvent(QMouseEvent *ev)
{
    this->offset = ev->pos();
}

void QSprite::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton)
    {
        this->move(mapToParent(ev->pos() - offset));
        this->setPostion(this->state, mapToParent(ev->pos() - offset));
    }
}
