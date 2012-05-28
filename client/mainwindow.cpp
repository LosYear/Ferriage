#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "qsprite.h"
#include "QToolButton"
#include <QVector>
#include "qraft.h"
#include "qmanager.h"
#include <QStringListModel>

#include <QJson/Parser>

QManager* manager;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Конструктор
    ui->left->hide();
    ui->right->hide();

    ui->log_w->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActive(int n)
{
    this->active = n;
}

void MainWindow::on_left_clicked()
{
    if (manager->changeSide(0)){
        ui->left->setEnabled(false);
        ui->right->setEnabled(true);
    }
    else{
        QMessageBox msg;
        msg.setText(QString::fromLocal8Bit("Действие невозможно!"));
        msg.exec();
    }
}

void MainWindow::on_right_clicked()
{
    if (manager->changeSide(1)){
        ui->left->setEnabled(true);
        ui->right->setEnabled(false);
    }
    else{
        QMessageBox msg;
        msg.setText(QString::fromLocal8Bit("Действие невозможно!"));
        msg.exec();
    }
}

void MainWindow::on_action_triggered()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
    QDir::currentPath(),
    QFileDialog::ShowDirsOnly
    | QFileDialog::DontResolveSymlinks);


    manager  = new QManager(ui->frame);
    manager->loadObjects(dir, ui->picture);

    ui->left->show();
    ui->right->show();
    ui->log->setEnabled(true);
    ui->show_log->setEnabled(true);
    ui->show_task->setEnabled(true);
    ui->steps_count->setEnabled(true);
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox msg;
    msg.setText(QString::number(manager->getActive()));
    msg.exec();
}

void MainWindow::on_action_5_triggered()
{

}

void MainWindow::on_steps_count_triggered()
{
    QMessageBox msg;
    msg.setText(QString::fromLocal8Bit("Сделанных ходов: ")+QString::number(manager->getSteps()));
    msg.exec();
}

void MainWindow::on_toolButton_clicked()
{
    ui->log_w->hide();
}

void MainWindow::on_show_log_triggered()
{
    QStringList list = manager->getList();
    ui->log_list->setModel(new QStringListModel(list));
    ui->log_w->show();
    ui->log_w->raise();
}

void MainWindow::on_show_task_triggered()
{
    QMessageBox msg;
    msg.setText(manager->task);
    msg.exec();
}
