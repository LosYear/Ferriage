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
#include "QMessageBox"

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
        this->onRaftLeft = value;
    }
    else{
        this->onRaftRight = value;
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
        return this->onRaftLeft;
    }
    else{
        return this->onRaftRight;
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
    else if( state == "onRaftLeft"){
        this->move(this->onRaftLeft);
    }
    else{
        this->move(this->onRaftRight);
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

int QSprite::getId()
{
    return this->id;
}

void QSprite::setId(int id)
{
    this->id = id;
}

void QSprite::setMovable(bool val)
{
    this->isMovable = val;
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

void QSprite::mouseDoubleClickEvent(QMouseEvent *ev)
{
    emit doubleClicked(this->id);
}


bool QSprite::getMovable()
{
    return this->isMovable;
}

void QSprite::setDefaultSide(QString value)
{
    this->defaultSide = value;
}

QString QSprite::getDefaultSide()
{
    return this->defaultSide;
}
