/********************************************************************************
** Form generated from reading UI file 'addclassdialog.ui'
**
** Created: Fri 13. Jul 21:54:50 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCLASSDIALOG_H
#define UI_ADDCLASSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addClassDialog
{
public:
    QLabel *label_3;
    QGroupBox *groupBox;
    QLabel *lAdv;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *className;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpinBox *children;
    QCommandLinkButton *stdImg;
    QPushButton *ok;

    void setupUi(QDialog *addClassDialog)
    {
        if (addClassDialog->objectName().isEmpty())
            addClassDialog->setObjectName(QString::fromUtf8("addClassDialog"));
        addClassDialog->resize(371, 349);
        label_3 = new QLabel(addClassDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 141, 16));
        groupBox = new QGroupBox(addClassDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 200, 341, 101));
        lAdv = new QLabel(groupBox);
        lAdv->setObjectName(QString::fromUtf8("lAdv"));
        lAdv->setGeometry(QRect(20, 20, 161, 41));
        layoutWidget = new QWidget(addClassDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 135, 41));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        className = new QLineEdit(layoutWidget);
        className->setObjectName(QString::fromUtf8("className"));

        verticalLayout->addWidget(className);

        layoutWidget1 = new QWidget(addClassDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 60, 154, 41));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        children = new QSpinBox(layoutWidget1);
        children->setObjectName(QString::fromUtf8("children"));
        children->setMinimum(1);
        children->setMaximum(5);

        verticalLayout_2->addWidget(children);

        stdImg = new QCommandLinkButton(addClassDialog);
        stdImg->setObjectName(QString::fromUtf8("stdImg"));
        stdImg->setGeometry(QRect(20, 130, 64, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/addClass/mask.png"), QSize(), QIcon::Normal, QIcon::Off);
        stdImg->setIcon(icon);
        stdImg->setIconSize(QSize(50, 50));
        stdImg->setCheckable(false);
        stdImg->setChecked(false);
        ok = new QPushButton(addClassDialog);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(140, 310, 75, 23));

        retranslateUi(addClassDialog);

        QMetaObject::connectSlotsByName(addClassDialog);
    } // setupUi

    void retranslateUi(QDialog *addClassDialog)
    {
        addClassDialog->setWindowTitle(QApplication::translate("addClassDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("addClassDialog", "\320\241\321\202\320\260\320\275\320\264\321\200\320\260\321\202\320\275\320\276\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("addClassDialog", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        lAdv->setText(QApplication::translate("addClassDialog", "<html><head/><body><p>\320\222\321\213 \320\275\320\265 \320\274\320\276\320\266\320\265\321\202\320\265 \320\267\320\260\320\263\321\200\321\203\320\267\320\260\320\266\320\260\321\202\321\214 </p><p>\320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217</p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addClassDialog", "\320\230\320\274\321\217 \320\262\320\270\320\264\320\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("addClassDialog", "<html><head/><body><p>\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266\320\265\320\271 \320\262\320\270\320\264\320\260</p></body></html>", 0, QApplication::UnicodeUTF8));
        stdImg->setText(QString());
        ok->setText(QApplication::translate("addClassDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addClassDialog: public Ui_addClassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCLASSDIALOG_H
