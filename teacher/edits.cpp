#include "edits.h"

Edits::Edits(int amt)
{
    if((amt < 11)&&(amt > 0))
    {
        amount = amt;
        edits = new QLineEdit*[amount];
        for(int i = 0; i < amount; i++)
            edits[i] = new QLineEdit;
    }
}

Edits::~Edits()
{
    for(int i = 0; i < amount; i++)
        delete edits[i];
    delete[] edits;
}

void Edits::ShowEdits(QWidget* layer, int x, int y, int width, int height, int step)
{
    int position = 0;
    for(int i = 0; i < amount; i++)
    {
        edits[i]->setParent(layer);
        edits[i]->setGeometry(x, y + position, width, height);
        edits[i]->show();
        position += step;
    }
}

void Edits::NewAmount(int amt)
{
    for(int i = 0; i < amount; i++)
        delete edits[i];
    delete[] edits;

    if((amt < 11)&&(amt > 0))
    {
        amount = amt;
        edits = new QLineEdit*[amount];
        for(int i = 0; i < amount; i++)
            edits[i] = new QLineEdit;
    }
}

void Edits::HideEdits()
{
    for(int i = 0; i < amount; i++)
        edits[i]->hide();
}

void Edits::setText(int n, QString str)
{
    if((n > -1)&&(n < amount))
    {
        edits[n]->setText(str);
    }
}

int Edits::getAmount(){
    return this->amount;
}

QString Edits::getText(int n){
    return edits[n]->text();
}
