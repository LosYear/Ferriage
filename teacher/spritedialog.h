#ifndef SPRITEDIALOG_H
#define SPRITEDIALOG_H

#include <QDialog>
#include "qmanager.h"

namespace Ui {
class SpriteDialog;
}

class SpriteDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SpriteDialog( int id, QManager* manager = 0, QWidget *parent = 0);
    ~SpriteDialog();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::SpriteDialog *ui;
    QManager* manager;
    int id;
};

#endif // SPRITEDIALOG_H
