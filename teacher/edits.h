#ifndef EDITS_H
#define EDITS_H
#include <QLineEdit>

class Edits
{
private:
    int amount;
    QLineEdit** edits;

public:
    Edits(int amt);
    ~Edits();
    void ShowEdits(QWidget* layer, int x, int y, int width, int height, int step);
    void NewAmount(int amt);
    void HideEdits();
    void setText(int n, QString str);
    QString getText(int n);
    int getAmount();
};

#endif // EDITS_H
