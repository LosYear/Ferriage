#ifndef QRAFT_H
#define QRAFT_H

#include <QLabel>
#include <QMouseEvent>

class QRaft : public QLabel
{
    Q_OBJECT
public:
    explicit QRaft(QWidget *parent = 0);

    void setPostion(QString name, QPoint value);
    void setPostion(QString name, int xpos, int ypos);

    void setState(QString state);
    
signals:
    
public slots:
protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

private:
    QString state;

    // Позиция плота
    QPoint leftPosition;
    QPoint rightPosition;

    QPoint offset;
    
};

#endif // QRAFT_H
