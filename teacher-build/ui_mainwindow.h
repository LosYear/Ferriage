/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 28. May 12:58:21 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralWidget;
    QFrame *start_screen;
    QLabel *logo;
    QListView *listView;
    QLabel *label;
    QCommandLinkButton *new_task;
    QCommandLinkButton *open_task;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(626, 394);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        start_screen = new QFrame(centralWidget);
        start_screen->setObjectName(QString::fromUtf8("start_screen"));
        start_screen->setGeometry(QRect(10, 0, 601, 371));
        start_screen->setFrameShape(QFrame::StyledPanel);
        start_screen->setFrameShadow(QFrame::Raised);
        logo = new QLabel(start_screen);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(40, 20, 141, 71));
        listView = new QListView(start_screen);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(270, 30, 321, 301));
        label = new QLabel(start_screen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 10, 111, 16));
        new_task = new QCommandLinkButton(start_screen);
        new_task->setObjectName(QString::fromUtf8("new_task"));
        new_task->setGeometry(QRect(10, 150, 201, 71));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/start_screen/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        new_task->setIcon(icon);
        new_task->setIconSize(QSize(72, 72));
        open_task = new QCommandLinkButton(start_screen);
        open_task->setObjectName(QString::fromUtf8("open_task"));
        open_task->setGeometry(QRect(10, 230, 201, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/start_screen/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        open_task->setIcon(icon1);
        open_task->setIconSize(QSize(72, 72));
        label_2 = new QLabel(start_screen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 270, 91, 31));
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);
        label_3 = new QLabel(start_screen);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 140, 91, 31));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setFrameShadow(QFrame::Plain);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 626, 21));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_2->menuAction());
        menu_2->addAction(action_2);
        menu_2->addAction(action_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\321\213", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", 0, QApplication::UnicodeUTF8));
        logo->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\320\235\320\265\320\264\320\260\320\262\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        new_task->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", 0, QApplication::UnicodeUTF8));
        open_task->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Coming Soon", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Coming Soon", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
