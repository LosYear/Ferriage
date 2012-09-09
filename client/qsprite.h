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
    QString getState();

    // Имя класса
    void setClassName(QString name);
    QString getClassName();

    // Стандратное положение
    QString getDefaultSide();
    void setDefaultSide(QString defaultSide);

    // ID - спрайта
    void setId(int id);
    int getId();
    
    void setMovable(bool val);
    bool getMovable();
signals:
    void deleteDrop(int id);
    void drop();

public slots:

private:
    QString className;
    QPoint leftSide;
    QPoint rightSide;
    QPoint rLeft;
    QPoint rRight;


    QString state;
    QString defaultSide;

    QPoint offset; // Смещение для движения объекта
    int id;

    bool isMovable;

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // QSPRITE_H
