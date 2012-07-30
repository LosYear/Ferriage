/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 30. Jul 14:45:01 2012
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
#include <QtGui/QCheckBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
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
    QStackedWidget *wizard_widget;
    QWidget *background;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *bgLabel;
    QHBoxLayout *horizontalLayout;
    QLineEdit *background_edit;
    QPushButton *bgButton;
    QPushButton *cNext_2;
    QWidget *classes;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cBack;
    QPushButton *cNext;
    QListWidget *list;
    QToolButton *addClass;
    QWidget *rules;
    QLabel *label_4;
    QToolButton *addRule;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *rBack;
    QPushButton *rNext;
    QWidget *raft;
    QLabel *label_5;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *bgLabel_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *raft_edit;
    QPushButton *raftPick;
    QCheckBox *checkBox;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *rBack_2;
    QPushButton *rNext_2;
    QSpinBox *maxSprites;
    QLabel *label_9;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *defaultLeft;
    QRadioButton *defaultRight;
    QWidget *position;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *widget;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label_8;
    QWidget *widget_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_6;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *rBack_3;
    QPushButton *saveFile;
    QWidget *panel;
    QWidget *buttons;
    QPushButton *step1;
    QPushButton *step2;
    QPushButton *step3;
    QPushButton *step4;
    QPushButton *step5;
    QPushButton *minimeze;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("/* \320\236\321\201\320\275\320\276\320\262\320\275\320\260\321\217 \320\277\320\260\320\275\320\265\320\273\321\214 */ \n"
"#wizard_widget, #rules, #background, #classes, #raft, #position{\n"
"	background: url(:/main/bg);\n"
"	border-top-left-radius:15px;\n"
"	border-top-right-radius:15px;\n"
"}\n"
"\n"
"#rules *, #background *, #classes *, #raft *, #position *{\n"
"	background:transparent;\n"
"}\n"
"\n"
"/* \320\222\321\201\320\277\320\276\320\274\320\276\320\263\320\260\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\277\320\260\320\275\320\265\320\273\321\214 */\n"
"#panel {\n"
"	border: none;\n"
"	background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"	stop: 0 #a6a6a6, stop: 0.08 #7f7f7f,\n"
"	stop: 0.39999 #717171, stop: 0.4 #626262,\n"
"	stop: 0.9 #4c4c4c, stop: 1 #333333);\n"
"}\n"
"\n"
"/* \320\232\320\275\320\276\320\277\320\272\320\270 \320\275\320\260 panel */\n"
"#panel QPushButton {\n"
"	color: #333;\n"
"	border: 2px solid #555;\n"
"	border-radius: 11px;\n"
"	padding: 5px;\n"
"	"
                        "background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"	fx: 0.3, fy: -0.4,\n"
"	radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"}\n"
"\n"
"#panel QPushButton:hover {\n"
"	background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"	fx: 0.3, fy: -0.4,\n"
"	radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
"\n"
"#panel QPushButton:pressed {\n"
"	background: qradialgradient(cx: 0.4, cy: -0.1,\n"
"	fx: 0.4, fy: -0.1,\n"
"	radius: 1.35, stop: 0 #fff, stop: 1 #ddd);\n"
"}\n"
"\n"
"#panel QPushButton:checked {\n"
"	background: qradialgradient(cx: 0.4, cy: -0.1,\n"
"	fx: 0.4, fy: -0.1,\n"
"	radius: 1.35, stop: 0 #fff, stop: 1 #ddd);\n"
"}\n"
"\n"
"/* \320\232\320\275\320\276\320\277\320\272\320\270 */\n"
"#wizard_widget QPushButton {\n"
"	color: #333;\n"
"	border: 2px solid #555;\n"
"	border-radius: 11px;\n"
"	padding: 5px;\n"
"	background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"	fx: 0.3, fy: -0.4,\n"
"	radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"}\n"
"\n"
"#wizard_widget QPushButton:hover {\n"
"	background: qradialgradient(cx"
                        ": 0.3, cy: -0.4,\n"
"	fx: 0.3, fy: -0.4,\n"
"	radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
"\n"
"#wizard_widget QPushButton:pressed {\n"
"	background: qradialgradient(cx: 0.4, cy: -0.1,\n"
"	fx: 0.4, fy: -0.1,\n"
"	radius: 1.35, stop: 0 #fff, stop: 1 #ddd);\n"
"}\n"
"\n"
"/* \320\235\320\260\320\264\320\277\320\270\321\201\320\270 */\n"
"#wizard_widget QLabel{\n"
"	color : white;\n"
"}\n"
"\n"
"/* \320\237\320\276\320\273\321\217 \320\262\320\262\320\276\320\264\320\260 */\n"
"#wizard_widget QLineEdit{\n"
"	background :qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0.255682 			   	rgba(243, 243, 243, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius:10px;\n"
"	border: 2px solid #555;\n"
"}\n"
"\n"
"/* \320\241\320\277\320\270\321\201\320\276\320\272 */\n"
"#wizard_widget QListView{\n"
"	background:white;\n"
"	border-bottom-right-radius : 10px;\n"
"	border-bottom-left-radius : 10px;\n"
"	border: 2px solid #555;\n"
"\n"
"}\n"
"\n"
"#wizard_widget QListView::item:alternate{\n"
"     "
                        "background: white;\n"
" }\n"
"\n"
"#wizard_widget QListView::item{\n"
"     background: rgb(241,244,248);\n"
" }\n"
"\n"
"#wizard_widget QListView::item:selected{\n"
"     background: rgb(75,149,229);\n"
" }\n"
"\n"
"/* \320\232\320\275\320\276\320\277\320\276\321\207\320\272\320\260 + */\n"
"#wizard_widget #addClass, #addRule{\n"
"	border-bottom-left-radius:5px;\n"
"	border-bottom-right-radius:5px;\n"
"	color: #333;\n"
"	border: 2px solid #555;\n"
"	padding: 5px;\n"
"	background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"	fx: 0.3, fy: -0.4,\n"
"	radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"}\n"
"\n"
"#wizard_widget #addClass:hover, #addRule:hover {\n"
"	background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"	fx: 0.3, fy: -0.4,\n"
"	radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
"\n"
"#wizard_widget #addClass:pressed, #addRule:pressed {\n"
"	background: qradialgradient(cx: 0.4, cy: -0.1,\n"
"	fx: 0.4, fy: -0.1,\n"
"	radius: 1.35, stop: 0 #fff, stop: 1 #ddd);\n"
"}\n"
"\n"
"/* \320\237\320\276\320\273\320\276\321"
                        "\201\320\272\320\260 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 */\n"
"#wizard_widget QScrollBar:vertical{\n"
"	background:transparent;\n"
"	max-width:8px;\n"
"}\n"
"\n"
"#wizard_widget QScrollBar::sub-line:vertical{\n"
"	background:transparent;\n"
"}\n"
"\n"
"#wizard_widget QScrollBar::add-line:vertical{\n"
"	background:transparent;\n"
"}\n"
"\n"
"#wizard_widget QScrollBar::add-page:vertical{\n"
"	background:transparent;\n"
"}\n"
"\n"
"#wizard_widget QScrollBar::sub-page:vertical{\n"
"	background:transparent;\n"
"}\n"
"\n"
"#wizard_widget QScrollBar::handle:vertical{\n"
"	background:rgb(241,241,241);\n"
"	min-height:20px\n"
"}\n"
"\n"
"#wizard_widget QScrollBar::handle:hover:vertical{\n"
"	background:rgb(205,205,205);\n"
"}\n"
"\n"
"#wizard_widget QScrollBar::handle:pressed:vertical{\n"
"	background:rgb(167,167,167);\n"
"}\n"
"\n"
"/* \320\222\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\270\320\265 \321\201\320\277\320\270\321\201\320\272\320\270 */\n"
"#wizard_wi"
                        "dget QComboBox{\n"
"	background:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0.255682 rgba(243, 243, 243, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	border: 2px solid #555;\n"
"	border-radius:10px;\n"
"}\n"
"\n"
"#wizard_widget  QComboBox::drop-down{\n"
"	border-top-right-radius:10px;\n"
"	border-top-left-radius:10px;\n"
"}\n"
"#wizard_widget QComboBox::down-arrow {\n"
"     image: url(:/main/down);\n"
"     width: 10px;\n"
"     height: 10px;\n"
"\n"
" }\n"
"#wizard_widget QComboBox QAbstractItemView {\n"
"     border: none;\n"
"     border-radius:none;\n"
" }\n"
"\n"
"/* \320\223\320\260\320\273\320\276\321\207\320\272\320\260 */\n"
"#wizard_widget QCheckBox{\n"
"	color:white;\n"
"}\n"
"\n"
"#wizard_widget QCheckBox:indicator{\n"
"	\n"
"	image: url(:/main/unchecked);\n"
"}\n"
"\n"
"#wizard_widget QCheckBox:indicator::checked{\n"
"	\n"
"	image: url(:/main/checked);\n"
"}\n"
"\n"
"#wizard_widget QCheckBox:indicator:hover{\n"
"	\n"
"	image: url(:/main/unchecked_hovered)\n"
"}\n"
"\n"
"#wizard_"
                        "widget QCheckBox:indicator::checked:hover{\n"
"	\n"
"	image: url(:/main/checked_hovered)\n"
"}\n"
"\n"
"/* \320\240\320\260\320\264\320\270\320\276 \320\272\320\275\320\276\320\277\320\272\320\260 */\n"
"#wizard_widget QRadioButton{\n"
"	color:white;\n"
"}\n"
"\n"
"#wizard_widget QRadioButton:indicator{\n"
"	\n"
"	image: url(:/main/radio_unchecked);\n"
"}\n"
"\n"
"#wizard_widget QRadioButton:indicator::checked{\n"
"	image: url(:/main/radio_checked);\n"
"}\n"
"\n"
"#wizard_widget QRadioButton:indicator:hover{\n"
"	\n"
"	image: url(:/main/radio_hover);\n"
"	\n"
"}\n"
"\n"
"#wizard_widget QRadioButton:indicator::checked:hover{\n"
"	\n"
"	image: url(:/main/radio_checked_hover);\n"
"	\n"
"}\n"
"\n"
"/* QSpinBox */\n"
"#wizard_widget QSpinBox{\n"
"	border: 2px solid #555;\n"
"	background:qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0.255682 rgba(243, 243, 243, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius : 10px;\n"
"}\n"
"\n"
"#wizard_widget QSpinBox:up-button{\n"
"	border-top-right-rad"
                        "ius : 10px;\n"
"}\n"
"\n"
"#wizard_widget QSpinBox:down-button{\n"
"	border-bottom-right-radius : 10px;\n"
"}\n"
"\n"
"#wizard_widget QSpinBox:up-arrow{\n"
"	\n"
"	image: url(:/main/up);\n"
"	height : 8px;\n"
"	width : 8px;\n"
"	margin-right:5px;\n"
"}\n"
"\n"
"#wizard_widget QSpinBox:down-arrow{\n"
"	image: url(:/main/down);\n"
"	height : 8px;\n"
"	width : 8px;\n"
"	margin-right:5px;\n"
"	\n"
"}\n"
"\n"
"/* \320\232\320\275\320\276\320\277\320\272\320\260 \320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 */\n"
"#panel #saveFile{\n"
"	background:none;\n"
"	border:none;\n"
"}"));
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
        wizard_widget = new QStackedWidget(centralWidget);
        wizard_widget->setObjectName(QString::fromUtf8("wizard_widget"));
        wizard_widget->setGeometry(QRect(0, 400, 800, 200));
        wizard_widget->setFrameShape(QFrame::NoFrame);
        wizard_widget->setFrameShadow(QFrame::Plain);
        background = new QWidget();
        background->setObjectName(QString::fromUtf8("background"));
        background->setAutoFillBackground(false);
        layoutWidget = new QWidget(background);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 20, 191, 64));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bgLabel = new QLabel(layoutWidget);
        bgLabel->setObjectName(QString::fromUtf8("bgLabel"));

        verticalLayout->addWidget(bgLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        background_edit = new QLineEdit(layoutWidget);
        background_edit->setObjectName(QString::fromUtf8("background_edit"));
        background_edit->setReadOnly(true);

        horizontalLayout->addWidget(background_edit);

        bgButton = new QPushButton(layoutWidget);
        bgButton->setObjectName(QString::fromUtf8("bgButton"));

        horizontalLayout->addWidget(bgButton);


        verticalLayout->addLayout(horizontalLayout);

        cNext_2 = new QPushButton(background);
        cNext_2->setObjectName(QString::fromUtf8("cNext_2"));
        cNext_2->setGeometry(QRect(701, 171, 94, 27));
        wizard_widget->addWidget(background);
        classes = new QWidget();
        classes->setObjectName(QString::fromUtf8("classes"));
        layoutWidget1 = new QWidget(classes);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(600, 170, 196, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        cBack = new QPushButton(layoutWidget1);
        cBack->setObjectName(QString::fromUtf8("cBack"));

        horizontalLayout_2->addWidget(cBack);

        cNext = new QPushButton(layoutWidget1);
        cNext->setObjectName(QString::fromUtf8("cNext"));

        horizontalLayout_2->addWidget(cNext);

        list = new QListWidget(classes);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(280, -2, 256, 192));
        list->setAlternatingRowColors(true);
        addClass = new QToolButton(classes);
        addClass->setObjectName(QString::fromUtf8("addClass"));
        addClass->setGeometry(QRect(540, -2, 25, 35));
        wizard_widget->addWidget(classes);
        rules = new QWidget();
        rules->setObjectName(QString::fromUtf8("rules"));
        label_4 = new QLabel(rules);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(370, 10, 61, 16));
        addRule = new QToolButton(rules);
        addRule->setObjectName(QString::fromUtf8("addRule"));
        addRule->setGeometry(QRect(770, -2, 25, 35));
        layoutWidget_2 = new QWidget(rules);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(600, 170, 196, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        rBack = new QPushButton(layoutWidget_2);
        rBack->setObjectName(QString::fromUtf8("rBack"));

        horizontalLayout_3->addWidget(rBack);

        rNext = new QPushButton(layoutWidget_2);
        rNext->setObjectName(QString::fromUtf8("rNext"));

        horizontalLayout_3->addWidget(rNext);

        wizard_widget->addWidget(rules);
        raft = new QWidget();
        raft->setObjectName(QString::fromUtf8("raft"));
        label_5 = new QLabel(raft);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(350, 10, 71, 16));
        layoutWidget_3 = new QWidget(raft);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(200, 30, 191, 64));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        bgLabel_2 = new QLabel(layoutWidget_3);
        bgLabel_2->setObjectName(QString::fromUtf8("bgLabel_2"));

        verticalLayout_2->addWidget(bgLabel_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        raft_edit = new QLineEdit(layoutWidget_3);
        raft_edit->setObjectName(QString::fromUtf8("raft_edit"));
        raft_edit->setReadOnly(true);

        horizontalLayout_4->addWidget(raft_edit);

        raftPick = new QPushButton(layoutWidget_3);
        raftPick->setObjectName(QString::fromUtf8("raftPick"));

        horizontalLayout_4->addWidget(raftPick);


        verticalLayout_2->addLayout(horizontalLayout_4);

        checkBox = new QCheckBox(raft);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(200, 100, 171, 41));
        checkBox->setCheckable(true);
        checkBox->setChecked(false);
        layoutWidget_4 = new QWidget(raft);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(600, 170, 196, 29));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        rBack_2 = new QPushButton(layoutWidget_4);
        rBack_2->setObjectName(QString::fromUtf8("rBack_2"));

        horizontalLayout_5->addWidget(rBack_2);

        rNext_2 = new QPushButton(layoutWidget_4);
        rNext_2->setObjectName(QString::fromUtf8("rNext_2"));

        horizontalLayout_5->addWidget(rNext_2);

        maxSprites = new QSpinBox(raft);
        maxSprites->setObjectName(QString::fromUtf8("maxSprites"));
        maxSprites->setGeometry(QRect(340, 140, 51, 21));
        maxSprites->setMinimum(1);
        maxSprites->setMaximum(10);
        label_9 = new QLabel(raft);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(170, 130, 141, 41));
        layoutWidget2 = new QWidget(raft);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(420, 30, 132, 48));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        defaultLeft = new QRadioButton(layoutWidget2);
        defaultLeft->setObjectName(QString::fromUtf8("defaultLeft"));

        horizontalLayout_7->addWidget(defaultLeft);

        defaultRight = new QRadioButton(layoutWidget2);
        defaultRight->setObjectName(QString::fromUtf8("defaultRight"));

        horizontalLayout_7->addWidget(defaultRight);


        verticalLayout_3->addLayout(horizontalLayout_7);

        wizard_widget->addWidget(raft);
        position = new QWidget();
        position->setObjectName(QString::fromUtf8("position"));
        label_6 = new QLabel(position);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(320, 10, 181, 16));
        label_7 = new QLabel(position);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 40, 101, 16));
        widget = new QWidget(position);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(270, 30, 301, 31));
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(0, 10, 101, 17));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(110, 10, 82, 17));
        radioButton_3 = new QRadioButton(widget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(200, 10, 101, 17));
        label_8 = new QLabel(position);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(160, 70, 101, 16));
        widget_2 = new QWidget(position);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(270, 60, 301, 31));
        radioButton_4 = new QRadioButton(widget_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(0, 10, 101, 17));
        radioButton_4->setChecked(true);
        radioButton_6 = new QRadioButton(widget_2);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(200, 10, 101, 17));
        layoutWidget_5 = new QWidget(position);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(600, 170, 196, 29));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        rBack_3 = new QPushButton(layoutWidget_5);
        rBack_3->setObjectName(QString::fromUtf8("rBack_3"));

        horizontalLayout_6->addWidget(rBack_3);

        saveFile = new QPushButton(layoutWidget_5);
        saveFile->setObjectName(QString::fromUtf8("saveFile"));

        horizontalLayout_6->addWidget(saveFile);

        wizard_widget->addWidget(position);
        panel = new QWidget(centralWidget);
        panel->setObjectName(QString::fromUtf8("panel"));
        panel->setGeometry(QRect(-10, 350, 811, 80));
        buttons = new QWidget(panel);
        buttons->setObjectName(QString::fromUtf8("buttons"));
        buttons->setGeometry(QRect(20, 10, 161, 31));
        step1 = new QPushButton(buttons);
        step1->setObjectName(QString::fromUtf8("step1"));
        step1->setGeometry(QRect(10, 0, 23, 23));
        step1->setCheckable(true);
        step1->setChecked(true);
        step2 = new QPushButton(buttons);
        step2->setObjectName(QString::fromUtf8("step2"));
        step2->setGeometry(QRect(40, 0, 23, 23));
        step2->setCheckable(true);
        step3 = new QPushButton(buttons);
        step3->setObjectName(QString::fromUtf8("step3"));
        step3->setGeometry(QRect(70, 0, 23, 23));
        step3->setCheckable(true);
        step4 = new QPushButton(buttons);
        step4->setObjectName(QString::fromUtf8("step4"));
        step4->setGeometry(QRect(100, 0, 23, 23));
        step4->setCheckable(true);
        step5 = new QPushButton(buttons);
        step5->setObjectName(QString::fromUtf8("step5"));
        step5->setGeometry(QRect(130, 0, 23, 23));
        step5->setCheckable(true);
        minimeze = new QPushButton(panel);
        minimeze->setObjectName(QString::fromUtf8("minimeze"));
        minimeze->setGeometry(QRect(770, 10, 23, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/main/down"), QSize(), QIcon::Normal, QIcon::Off);
        minimeze->setIcon(icon2);
        minimeze->setIconSize(QSize(10, 10));
        minimeze->setCheckable(false);
        MainWindow->setCentralWidget(centralWidget);
        start_screen->raise();
        panel->raise();
        wizard_widget->raise();

        retranslateUi(MainWindow);

        wizard_widget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\321\213", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", 0, QApplication::UnicodeUTF8));
        logo->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", 0, QApplication::UnicodeUTF8));
        new_task->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", 0, QApplication::UnicodeUTF8));
        open_task->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Coming Soon", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Coming Soon", 0, QApplication::UnicodeUTF8));
        bgLabel->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\276\320\275", 0, QApplication::UnicodeUTF8));
        bgButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        cNext_2->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        cBack->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", 0, QApplication::UnicodeUTF8));
        cNext->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        addClass->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260", 0, QApplication::UnicodeUTF8));
        addRule->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        rBack->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", 0, QApplication::UnicodeUTF8));
        rNext->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\262\320\276\320\267\321\207\320\270\320\272", 0, QApplication::UnicodeUTF8));
        bgLabel_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        raftPick->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\266\320\265\321\202 \320\273\320\270 \320\277\320\265\321\200\320\265\320\262\320\276\320\267\321\207\320\270\320\272\n"
"\320\264\320\262\320\270\320\263\320\260\321\202\321\214\321\201\321\217 \321\201\320\260\320\274\320\276\321\201\321\202\320\276\321\217\321\202\320\265\320\273\321\214\320\275\320\276", 0, QApplication::UnicodeUTF8));
        rBack_2->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", 0, QApplication::UnicodeUTF8));
        rNext_2->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 <br>\n"
"\320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\320\221\320\265\321\200\320\265\320\263", 0, QApplication::UnicodeUTF8));
        defaultLeft->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\262\321\213\320\271", 0, QApplication::UnicodeUTF8));
        defaultRight->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\321\213\320\271", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\267\320\270\321\206\320\270\320\276\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\262\321\213\320\271 \320\261\320\265\321\200\320\265\320\263", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\235\320\260 \320\277\320\273\320\276\321\202\321\203", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\321\213\320\271 \320\261\320\265\321\200\320\265\320\263", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217 \320\277\320\273\320\276\321\202\320\260", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\262\321\213\320\271 \320\261\320\265\321\200\320\265\320\263", 0, QApplication::UnicodeUTF8));
        radioButton_6->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\321\213\320\271 \320\261\320\265\321\200\320\265\320\263", 0, QApplication::UnicodeUTF8));
        rBack_3->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", 0, QApplication::UnicodeUTF8));
        saveFile->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        step1->setToolTip(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\204\320\276\320\275\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        step1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        step2->setToolTip(QApplication::translate("MainWindow", "\320\242\320\270\320\277\321\213 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        step2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        step3->setToolTip(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        step3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        step4->setToolTip(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\262\320\276\320\267\321\207\320\270\320\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        step4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        step5->setToolTip(QApplication::translate("MainWindow", "\320\237\320\276\320\267\320\270\321\206\320\270\320\276\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        step5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        minimeze->setToolTip(QApplication::translate("MainWindow", "\320\237\320\276\320\267\320\270\321\206\320\270\320\276\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        minimeze->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
