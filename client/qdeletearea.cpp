#include "qdeletearea.h"
QDeleteArea::QDeleteArea(QWidget *parent) :
    QLabel(parent)
{
    this->setPixmap(QPixmap(":/main/trash_empty"));
    this->resize(140, 140);
    this->setAcceptDrops(true);
}

void QDeleteArea::dropEvent(QDropEvent *ev)
{
    if (ev->mimeData()->text().contains("!")){
        this->setPixmap(QPixmap(":/main/trash_full"));

        QString _tmp = ev->mimeData()->text();
        _tmp.remove("!");
        emit returnToSide(_tmp.toInt());
    }
}

void QDeleteArea::dragLeaveEvent(QDragLeaveEvent *ev)
{
    this->setPixmap(QPixmap(":/main/trash_empty"));
}

void QDeleteArea::dragEnterEvent(QDragEnterEvent *ev)
{
    ev->acceptProposedAction();
    this->setPixmap(QPixmap(":/main/trash_full"));
}
