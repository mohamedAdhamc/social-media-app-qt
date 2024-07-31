/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *sign_up;
    QFrame *frame;
    QPushButton *SPsignupButton;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QLabel *label_3;
    QPushButton *SPloginButton;
    QWidget *login;
    QStackedWidget *stackedWidget_2;
    QWidget *sign_up_2;
    QWidget *login_2;
    QWidget *home_2;
    QLabel *label_6;
    QFrame *frame_2;
    QPushButton *loginButton_2;
    QLabel *label_4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QLabel *label_5;
    QPushButton *LsignupButton;
    QWidget *home;
    QLabel *label_2;
    QPushButton *settingsButton;
    QPushButton *messageButton;
    QPushButton *profileButton;
    QScrollArea *newsFeed;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 10, 761, 481));
        sign_up = new QWidget();
        sign_up->setObjectName(QString::fromUtf8("sign_up"));
        frame = new QFrame(sign_up);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(190, 80, 381, 301));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        SPsignupButton = new QPushButton(frame);
        SPsignupButton->setObjectName(QString::fromUtf8("SPsignupButton"));
        SPsignupButton->setGeometry(QRect(140, 220, 89, 25));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 30, 101, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 80, 181, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        textEdit_2 = new QTextEdit(verticalLayoutWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        verticalLayout->addWidget(textEdit_2);

        textEdit_3 = new QTextEdit(verticalLayoutWidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));

        verticalLayout->addWidget(textEdit_3);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(56, 250, 161, 20));
        SPloginButton = new QPushButton(frame);
        SPloginButton->setObjectName(QString::fromUtf8("SPloginButton"));
        SPloginButton->setGeometry(QRect(230, 250, 71, 21));
        stackedWidget->addWidget(sign_up);
        login = new QWidget();
        login->setObjectName(QString::fromUtf8("login"));
        stackedWidget_2 = new QStackedWidget(login);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(380, 210, 761, 481));
        sign_up_2 = new QWidget();
        sign_up_2->setObjectName(QString::fromUtf8("sign_up_2"));
        stackedWidget_2->addWidget(sign_up_2);
        login_2 = new QWidget();
        login_2->setObjectName(QString::fromUtf8("login_2"));
        stackedWidget_2->addWidget(login_2);
        home_2 = new QWidget();
        home_2->setObjectName(QString::fromUtf8("home_2"));
        label_6 = new QLabel(home_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(320, 30, 121, 51));
        stackedWidget_2->addWidget(home_2);
        frame_2 = new QFrame(login);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(190, 90, 381, 301));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        loginButton_2 = new QPushButton(frame_2);
        loginButton_2->setObjectName(QString::fromUtf8("loginButton_2"));
        loginButton_2->setGeometry(QRect(140, 220, 89, 25));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 30, 101, 51));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_2 = new QWidget(frame_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(90, 100, 181, 101));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit_4 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));

        verticalLayout_2->addWidget(textEdit_4);

        textEdit_5 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));

        verticalLayout_2->addWidget(textEdit_5);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(56, 250, 161, 20));
        LsignupButton = new QPushButton(frame_2);
        LsignupButton->setObjectName(QString::fromUtf8("LsignupButton"));
        LsignupButton->setGeometry(QRect(230, 250, 61, 21));
        stackedWidget->addWidget(login);
        home = new QWidget();
        home->setObjectName(QString::fromUtf8("home"));
        label_2 = new QLabel(home);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 0, 377, 25));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        settingsButton = new QPushButton(home);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        settingsButton->setGeometry(QRect(0, 0, 41, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("resources/settings-icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        settingsButton->setIcon(icon);
        messageButton = new QPushButton(home);
        messageButton->setObjectName(QString::fromUtf8("messageButton"));
        messageButton->setGeometry(QRect(720, 0, 41, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("resources/messageIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        messageButton->setIcon(icon1);
        profileButton = new QPushButton(home);
        profileButton->setObjectName(QString::fromUtf8("profileButton"));
        profileButton->setGeometry(QRect(670, 0, 41, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("resources/profileIcon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        profileButton->setIcon(icon2);
        newsFeed = new QScrollArea(home);
        newsFeed->setObjectName(QString::fromUtf8("newsFeed"));
        newsFeed->setGeometry(QRect(130, 80, 471, 311));
        newsFeed->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        newsFeed->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 455, 309));
        newsFeed->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(home);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SPsignupButton->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your email", nullptr));
        textEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Create a password", nullptr));
        textEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "Confirm password", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Already have an account ?", nullptr));
        SPloginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Home Page", nullptr));
        loginButton_2->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        textEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your email", nullptr));
        textEdit_5->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter you password", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Don't have an account ? ", nullptr));
        LsignupButton->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        settingsButton->setText(QString());
        messageButton->setText(QString());
        profileButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
