#ifndef QDISPLAYRULE_H
#define QDISPLAYRULE_H

#include <QObject>
#include <qdroplabel.h>
#include <QComboBox>


class QDisplayRule : public QObject
{
    Q_OBJECT
public:
    explicit QDisplayRule(QWidget *parent = 0);

    QDropLabel* obj1;
    QDropLabel* obj2;
    QComboBox* combobox;

    QComboBox* adv;
    QDropLabel* drop_adv;
    
signals:
    
public slots:
    void comboboxValueChanged(int id);

private:

    
};

#endif // QDISPLAYRULE_H
