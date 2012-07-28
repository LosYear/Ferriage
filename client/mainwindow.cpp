#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(617, 410);

    /* Устанавливаем логотип и прячем меню*/
    this->ui->logo->setPixmap(QPixmap(":/start_screen/logo"));
    this->ui->logo->adjustSize();

    this->ui->menuBar->hide();

    // Создаем менеджер
    manager = new QManager(this->ui->centralWidget, this->ui->centralWidget);
    left = 0;
    right = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_open_task_clicked()
{
    this->manager->loadFromFile("D:/Coding/QT/teacher_new/teacher-build/dir");

    this->setWindowTitle(this->manager->getName() + " - Ferriage");
    this->resize(800, 600);
    this->ui->start_screen->hide();

    // Кнопочки

    if (left == 0){
        left = new QPushButton(this->ui->centralWidget);

        left->setGeometry(10, 530, 64, 64);
        left->setIcon(QIcon(":/main/left"));
        left->setIconSize(QSize(48,48));
        left->setFlat(true);
        left->show();
        left->raise();

        connect(left, SIGNAL(clicked()), this, SLOT(left_clicked()));
    }

    if (right == 0){
        right = new QPushButton(this->ui->centralWidget);

        right->setGeometry(726, 530, 64, 64);
        right->setIcon(QIcon(":/main/right"));
        right->setIconSize(QSize(48,48));
        right->setFlat(true);
        right->show();
        right->raise();

        connect(right, SIGNAL(clicked()), this, SLOT(right_clicked()));
    }
}

void MainWindow::left_clicked()
{
    this->manager->toLeftSide();
}


void MainWindow::right_clicked()
{
    this->manager->toRightSide();
}
