#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractAnimation>
#include <QPropertyAnimation>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setActive(int n);

private slots:
    void on_left_clicked();
    void on_right_clicked();
    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_5_triggered();

    void on_steps_count_triggered();

    void on_toolButton_clicked();

    void on_show_log_triggered();

    void on_show_task_triggered();

private:
    Ui::MainWindow *ui;
    int active;
};

#endif // MAINWINDOW_H
