#include "qraft.h"

QRaft::QRaft( const QString & text, QWidget *parent ) :
    QLabel(parent)
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
    //this->active = activeLink;
}

void QRaft::slotClicked()
{
    //setActive(-1);
}


void QRaft::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}

void QRaft::setSide(int n)
{
    this->side = n;
}

int QRaft::getSide()
{
    return this->side;
}

bool QRaft::getActive()
{
    return this->isActive;
}

void QRaft::setActive( bool active){
    this->isActive = active;
}

bool QRaft::getObserver()
{
    return this->isObserver;
}

void QRaft::setObserver( bool observer )
{
    this->isObserver = observer;
}

bool QRaft::getMovable()
{
    return this->isMovable;
}

void QRaft::setMovable(bool movable)
{
    this->isMovable = movable;
}
