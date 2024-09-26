/********************************************************************************
** Form generated from reading UI file 'mainwindowlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWLOGIN_H
#define UI_MAINWINDOWLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowLogin
{
public:
    QWidget *centralwidget;
    QStackedWidget *pages;
    QWidget *login;
    QWidget *widget;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QPushButton *view;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *hide;
    QWidget *forgot_password;
    QWidget *widget_2;
    QLineEdit *id_input_forgot;
    QPushButton *verifyidentity;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *newpassword_input;
    QPushButton *confirmnew;
    QLabel *label_10;
    QLineEdit *email_input_forgot;
    QPushButton *eyepassword_hide_forgot;
    QPushButton *eyepassword_view_forgot;
    QPushButton *back_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowLogin)
    {
        if (MainWindowLogin->objectName().isEmpty())
            MainWindowLogin->setObjectName("MainWindowLogin");
        MainWindowLogin->resize(1167, 650);
        MainWindowLogin->setStyleSheet(QString::fromUtf8("background-color:white;\n"
""));
        centralwidget = new QWidget(MainWindowLogin);
        centralwidget->setObjectName("centralwidget");
        pages = new QStackedWidget(centralwidget);
        pages->setObjectName("pages");
        pages->setGeometry(QRect(10, 0, 1151, 601));
        pages->setStyleSheet(QString::fromUtf8(""));
        login = new QWidget();
        login->setObjectName("login");
        widget = new QWidget(login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1151, 601));
        widget->setStyleSheet(QString::fromUtf8(""));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(702, 187, 371, 61));
        lineEdit->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #1E36B7;\n"
"background-color: #FFFFFF;\n"
"font-size: 25px;"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(942, 467, 131, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: #1E36B7;\n"
"color: #FFFFFF;\n"
"border-radius: 10px;\n"
"font-size: 20px;"));
        view = new QPushButton(widget);
        view->setObjectName("view");
        view->setGeometry(QRect(1032, 335, 31, 29));
        view->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 10px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/register_page/view.png"), QSize(), QIcon::Normal, QIcon::Off);
        view->setIcon(icon);
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(827, 290, 63, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(702, 67, 331, 41));
        label->setStyleSheet(QString::fromUtf8("color: #112f91;\n"
"font-size: 35px;\n"
"font-weight: bold;"));
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(42, 17, 521, 561));
        label_7->setStyleSheet(QString::fromUtf8("background-image: url(\":/imgs/login_page/login.svg\");\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"border-style:none;"));
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1027, 82, 31, 21));
        label_6->setStyleSheet(QString::fromUtf8("background-image: url(\":/imgs/login_page/iconofshopping.svg\");\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"border-style:none;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(712, 287, 111, 20));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;"));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(702, 317, 371, 61));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #1E36B7;\n"
"background-color: #FFFFFF;\n"
"font-size: 25px;"));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(790, 160, 21, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(702, 467, 131, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-color: #1B7FBD;\n"
"border-style:solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"font-size: 20px;\n"
"font-weight: bold;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(712, 157, 81, 20));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(702, 387, 171, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font-size: 20px;\n"
"color: #1E36B7;\n"
"font-weight: bold;\n"
"border-width: 1px;\n"
"border-color: red;\n"
"border-radius: 2px;"));
        hide = new QPushButton(widget);
        hide->setObjectName("hide");
        hide->setGeometry(QRect(1032, 335, 31, 29));
        hide->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 10px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/register_page/hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        hide->setIcon(icon1);
        lineEdit->raise();
        pushButton_3->raise();
        label_4->raise();
        label->raise();
        label_7->raise();
        label_6->raise();
        label_3->raise();
        lineEdit_2->raise();
        label_5->raise();
        pushButton_2->raise();
        label_2->raise();
        pushButton->raise();
        hide->raise();
        view->raise();
        pages->addWidget(login);
        forgot_password = new QWidget();
        forgot_password->setObjectName("forgot_password");
        widget_2 = new QWidget(forgot_password);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(-10, 0, 1161, 591));
        id_input_forgot = new QLineEdit(widget_2);
        id_input_forgot->setObjectName("id_input_forgot");
        id_input_forgot->setGeometry(QRect(440, 300, 261, 51));
        id_input_forgot->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border-color: #B6AFAF;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"text-align: center;"));
        id_input_forgot->setAlignment(Qt::AlignCenter);
        verifyidentity = new QPushButton(widget_2);
        verifyidentity->setObjectName("verifyidentity");
        verifyidentity->setGeometry(QRect(730, 300, 211, 41));
        verifyidentity->setStyleSheet(QString::fromUtf8("border-radius: 17px;\n"
"background-color: #112f91;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"color: white;"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(420, 20, 271, 101));
        label_8->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-weight: bold;\n"
"font-size: 30px;"));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(440, 150, 241, 61));
        label_9->setStyleSheet(QString::fromUtf8("color: grey;\n"
"font-weight: bold;\n"
"font-size: 16px;"));
        newpassword_input = new QLineEdit(widget_2);
        newpassword_input->setObjectName("newpassword_input");
        newpassword_input->setGeometry(QRect(440, 400, 261, 51));
        newpassword_input->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border-color: #B6AFAF;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"text-align: center;"));
        newpassword_input->setAlignment(Qt::AlignCenter);
        confirmnew = new QPushButton(widget_2);
        confirmnew->setObjectName("confirmnew");
        confirmnew->setGeometry(QRect(460, 460, 211, 41));
        confirmnew->setStyleSheet(QString::fromUtf8("border-radius: 17px;\n"
"background-color: #112f91;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"color: white;"));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(600, 80, 31, 41));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/imgs/login_page/code.svg")));
        label_10->setScaledContents(true);
        email_input_forgot = new QLineEdit(widget_2);
        email_input_forgot->setObjectName("email_input_forgot");
        email_input_forgot->setGeometry(QRect(440, 230, 261, 51));
        email_input_forgot->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border-color: #B6AFAF;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"text-align: center;"));
        email_input_forgot->setAlignment(Qt::AlignCenter);
        eyepassword_hide_forgot = new QPushButton(widget_2);
        eyepassword_hide_forgot->setObjectName("eyepassword_hide_forgot");
        eyepassword_hide_forgot->setGeometry(QRect(674, 416, 21, 21));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/sellereyepass/hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        eyepassword_hide_forgot->setIcon(icon2);
        eyepassword_hide_forgot->setFlat(true);
        eyepassword_view_forgot = new QPushButton(widget_2);
        eyepassword_view_forgot->setObjectName("eyepassword_view_forgot");
        eyepassword_view_forgot->setGeometry(QRect(674, 416, 21, 21));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgs/sellereyepass/view.png"), QSize(), QIcon::Normal, QIcon::Off);
        eyepassword_view_forgot->setIcon(icon3);
        eyepassword_view_forgot->setFlat(true);
        back_btn = new QPushButton(widget_2);
        back_btn->setObjectName("back_btn");
        back_btn->setGeometry(QRect(980, 528, 161, 31));
        back_btn->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: white;\n"
"background-color: black;\n"
"border-radius: 3px;"));
        pages->addWidget(forgot_password);
        MainWindowLogin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowLogin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1167, 26));
        MainWindowLogin->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowLogin);
        statusbar->setObjectName("statusbar");
        MainWindowLogin->setStatusBar(statusbar);

        retranslateUi(MainWindowLogin);

        QMetaObject::connectSlotsByName(MainWindowLogin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowLogin)
    {
        MainWindowLogin->setWindowTitle(QCoreApplication::translate("MainWindowLogin", "MainWindow", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindowLogin", "Login", nullptr));
        view->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindowLogin", "*", nullptr));
        label->setText(QCoreApplication::translate("MainWindowLogin", "Supermarket online", nullptr));
        label_7->setText(QString());
        label_6->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindowLogin", "Password", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindowLogin", "*", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindowLogin", "Register", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowLogin", "E-mail", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowLogin", "Forgot password?", nullptr));
        hide->setText(QString());
        id_input_forgot->setText(QString());
        id_input_forgot->setPlaceholderText(QCoreApplication::translate("MainWindowLogin", "Enter your ID ...", nullptr));
        verifyidentity->setText(QCoreApplication::translate("MainWindowLogin", "Verify your identity", nullptr));
#if QT_CONFIG(whatsthis)
        label_8->setWhatsThis(QCoreApplication::translate("MainWindowLogin", "<html><head/><body><p align=\"center\">Enter your</p><p align=\"center\">Verification code</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_8->setText(QCoreApplication::translate("MainWindowLogin", "<html><head/><body><p align=\"center\">Forgot Password</p><p align=\"center\">Page</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindowLogin", "<html><head/><body><p align=\"center\">Enter Your ID</p><p align=\"center\">to make new password</p></body></html>", nullptr));
        newpassword_input->setText(QString());
        newpassword_input->setPlaceholderText(QCoreApplication::translate("MainWindowLogin", "Enter New Password", nullptr));
        confirmnew->setText(QCoreApplication::translate("MainWindowLogin", "Confirm", nullptr));
        label_10->setText(QString());
        email_input_forgot->setText(QString());
        email_input_forgot->setPlaceholderText(QCoreApplication::translate("MainWindowLogin", "Enter Your Email...", nullptr));
        eyepassword_hide_forgot->setText(QString());
        eyepassword_view_forgot->setText(QString());
        back_btn->setText(QCoreApplication::translate("MainWindowLogin", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowLogin: public Ui_MainWindowLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWLOGIN_H
