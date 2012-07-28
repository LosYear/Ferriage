#ifndef QDELETEAREA_H
#define QDELETEAREA_H

#include <QLabel>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>

class QDeleteArea : public QLabel
{
    Q_OBJECT
public:
    explicit QDeleteArea(QWidget *parent = 0);

protected:
    void dropEvent(QDropEvent *ev);
    void dragLeaveEvent(QDragLeaveEvent *ev);
    void dragEnterEvent(QDragEnterEvent *ev);
    
signals:
    void returnToSide(int id);
public slots:
    
};

#endif // QDELETEAREA_H
