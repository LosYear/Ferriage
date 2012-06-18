#ifndef ADDCLASSDIALOG_H
#define ADDCLASSDIALOG_H

#include <QDialog>
#include "qmanager.h"
#include "qcommandlinkbuttonextended.h"
#include <QVector>

namespace Ui {
class addClassDialog;
}

class addClassDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit addClassDialog(QManager* manager = 0, QClass *arg = 0,QWidget *parent = 0);
    ~addClassDialog();
    
private slots:
    void on_children_valueChanged(int val);
    void imageClicked(int id);

    void on_stdImg_clicked();

    void on_ok_clicked();

private:
    Ui::addClassDialog *ui;

    QManager* manager;

    QVector <QCommandLinkButtonExtended*> images;

    QString recentPath; // Последний путь

    QPixmap stdPix;

    //QCommandLinkButtonExtended* stdImg;
};

#endif // ADDCLASSDIALOG_H
