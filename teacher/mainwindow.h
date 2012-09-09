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

    void on_rBack_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_6_clicked();

    void on_step1_clicked();

    void on_step2_clicked();

    void on_step3_clicked();

    void on_step4_clicked();

    void on_step5_clicked();

    void on_pushButton_6_clicked();

    void on_minimeze_clicked();

    void on_saveFile_clicked();

    void on_pushButton_clicked();

    void on_maxSprites_valueChanged(int arg1);

    void on_checkBox_clicked();

    void on_defaultLeft_clicked();

    void on_defaultRight_clicked();

    void on_maxSprites_customContextMenuRequested(const QPoint &pos);

    void on_spinBox_valueChanged(int arg1);

    void on_raft_height_valueChanged(int arg1);

    void on_raft_width_valueChanged(int arg1);

    void on_radioButton_5_clicked();

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
