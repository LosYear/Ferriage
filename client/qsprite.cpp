#include "qsprite.h"

QSprite::QSprite( const QString & text, QWidget *parent) :
    QLabel(parent)
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
}

void QSprite::slotClicked()
{
    setActive(this->getNumber());

}


void QSprite::mousePressEvent ( QMouseEvent * event )
{
    emit clicked(this->getNumber());
}

void QSprite::setNumber(int n)
{
    this->number = n;
}

int QSprite::getNumber()
{
    return this->number;
}


// Çàäàåì àêòèâíûì îáúåêò

void QSprite::setActive(bool active){
    this->isActive = active;
}

// Ïğîâåğÿåì àêòèâåí ëè îáúåêò

bool QSprite::getActive(){
    return this->isActive;
}

// Îïåğàöèè ñ áåğåãîì
void QSprite::setSide(int side)
{
    this->side = side;
}

int QSprite::getSide()
{
    return this->side;
}

void QSprite::setOldX(int x)
{
    this->x_old = x;
}

int QSprite::getOldX()
{
    return this->x_old;
}

void QSprite::setOldY(int y)
{
    this->y_old = y;
}

int QSprite::getOldY()
{
    return this->y_old;
}
