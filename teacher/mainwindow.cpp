#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

#include "info.h"
#include "addclassdialog.h"
#include <QScrollArea>
#include <qraft.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Общая инициализация
    this->recentPath = "/";

    // Инициализация стартового экрана
    initStartScreen();

    // Поле с правилами

    wgt = new QWidget(this->ui->rules);
    wgt->setGeometry(0, 0, 750, 150);
    wgt->show();

    area = new QScrollArea(this->ui->rules);
    area->setGeometry(10, 30, 780, 160);
    area->setWidget(wgt);
    area->lower();
    area->setFrameShape(QFrame::NoFrame);
    area->show();

    // Поле с классами

    classes = new QWidget(this->ui->rules);
    classes->setGeometry(0,0, 180, 180);
    classes->show();


    classes_area = new QScrollArea(this->ui->rules);
    classes_area->setGeometry(0, 0, 210, 200);
    classes_area->setWidget(classes);
    classes_area->setFrameShape(QFrame::NoFrame);
    classes_area->show();
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

    for (int i = 0; i < this->manager->typesSize(); i++){
        this->ui->list->addItem(this->manager->getTypesItem(i)->getName());
    }
}

void MainWindow::drawOnForm()
{
    for (int i = 0; i < this->manager->typesSize(); i++){
        int count = this->manager->getTypesItem(i)->getCount();
        if (this->manager->getTypesItem(i)->getPainted()){
            if (this->manager->getTypesItem(i)->getEdited()){
                QString name = this->manager->getTypesItem(i)->getName();
                int k = 0;
                for (int j = 0; j<this->manager->spritesSize(); j++){
                    if(this->manager->getSprite(j)->getClassName() == name){
                        this->manager->getSprite(j)->setPixmap(this->manager->getTypesItem(i)->
                                                               getImg(k).scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                        k++;
                    }
                }
                this->manager->getTypesItem(i)->setEdited(false);
                this->manager->getTypesItem(i)->setPainted(false);
            }

        }
        else{
            for (int j = 0; j < count; j++){
                QSprite* sprite = new QSprite(this->ui->centralWidget);
                sprite->setClassName(this->manager->getTypesItem(i)->getName());
                sprite->setPixmap(this->manager->getTypesItem(i)->getImg(j).scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                sprite->setGeometry(j*64, i*64, 64, 64);
                sprite->show();

                sprite->setPostion("leftSide", QPoint(sprite->x(), sprite->y()));
                sprite->setPostion("rightSide", QPoint(sprite->x(), sprite->y()));
                sprite->setPostion("onRaft", QPoint(sprite->x(), sprite->y()));


                this->manager->addSprite(sprite);
            }
            this->manager->getTypesItem(i)->setPainted(true);
        }
    }
}

void MainWindow::nextStep()
{
    this->ui->wizard_widget->setCurrentIndex(this->ui->wizard_widget->currentIndex()+1);
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
    nextStep();
}

void MainWindow::on_cBack_clicked()
{
    previousStep();
}

void MainWindow::on_addClass_clicked()
{
    addClassDialog wClass(this->manager);
    wClass.exec();

    updateList();

//    Объекты в правилах
    if (this->dragLabels.size()  != 0){
        for (int i = 0; i<dragLabels.size(); i++){
            QDragLabel* _tmp = dragLabels[i];
            delete _tmp;
            dragLabels.remove(i);
        }
        dragLabels.clear();
    }

    // Рисуем

    this->classes->setGeometry(classes->x(), classes->y(), classes->width(),
                                    64);

    for (int i = 0; i < this->manager->typesSize(); i++){
        QDragLabel* _tmp = new QDragLabel(this->classes);
        dragLabels.insert(i, _tmp);
        dragLabels[i]->setGeometry(60, 70*i, 64, 64);
        dragLabels[i]->setPixmap(this->manager->getTypesItem(i)->getImg(0).scaled(64, 64, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        dragLabels[i]->show();
        dragLabels[i]->setClassName(this->manager->getTypesItem(i)->getName());

        this->classes->setGeometry(classes->x(), classes->y(), classes->width(),
                                        classes->height()+64);
    }

    // Рисуем на форме
    drawOnForm();

}

void MainWindow::on_list_itemDoubleClicked(QListWidgetItem *item)
{
    QClass arg;

//    Выбор класса
    for (QVector<QClass>::iterator it = this->manager->getTypesBeginIterator();
         it != this->manager->getTypesEndIterator(); ++it){
        if(it->getName() == item->text()){
            arg = *it;
            arg.setEdited(true);
            break;
        }
    }

   addClassDialog w(this->manager, &arg);
   w.exec();

   drawOnForm();
}

void MainWindow::on_addRule_clicked()
{
    if (this->rules.size() == 0){
        QDisplayRule* _tmp = new QDisplayRule(this->wgt);
        rules.push_back(_tmp);

        rules[0]->obj1->setGeometry(220, 10, 64, 64);
        rules[0]->obj1->setPixmap(QPixmap(":/rules/mask"));
        rules[0]->obj1->show();

        rules[0]->combobox->setGeometry(rules[0]->obj1->x()+ 70, 30, 130, 22);
        rules[0]->combobox->show();

        rules[0]->obj2->setGeometry(425, 10, 64, 64);
        rules[0]->obj2->setPixmap(QPixmap(":/rules/mask"));
        rules[0]->obj2->show();

        this->wgt->setGeometry(wgt->x(), wgt->y(), wgt->width(), 74);
    } else {
        QDisplayRule* end = rules[rules.size()-1];

        QDisplayRule* _tmp = new QDisplayRule(this->wgt);
        rules.push_back(_tmp);

        QDisplayRule* _end = rules[rules.size()-1];
        _end->obj1->setGeometry(220, end->obj1->y() + 70, 64, 64);
        _end->obj1->setPixmap(QPixmap(":/rules/mask"));
        _end->obj1->show();

        _end->combobox->setGeometry(end->combobox->x(), _end->obj1->y() + 20, 130,22 );
        _end->combobox->show();

        _end->obj2->setGeometry(425, end->obj2->y()+70, 64,64);
        _end->obj2->setPixmap(QPixmap(":/rules/mask"));
        _end->obj2->show();

        this->wgt->setGeometry(wgt->x(), wgt->y(), wgt->width(), wgt->height()+(70));
    }
}

void MainWindow::on_addRule_destroyed()
{

}

void MainWindow::on_cNext_clicked()
{
    this->ui->wizard_widget->setCurrentIndex(this->ui->wizard_widget->currentIndex()+1);
}


void MainWindow::previousStep()
{
    this->ui->wizard_widget->setCurrentIndex(this->ui->wizard_widget->currentIndex()-1);
}

void MainWindow::on_cNext_2_clicked()
{
    nextStep();
}

void MainWindow::on_rBack_clicked()
{
    previousStep();
}

void MainWindow::on_rNext_clicked()
{
    nextStep();
}

void MainWindow::on_raftPick_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("Выбор изображения"),
                                                this->recentPath, QString::fromLocal8Bit("PNG | *.png"));

    // Запоминаем путь
    QFileInfo file_info(path);
    this->recentPath = file_info.path();

    QRaft* raft = this->manager->getRaft();
    if (raft == 0){
        raft = new QRaft(this->ui->centralWidget);
    }
    raft->setPixmap(QPixmap(path).scaled(QSize(64,64), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    raft->setGeometry(300, 200, 64, 64);
    raft->show();

}

void MainWindow::on_radioButton_clicked()
{
    for (int i = 0; i < this->manager->spritesSize(); i++){
        this->manager->getSprite(i)->setState("leftSide");
    }
}

void MainWindow::on_radioButton_2_clicked()
{
    for (int i = 0; i < this->manager->spritesSize(); i++){
        this->manager->getSprite(i)->setState("onRaft");
    }
}

void MainWindow::on_radioButton_3_clicked()
{
    for (int i = 0; i < this->manager->spritesSize(); i++){
        this->manager->getSprite(i)->setState("rightSide");
    }
}

void MainWindow::on_rNext_2_clicked()
{
    nextStep();
}

void MainWindow::on_rBack_2_clicked()
{
    previousStep();
}
