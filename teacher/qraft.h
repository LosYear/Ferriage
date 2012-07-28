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

    QPoint getPositon(QString name);

    void setState(QString state);

    void setItems(int items);
    int getItems();

    void setMovable(bool value);
    bool getMovable();

    QString getDefaultSide();
    void setDefaultSide(QString side);
    
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

    int itemsOnIt;
    bool isMovable;
    QString defaultSide;
    
};

#endif // QRAFT_H
