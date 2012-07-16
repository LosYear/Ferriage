/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 16. Jul 20:40:52 2012
**      by: Qt User Interface Compiler version 4.8.1
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
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *start_screen;
    QLabel *logo;
    QListView *listView;
    QLabel *label;
    QCommandLinkButton *open_task;
    QLabel *label_3;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(617, 410);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        start_screen = new QFrame(centralWidget);
        start_screen->setObjectName(QString::fromUtf8("start_screen"));
        start_screen->setGeometry(QRect(10, 10, 601, 371));
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
        open_task = new QCommandLinkButton(start_screen);
        open_task->setObjectName(QString::fromUtf8("open_task"));
        open_task->setGeometry(QRect(10, 150, 201, 71));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/start_screen/open"), QSize(), QIcon::Normal, QIcon::Off);
        open_task->setIcon(icon);
        open_task->setIconSize(QSize(72, 72));
        label_3 = new QLabel(start_screen);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 140, 91, 31));
        QFont font;
        font.setPointSize(11);
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setFrameShadow(QFrame::Plain);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 617, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ferriage", 0, QApplication::UnicodeUTF8));
        logo->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", 0, QApplication::UnicodeUTF8));
        open_task->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Coming Soon", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
