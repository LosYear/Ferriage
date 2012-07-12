#ifndef QDRAGLABEL_H
#define QDRAGLABEL_H

#include <QLabel>

class QDragLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QDragLabel(QWidget *parent = 0);

    void setClassName(QString name);
    QString getClassName();
protected:
    void mousePressEvent(QMouseEvent *event);
    
signals:
    
public slots:

private:
    QString class_name;
    
};

#endif // QDRAGLABEL_H
