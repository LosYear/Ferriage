#include "qcommandlinkbuttonextended.h"

QCommandLinkButtonExtended::QCommandLinkButtonExtended(QWidget *parent) :
    QCommandLinkButton(parent)
{
}

void QCommandLinkButtonExtended::setStdIcon(bool value)
{
    this->stdIcon = value;
}

bool QCommandLinkButtonExtended::getStdIcon()
{
    return this->stdIcon;
}

void QCommandLinkButtonExtended::setImage(QString image)
{
    this->image = image;
}

QString QCommandLinkButtonExtended::getImage()
{
    return this->image;
}

void QCommandLinkButtonExtended::setOrigPixmap(QPixmap pix)
{
    this->origPixmap = pix;
}

QPixmap QCommandLinkButtonExtended::getOrigPixmap()
{
    return this->origPixmap;
}


void QCommandLinkButtonExtended::setId(int id)
{
    this->id = id;
}


int QCommandLinkButtonExtended::getId()
{
    return this->id;
}

void QCommandLinkButtonExtended::mousePressEvent ( QMouseEvent * event )
{
    emit clicked(this->getId());
}
