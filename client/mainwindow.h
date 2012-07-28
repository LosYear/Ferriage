#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmanager.h"
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
protected:
    void changeEvent(QEvent *e);
    
private slots:
    void on_open_task_clicked();
    void left_clicked();
    void right_clicked();

private:
    Ui::MainWindow *ui;

    QManager* manager;
    QPushButton* left;
    QPushButton* right;
};

#endif // MAINWINDOW_H
