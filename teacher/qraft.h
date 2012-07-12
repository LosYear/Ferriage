#ifndef QRAFT_H
#define QRAFT_H

#include <QLabel>

class QRaft : public QLabel
{
    Q_OBJECT
public:
    explicit QRaft(QWidget *parent = 0);
    void setSide(bool isLeftSide);
    bool getSide();

    void setPostion(QString name, QPoint value);
    void setPostion(QString name, int xpos, int ypos);
    
signals:
    
public slots:

private:
    bool isLeftSide; // �������, false-������, true - �����

    // ������� �����
    QPoint leftPosition;
    QPoint rightPosition;
    
};

#endif // QRAFT_H
