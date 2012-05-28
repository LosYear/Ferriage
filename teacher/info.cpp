#include "info.h"
#include "ui_info.h"

info::info(QManager* manager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);

    this->manager = manager;
}

info::~info()
{
    delete ui;
}

void info::on_pushButton_clicked()
{
    manager->setName(ui->name->text());
    manager->setTask(ui->task->document()->toPlainText());

    this->close();
}
