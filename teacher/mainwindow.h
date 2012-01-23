#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <edits.h>
#include <ldir.h>
#include <QVector>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Edits* edits;
    lDir* cDir;
    QVector < QVector< int > > rules;

    void initVector ( int n);

private slots:
    void on_selectButton_clicked();
    void on_toolButton_clicked();
    void on_spinBox_valueChanged(int );
    void on_actionReadyClicked_triggered();
   // void on_buttonUnPack_clicked();
};

#endif // MAINWINDOW_H
