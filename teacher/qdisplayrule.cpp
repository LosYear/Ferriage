#include "qdisplayrule.h"
#include "QMessageBox"

QDisplayRule::QDisplayRule(QWidget *parent) :
    QObject(parent)
{
    this->combobox = new QComboBox(parent);

    this->combobox->addItem(QString::fromLocal8Bit("Запрет"), QVariant()); // 0
    this->combobox->addItem(QString::fromLocal8Bit("Расширенный запрет"), QVariant()); // 1
    this->combobox->addItem(QString::fromLocal8Bit(">"), QVariant()); // 2
    this->combobox->addItem(QString::fromLocal8Bit(">="), QVariant()); // 3
    this->combobox->addItem(QString::fromLocal8Bit("="), QVariant()); // 4

    connect(this->combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboboxValueChanged(int)));

    this->obj1 = new QDropLabel(parent);
    this->obj2 = new QDropLabel(parent);

    this->adv = NULL;
    this->drop_adv = NULL;
}

void QDisplayRule::comboboxValueChanged(int id){

    if ( id ==  1){
        adv = new QComboBox(qobject_cast<QWidget*>(parent()));
        adv->addItem(QString::fromLocal8Bit("Должен присутствовать"), QVariant());

        drop_adv = new QDropLabel(qobject_cast<QWidget*>(parent()));
        drop_adv->setGeometry(obj2->x()+225, obj2->y(), obj2->width(), obj2->height());
        drop_adv->setPixmap(QPixmap(":/rules/mask"));
        drop_adv->show();

        adv->setGeometry(combobox->x()+205, combobox->y(), combobox->width()+20, combobox->height() );
        adv->show();
    } else if (adv != NULL || drop_adv != NULL){
        delete adv;
        delete drop_adv;

        adv = NULL;
        drop_adv = NULL;
    }
}
