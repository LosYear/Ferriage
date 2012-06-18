#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

#include "info.h"
#include "addclassdialog.h"
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Общая инициализация
    this->recentPath = "/";

    // Инициализация стартового экрана
    initStartScreen();
//    this->setGeometry(this->x(), this->y(),
//                      630, 400);
    wgt = new QWidget(this->ui->rules);
    wgt->setGeometry(0, 0, 770, 150);
    wgt->show();

    area = new QScrollArea(this->ui->rules);
    area->setGeometry(10, 30, 780, 160);
    area->setWidget(wgt);
    area->lower();
    area->setFrameShape(QFrame::NoFrame);
    area->show();
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

    this->ui->wizard_widget->hide();
}

void MainWindow::updateList()
{
    this->ui->list->clear();

    for (int i = 0; i < this->manager->types.size(); i++){
        this->ui->list->addItem(this->manager->types[i].getName());
    }
}

void MainWindow::on_new_task_clicked()
{
    this->ui->start_screen->hide();

    //    Создаем менеджер
    this->manager = new QManager(this->ui->centralWidget, this->ui->centralWidget);

    info wInfo(manager);
    wInfo.exec();

    //    Изменяем интерфейс
    this->setWindowTitle(this->manager->getName() + " - Ferriage");
    this->setGeometry(this->x(), this->y(),
                      800, 600);

    this->ui->wizard_widget->setGeometry(0,400, 800, 200);

    this->ui->wizard_widget->show();

}

void MainWindow::on_bgButton_clicked()
{
    QFileDialog* dialog = new QFileDialog();
    QString filename = dialog->getOpenFileName(this, QString::fromLocal8Bit("Выберете фон"),
                            this->recentPath, QString::fromLocal8Bit("Графика | *.jpg; *.jpeg; *.png; *.bmp"));

    // Загружаем
    this->ui->background_edit->setText(filename);

    QFileInfo file_info(filename);
    this->recentPath = file_info.path();

    // Отрисовка фон
    this->manager->setBackground(filename);
}

void MainWindow::on_bg_next_clicked()
{
    this->ui->wizard_widget->setCurrentIndex(this->ui->wizard_widget->currentIndex()+1);
}

void MainWindow::on_cBack_clicked()
{
    this->ui->wizard_widget->setCurrentIndex(this->ui->wizard_widget->currentIndex() - 1);
}

void MainWindow::on_addClass_clicked()
{
    addClassDialog wClass(this->manager);
    wClass.exec();

    updateList();
}

void MainWindow::on_list_itemDoubleClicked(QListWidgetItem *item)
{
    QClass arg;

//    Выбор класса
    for (QVector<QClass>::iterator it = this->manager->types.begin();
         it != this->manager->types.end(); ++it){
        if(it->getName() == item->text()){
            arg = *it;
            break;
        }
    }

   addClassDialog w(this->manager, &arg);
   w.exec();
}
