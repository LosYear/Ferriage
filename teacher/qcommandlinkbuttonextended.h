#ifndef QCOMMANDLINKBUTTONEXTENDED_H
#define QCOMMANDLINKBUTTONEXTENDED_H

#include <QCommandLinkButton>

class QCommandLinkButtonExtended : public QCommandLinkButton
{
    Q_OBJECT
public:
    explicit QCommandLinkButtonExtended(QWidget *parent = 0);
    void setStdIcon(bool value);
    bool getStdIcon();

    void setImage(QString image); // DEPRECATED
    QString getImage(); // DEPRECATED

    void setOrigPixmap(QPixmap pix);
    QPixmap getOrigPixmap();
signals:
    void clicked(int);
    
public slots:

private:
    int id; // ID спрайта
    bool stdIcon; // Стандартна ли иконка?
    QString image; // @DEPRECATED
    QPixmap origPixmap;

public:
    int getId();
    void setId(int id);

protected:
    void mousePressEvent ( QMouseEvent * event );
};

#endif // QCOMMANDLINKBUTTONEXTENDED_H
