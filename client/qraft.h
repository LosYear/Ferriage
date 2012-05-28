#ifndef QRAFT_H
#define QRAFT_H

#include <QLabel>

class QRaft : public QLabel
{
    Q_OBJECT
public:
    explicit QRaft( const QString & text, QWidget *parent = 0);
    void setSide(int n);
    int getSide();

    bool getActive();
    void setActive(bool active);

    bool getObserver();
    void setObserver(bool observer);

    bool getMovable();
    void setMovable(bool movable);
    
signals:
    void clicked();
    
public slots:
    void slotClicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;

private:
    int number;
    QObject mnWindow;
    int side; // Left - 0, Right - 1
    void setActive( int n );
    bool isActive;

//    Может ли плот ездить сам
    bool isMovable;
//    Являеться ли плот наблюдателем
    bool isObserver;
    
};

#endif // QMAN_H
