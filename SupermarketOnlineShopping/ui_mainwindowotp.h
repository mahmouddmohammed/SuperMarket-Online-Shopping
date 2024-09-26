/********************************************************************************
** Form generated from reading UI file 'mainwindowotp.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWOTP_H
#define UI_MAINWINDOWOTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowOtp
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowOtp)
    {
        if (MainWindowOtp->objectName().isEmpty())
            MainWindowOtp->setObjectName("MainWindowOtp");
        MainWindowOtp->resize(1167, 650);
        MainWindowOtp->setStyleSheet(QString::fromUtf8("background-color: white;"));
        centralwidget = new QWidget(MainWindowOtp);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(460, 400, 261, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border-color: #B6AFAF;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"text-align: center;"));
        lineEdit->setMaxLength(6);
        lineEdit->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(500, 498, 171, 41));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 17px;\n"
"background-color: #112f91;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"color: white;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(450, 50, 271, 111));
        label->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-weight: bold;\n"
"font-size: 30px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(470, 160, 241, 61));
        label_2->setStyleSheet(QString::fromUtf8("color: grey;\n"
"font-weight: bold;\n"
"font-size: 16px;"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(500, 558, 181, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: #1B7FBD;\n"
"font-size: 18px;\n"
"font-weight: bold;\n"
"background-color: #ffffff;\n"
"\n"
"border-color: red;\n"
"border-radius: 2px;\n"
""));
        MainWindowOtp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowOtp);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1167, 26));
        MainWindowOtp->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowOtp);
        statusbar->setObjectName("statusbar");
        MainWindowOtp->setStatusBar(statusbar);

        retranslateUi(MainWindowOtp);

        QMetaObject::connectSlotsByName(MainWindowOtp);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowOtp)
    {
        MainWindowOtp->setWindowTitle(QCoreApplication::translate("MainWindowOtp", "MainWindow", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindowOtp", "Enter The Code ...", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowOtp", "Verify", nullptr));
#if QT_CONFIG(whatsthis)
        label->setWhatsThis(QCoreApplication::translate("MainWindowOtp", "<html><head/><body><p align=\"center\">Enter your</p><p align=\"center\">Verification code</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QCoreApplication::translate("MainWindowOtp", "<html><head/><body><p align=\"center\">Enter your</p><p align=\"center\">Verification code</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowOtp", "<html><head/><body><p align=\"center\">We sent a verification code to </p><p align=\"center\">your e-mail</p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindowOtp", "Send another code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowOtp: public Ui_MainWindowOtp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWOTP_H
