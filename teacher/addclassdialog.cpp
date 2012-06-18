#include "addclassdialog.h"
#include "ui_addclassdialog.h"
#include "QMessageBox"
#include <QFileDialog>
#include "qclass.h"

addClassDialog::addClassDialog(QManager *manager, QClass *arg, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addClassDialog)
{
    ui->setupUi(this);
    ui->children->setValue(1);

    this->manager = manager;

    this->recentPath = "/";

    if (arg != 0){
        // Имя
        this->ui->className->setText(arg->getName());
        this->ui->className->setDisabled(true);
        // Количество
        this->ui->children->setValue(arg->getCount());
        // Стандартная картинка
        this->ui->stdImg->setIcon(QIcon(arg->getImg(0)));
        this->ui->stdImg->setIconSize(QSize(50,50));
        this->stdPix = arg->getImg(0);

        for ( int i = 0; i < this->images.size(); i++){
            this->images[i]->setIcon(QIcon(arg->getImg(i+1)));
            this->images[i]->setIconSize(QSize(50,50));
            this->images[i]->setOrigPixmap(arg->getImg(i+1));
            if (arg->getImg(0).toImage() != arg->getImg(i+1).toImage()){
                this->images[i]->setStdIcon(false);
            }
        }
    }

}

addClassDialog::~addClassDialog()
{
    delete ui;
}

void addClassDialog::on_children_valueChanged(int val)
{
    if(val == 1){
        ui->lAdv->show();

        QCommandLinkButtonExtended* _tmp = this->images[0];
        this->images.remove(0);

        delete _tmp;
    }
    else{
        ui->lAdv->hide();
//        Удаляем лишние элементы
        if (val-1 < this->images.size()){
            for ( int i = this->images.size()-1; i>=val-1; i--){
                QCommandLinkButtonExtended* _tmp = this->images[i];
                this->images.remove(i);

                delete _tmp;
            }
        }
        else{
            // Создаем новые элементы
            for( int i = 0; i<val-1; i++){
                if ( i >= this->images.size()){
                    QCommandLinkButtonExtended* tmp = new QCommandLinkButtonExtended(this->ui->groupBox);
                    tmp->setGeometry(80*i+10, 15 , 64, 70);
                    tmp->setId(i);

                    QIcon icon = this->ui->stdImg->icon();
                    tmp->setIcon(icon);
                    QSize _size(50,50);
                    tmp->setIconSize(_size);

                    tmp->show();

                    tmp->setStdIcon(true);

                    connect(tmp, SIGNAL(clicked(int)), this, SLOT(imageClicked(int)));

                    this->images.insert(i, tmp);
                }
            }
        }
    }
}

void addClassDialog::imageClicked(int id)
{
    QString path = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("Выбор изображения"),
                                                this->recentPath,QString::fromLocal8Bit("PNG | *.png"));
    QIcon icon(path);
    QSize _size(50, 50);

    this->images[id]->setIconSize(_size);
    this->images[id]->setIcon(icon);
    this->images[id]->setOrigPixmap(QPixmap(path));
    this->images[id]->setStdIcon(false);
}

void addClassDialog::on_stdImg_clicked()
{
    QFileDialog dialog;

    QString path = dialog.getOpenFileName(this, QString::fromLocal8Bit("Выбор изображения"),
                                          this->recentPath, QString::fromLocal8Bit("PNG | *.png"));

    // Меняем изображения всем, кто использует маску

    QIcon icon(path);

    for(int i = 0; i < this->images.size(); i++){
        if (this->images[i]->getStdIcon()){
            this->images[i]->setIcon(icon);
        }
    }

    this->ui->stdImg->setIcon(icon);
    this->stdPix = QPixmap(path);

    // Запоминаем путь
    QFileInfo file_info(path);
    this->recentPath = file_info.path();
}

void addClassDialog::on_ok_clicked()
{
    // Проверки
    if( this->ui->className->text() == NULL){
        QMessageBox msg;
        msg.setText(QString::fromLocal8Bit("Введите 'Имя вида'"));
        msg.exec();
    }

    // Переносим данные
    QClass _tmp;
    _tmp.setName(this->ui->className->text());
    _tmp.setCount(this->ui->children->value());

    QVector <QPixmap> imgs;
    imgs.clear();

    //imgs.insert(0, this->stdPix);

    for ( int i = 0; i < this->images.size(); i++){
        if (!this->images[i]->getStdIcon()){
            imgs.insert(i, this->images[i]->getOrigPixmap());
        }
        else{
            imgs.insert(i, this->stdPix);
        }
    }

    this->manager->addType(_tmp.getName(), _tmp.getCount(), this->stdPix,
                           imgs);
    this->close();
}
