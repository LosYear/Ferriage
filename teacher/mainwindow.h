#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmanager.h"
#include <QListWidgetItem>
#include <QScrollArea>

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

//    Последний путь
    QString recentPath;
    
private slots:
    void on_new_task_clicked();

    void on_bgButton_clicked();

    void on_bg_next_clicked();

    void on_cBack_clicked();

    void on_addClass_clicked();

    void on_list_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QWidget* wgt;
    QScrollArea* area;

    void initStartScreen();

    void updateList();
};

#endif // MAINWINDOW_H
