#ifndef QSPRITE_H
#define QSPRITE_H

#include <QLabel>

class QSprite : public QLabel
{
    Q_OBJECT
public:
    explicit QSprite( const QString & text, QWidget *parent = 0);
    void setNumber(int n);
    int getNumber();

//    -- Методы --
    void setActive(bool active);
    bool getActive();

    void setSide(int side);
    int getSide();

    void setOldX(int x);
    int getOldX();
    void setOldY(int y);
    int getOldY();


    
signals:
    void clicked(int);
    
public slots:
    void slotClicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;

private:
    int number;
    
//    -- Переменные --
    bool isActive;
//    Берег
    int side;

//    Старые координаты
    int x_old;
    int y_old;

};

#endif // QLABELEXTENDED_H
