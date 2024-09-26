/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_3;
    QWidget *widget_3;
    QWidget *widget_2;
    QLabel *label_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLabel *label_9;
    QWidget *widget;
    QLabel *label_3;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *seller_login;
    QPushButton *seller_register;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1167, 650);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(0, 0, 1181, 641));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame#frame_3 {\n"
"/*background-color: red;*/\n"
"	/*background-image: url(:/imgs/home/background_home.png);*/\n"
"	/*background-image:url(:/imgs/home/background_main3.png);*/\n"
"	background-image: url(:/imgs/home/background_home.png);\n"
"background-repeat: no-repeat;\n"
"  \n"
"  background-position: center;\n"
"\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        widget_3 = new QWidget(frame_3);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 1161, 601));
        widget_3->setStyleSheet(QString::fromUtf8("/*\n"
"QWidget {\n"
"background-image: url(\":/imgs/register_page/image.png\");\n"
"}\n"
"\n"
"QWidget widget {\n"
"background-image:none;\n"
"}\n"
"*/\n"
"/*\n"
"QWidget {\n"
"background-color: red;\n"
"border-color: black;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"}\n"
"*/"));
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(690, 180, 311, 351));
        widget_2->setStyleSheet(QString::fromUtf8("/*background-color: #e8e8e6;*/\n"
"background-color: white;\n"
"border-radius: 15px;"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 10, 91, 41));
        label_2->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: black;\n"
"font-size: 40px;\n"
"border-radius: 1px;"));
        layoutWidget_3 = new QWidget(widget_2);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(6, 281, 291, 62));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget_3);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setStyleSheet(QString::fromUtf8("border-width: 2px;\n"
"border-color: #112f91;\n"
"border-style: solid;\n"
"color: #112f91;\n"
"font-weight: bold;\n"
"border-radius: 10px;\n"
"\n"
""));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #112f91;\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius: 5px;\n"
""));

        horizontalLayout_2->addWidget(pushButton_2);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 10, 291, 271));
        label_6->setStyleSheet(QString::fromUtf8("border-radius: 3px;"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/imgs/home/customer_home.png")));
        label_6->setScaledContents(true);
        label_9 = new QLabel(widget_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(90, -20, 141, 51));
        label_9->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        label_9->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        widget = new QWidget(widget_3);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(190, 180, 311, 351));
        widget->setStyleSheet(QString::fromUtf8("/*\n"
"border-color: red;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"background-image: none;\n"
"background-color: white;\n"
"\n"
"background-color: #e8e8e6;*/\n"
"background-color: white;\n"
"border-radius: 10px;\n"
"border-radius: 15px;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(150, 90, 111, 41));
        label_3->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: black;\n"
"font-size: 40px;\n"
"border-radius:1px;\n"
"\n"
""));
        layoutWidget_4 = new QWidget(widget);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(10, 291, 291, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        seller_login = new QPushButton(layoutWidget_4);
        seller_login->setObjectName("seller_login");
        seller_login->setMinimumSize(QSize(0, 40));
        seller_login->setStyleSheet(QString::fromUtf8("/*background-color: #F10000;*/\n"
"border-width: 2px;\n"
"border-color: #F10000;\n"
"border-style: solid;\n"
"color: #F10000;\n"
"font-weight: bold;\n"
"border-radius: 10px;\n"
""));

        horizontalLayout_4->addWidget(seller_login);

        seller_register = new QPushButton(layoutWidget_4);
        seller_register->setObjectName("seller_register");
        seller_register->setMinimumSize(QSize(0, 40));
        seller_register->setStyleSheet(QString::fromUtf8("background-color: #F10000;\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius: 10px;\n"
""));

        horizontalLayout_4->addWidget(seller_register);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 291, 271));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imgs/home/seller_homee.png")));
        label->setScaledContents(true);
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(80, -20, 141, 51));
        label_8->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        label_8->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(130, 20, 891, 81));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"background-color: #2E4F4F;\n"
"color: white;\n"
"border: none;\n"
"\n"
""));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(940, 20, 81, 91));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/imgs/home/homeee.png")));
        label_5->setScaledContents(true);
        label_7 = new QLabel(widget_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(540, 120, 151, 41));
        label_7->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-weight:bold;\n"
"font-size: 30px;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1167, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_6->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Buyer", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Seller", nullptr));
        seller_login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        seller_register->setText(QCoreApplication::translate("MainWindow", "Create New Seller Account", nullptr));
        label->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Seller", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">SuperMarket Online Shopping</span></p></body></html>", nullptr));
        label_5->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Join us As", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
