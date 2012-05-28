#ifndef INFO_H
#define INFO_H

#include <QDialog>

#include "qmanager.h"

namespace Ui {
class info;
}

class info : public QDialog
{
    Q_OBJECT
    
public:
    explicit info(QManager* manager = 0, QWidget *parent = 0);
    ~info();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::info *ui;

//    Менеджер
    QManager* manager;
};

#endif // INFO_H
