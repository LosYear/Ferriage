#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>

#include "info.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->menuBar->hide();

    // Инициализация стартового экрана
    initStartScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initStartScreen()
{
    QPixmap* logo = new QPixmap(":/start_screen/logo.png");

    this->ui->logo->setPixmap(*logo);
    this->ui->logo->adjustSize();
}

void MainWindow::on_new_task_clicked()
{
    this->ui->start_screen->hide();
    this->ui->menuBar->show();

    //    Создаем менеджер
    this->manager = new QManager(this->ui->centralWidget);

    info wInfo(manager);
    wInfo.exec();

    //    Включаем пункты меню
}
