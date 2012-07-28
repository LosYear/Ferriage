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

#ifndef QSPRITE_H
#define QSPRITE_H

#include <QLabel>
#include <QMouseEvent>

class QSprite : public QLabel
{
    Q_OBJECT
public:
    explicit QSprite(QWidget *parent = 0);

    // Позиция
    void setPostion(QString name, QPoint value);
    void setPostion(QString name, int xpos, int ypos);
    QPoint getPosition(QString name);


    // Состояние(берег)
    void setState(QString state);

    // Имя класса
    void setClassName(QString name);
    QString getClassName();
    
signals:
    
public slots:

private:
    QString className;
    QPoint leftSide;
    QPoint rightSide;
    QPoint onRaft;


    QString state;

    QPoint offset; // Смещение для движения объекта

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
};

#endif // QSPRITE_H
