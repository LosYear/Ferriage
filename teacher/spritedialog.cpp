#include "spritedialog.h"
#include "ui_spritedialog.h"

SpriteDialog::SpriteDialog(int id, QManager *manager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpriteDialog)
{
    ui->setupUi(this);
    this->manager = manager;
    this->id = id;

    this->ui->height->setValue(manager->getSprite(id)->height());
    this->ui->width->setValue(manager->getSprite(id)->width());

    this->ui->isMovable->setChecked(manager->getSprite(id)->getMovable());

    if(manager->getSprite(id)->getDefaultSide() == "leftSide"){
        this->ui->side->setCurrentIndex(0);
    }
    else{
        this->ui->side->setCurrentIndex(1);
    }
}

SpriteDialog::~SpriteDialog()
{
    delete ui;
}

void SpriteDialog::on_pushButton_clicked()
{
    this->manager->getSprite(this->id)->resize(this->ui->width->value(),
                                               this->ui->height->value());
    this->manager->getSprite(this->id)->setMovable(this->ui->isMovable->checkState());

    if(this->ui->side->currentIndex() == 0){
        this->manager->getSprite(this->id)->setDefaultSide("leftSide");
    }
    else{
        this->manager->getSprite(this->id)->setDefaultSide("rightSide");
    }

    this->close();
}
