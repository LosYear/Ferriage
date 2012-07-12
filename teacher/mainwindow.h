#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmanager.h"
#include <QListWidgetItem>
#include <QScrollArea>
#include <qdisplayrule.h>
#include <qdraglabel.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//    �������� ��������
    QManager* manager;

//    ��������� ����
    QString recentPath;
    
private slots:
    void on_new_task_clicked();

    void on_bgButton_clicked();

    void on_bg_next_clicked();

    void on_cBack_clicked();

    void on_addClass_clicked();

    void on_list_itemDoubleClicked(QListWidgetItem *item);

    void on_addRule_clicked();

    void on_addRule_destroyed();

    void on_cNext_clicked();

    void on_cNext_2_clicked();

    void on_rBack_clicked();

    void on_rNext_clicked();

    void on_raftPick_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_rNext_2_clicked();

    void on_rBack_2_clicked();

private:
    Ui::MainWindow *ui;
    QWidget* wgt;
    QScrollArea* area;
    QWidget* classes;
    QScrollArea* classes_area;

    QVector <QDragLabel*> dragLabels;

    QVector <QDisplayRule*> rules;

    void initStartScreen();

    void updateList();

    void drawOnForm();
    void nextStep();
    void previousStep();
};

#endif // MAINWINDOW_H
