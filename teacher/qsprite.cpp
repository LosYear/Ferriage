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
