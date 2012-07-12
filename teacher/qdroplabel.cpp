#include "qdroplabel.h"
#include <QDragEnterEvent>
#include <QMessageBox>

QDropLabel::QDropLabel(QWidget *parent) :
    QLabel(parent)
{
    this->setAcceptDrops(true);
}

void QDropLabel::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void QDropLabel::setClassName(QString name)
{
    this->class_name = name;
}

QString QDropLabel::getClassName()
{
    return this->class_name;
}

void QDropLabel::dropEvent(QDropEvent *event)
{
    this->class_name = event->mimeData()->text();

    QMessageBox msg;
    msg.setText(class_name);
    msg.exec();

    QPixmap pix = qvariant_cast<QPixmap>(event->mimeData()->imageData());

    this->setPixmap(pix);

    event->acceptProposedAction();
}
