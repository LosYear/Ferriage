#include "qdraglabel.h"
#include <QMessageBox>
#include <QMouseEvent>

QDragLabel::QDragLabel(QWidget *parent) :
    QLabel(parent)
{
}

void QDragLabel::setClassName(QString name)
{
    this->class_name = name;
}

QString QDragLabel::getClassName()
{
    return this->class_name;
}

void QDragLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        QDrag* drag = new QDrag(this);
        QMimeData* mime = new QMimeData;

        mime->setText(this->class_name);
        mime->setImageData(this->pixmap()->toImage());
        drag->setMimeData(mime);
        drag->setPixmap(*this->pixmap());

        Qt::DropAction dropAction = drag->exec();
    }
}
