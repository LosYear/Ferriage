#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//    Менеджер спрайтов
    QManager* manager;
    
private slots:
    void on_new_task_clicked();

private:
    Ui::MainWindow *ui;

    void initStartScreen();
};

#endif // MAINWINDOW_H
