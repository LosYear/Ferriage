/********************************************************************************
** Form generated from reading UI file 'spritedialog.ui'
**
** Created: Sat 11. Aug 18:24:17 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITEDIALOG_H
#define UI_SPRITEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpriteDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *height;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpinBox *width;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QComboBox *side;
    QCheckBox *isMovable;
    QPushButton *pushButton;

    void setupUi(QDialog *SpriteDialog)
    {
        if (SpriteDialog->objectName().isEmpty())
            SpriteDialog->setObjectName(QString::fromUtf8("SpriteDialog"));
        SpriteDialog->resize(173, 182);
        widget = new QWidget(SpriteDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 156, 159));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        height = new QSpinBox(widget);
        height->setObjectName(QString::fromUtf8("height"));
        height->setMinimum(32);
        height->setMaximum(256);

        verticalLayout->addWidget(height);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        width = new QSpinBox(widget);
        width->setObjectName(QString::fromUtf8("width"));
        width->setMinimum(32);
        width->setMaximum(256);
        width->setValue(32);

        verticalLayout_2->addWidget(width);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        side = new QComboBox(widget);
        side->setObjectName(QString::fromUtf8("side"));

        verticalLayout_3->addWidget(side);


        verticalLayout_4->addLayout(verticalLayout_3);

        isMovable = new QCheckBox(widget);
        isMovable->setObjectName(QString::fromUtf8("isMovable"));

        verticalLayout_4->addWidget(isMovable);


        verticalLayout_5->addLayout(verticalLayout_4);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_5->addWidget(pushButton);


        retranslateUi(SpriteDialog);

        QMetaObject::connectSlotsByName(SpriteDialog);
    } // setupUi

    void retranslateUi(QDialog *SpriteDialog)
    {
        SpriteDialog->setWindowTitle(QApplication::translate("SpriteDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SpriteDialog", "\320\222\321\213\321\201\320\276\321\202\320\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SpriteDialog", "\320\250\320\270\321\200\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SpriteDialog", "\320\221\320\265\321\200\320\265\320\263 \320\277\320\276-\321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8));
        side->clear();
        side->insertItems(0, QStringList()
         << QApplication::translate("SpriteDialog", "\320\233\320\265\320\262\321\213\320\271", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpriteDialog", "\320\237\321\200\320\260\320\262\321\213\320\271", 0, QApplication::UnicodeUTF8)
        );
        isMovable->setText(QApplication::translate("SpriteDialog", "\320\234\320\276\320\266\320\265\321\202 \320\273\320\270 \320\277\320\265\321\200\320\265\320\264\320\262\320\270\320\263\320\260\321\202\321\214\321\201\321\217 \n"
"\320\275\320\260 \320\277\320\273\320\276\321\202\321\203 \321\201\320\260\320\274\320\276\321\201\321\202\320\276\321\217\321\202\320\265\320\273\321\214\320\275\320\276", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SpriteDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpriteDialog: public Ui_SpriteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEDIALOG_H
