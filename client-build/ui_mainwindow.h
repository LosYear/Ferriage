/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 7. Apr 00:12:43 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *show_task;
    QAction *steps_count;
    QAction *show_log;
    QWidget *centralWidget;
    QWidget *frame;
    QLabel *picture;
    QToolButton *left;
    QToolButton *right;
    QWidget *log_w;
    QListView *log_list;
    QToolButton *toolButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *log;
    QMenu *menu_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 615);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        show_task = new QAction(MainWindow);
        show_task->setObjectName(QString::fromUtf8("show_task"));
        show_task->setEnabled(false);
        steps_count = new QAction(MainWindow);
        steps_count->setObjectName(QString::fromUtf8("steps_count"));
        steps_count->setEnabled(false);
        show_log = new QAction(MainWindow);
        show_log->setObjectName(QString::fromUtf8("show_log"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QWidget(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 800, 600));
        picture = new QLabel(frame);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setGeometry(QRect(0, 0, 800, 600));
        left = new QToolButton(frame);
        left->setObjectName(QString::fromUtf8("left"));
        left->setEnabled(true);
        left->setGeometry(QRect(0, 540, 81, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/arrow_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        left->setIcon(icon);
        left->setIconSize(QSize(64, 64));
        left->setCheckable(false);
        left->setAutoRaise(true);
        right = new QToolButton(frame);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(710, 540, 81, 51));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/arrow_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/res/arrow_right.png"), QSize(), QIcon::Normal, QIcon::On);
        right->setIcon(icon1);
        right->setIconSize(QSize(64, 64));
        right->setAutoRaise(true);
        log_w = new QWidget(frame);
        log_w->setObjectName(QString::fromUtf8("log_w"));
        log_w->setGeometry(QRect(598, 0, 201, 541));
        log_list = new QListView(log_w);
        log_list->setObjectName(QString::fromUtf8("log_list"));
        log_list->setGeometry(QRect(0, 20, 201, 511));
        toolButton = new QToolButton(log_w);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(5, 0, 191, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy);
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        log = new QMenu(menu_3);
        log->setObjectName(QString::fromUtf8("log"));
        log->setEnabled(false);
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        menu_5->setGeometry(QRect(407, 99, 183, 50));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menu->addAction(action);
        menu_2->addAction(show_task);
        menu_3->addAction(steps_count);
        menu_3->addAction(log->menuAction());
        log->addAction(show_log);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ferriage Client", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\320\220\320\272\321\202\320\270\320\262\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8));
        show_task->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\203\321\201\320\273\320\276\320\262\320\270\320\265", 0, QApplication::UnicodeUTF8));
        steps_count->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\205\320\276\320\264\320\276\320\262", 0, QApplication::UnicodeUTF8));
        show_log->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        picture->setText(QString());
        left->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        right->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        log->setTitle(QApplication::translate("MainWindow", "\320\233\320\276\320\263", 0, QApplication::UnicodeUTF8));
        menu_5->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
