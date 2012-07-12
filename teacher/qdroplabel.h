#ifndef QDROPLABEL_H
#define QDROPLABEL_H

#include <QLabel>

class QDropLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QDropLabel(QWidget *parent = 0);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent* event);

    void setClassName(QString name);
    QString getClassName();
    
signals:
    
public slots:

protected:

private:
    QString class_name;

    
};

#endif // QDROPLABEL_H
