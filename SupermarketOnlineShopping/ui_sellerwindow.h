/********************************************************************************
** Form generated from reading UI file 'sellerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLERWINDOW_H
#define UI_SELLERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SellerWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QStackedWidget *stackedWidget;
    QWidget *login_page;
    QLabel *label_5;
    QPushButton *login_btn_loginpage;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *email_input_login;
    QLineEdit *password_input_login;
    QPushButton *forget_password_btn_login;
    QLabel *label_4;
    QPushButton *register_btn_loginpage;
    QLabel *label_3;
    QPushButton *eyepassword_hide_login;
    QPushButton *eyepassword_view_login;
    QLabel *label_35;
    QWidget *Register_page;
    QLabel *label_10;
    QLabel *label_7;
    QPushButton *login_btn_rpage;
    QLineEdit *fullname_input;
    QPushButton *register_btnn_rpage;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_9;
    QLabel *label_11;
    QLineEdit *email_input_register;
    QLabel *label_14;
    QLineEdit *password_input_register;
    QLabel *label_15;
    QLineEdit *phonenumber_register;
    QLineEdit *day_register;
    QLineEdit *month_register;
    QLineEdit *year_register;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *username_input;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *eyepassword_hide_register;
    QPushButton *eyepassword_view_register;
    QPushButton *profile_photo_image;
    QComboBox *gender_comboBox;
    QLabel *label_34;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_32;
    QLabel *label_38;
    QCheckBox *checkbox_agreeto_policy;
    QPushButton *agreements_btn;
    QWidget *forget_password;
    QLineEdit *id_input_forgot;
    QLineEdit *newpassword_input;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *confirmnewpassword_btn;
    QPushButton *verifyidentity;
    QLineEdit *email_input_forgot;
    QLineEdit *username_input_forgot;
    QPushButton *eyepassword_view_forget;
    QPushButton *eyepassword_hide_forget;
    QPushButton *back_btn;
    QWidget *home_page;
    QFrame *frame;
    QFrame *frame_2;
    QLabel *label_29;
    QPushButton *add_product;
    QPushButton *profile_stting_btn;
    QPushButton *view_products;
    QLabel *label_30;
    QLabel *acc_balance_value;
    QPushButton *home_btn;
    QStackedWidget *stackedWidget_2;
    QWidget *home_pagee;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QPushButton *add_products_now;
    QLabel *label_28;
    QLabel *name_of_seller;
    QPushButton *logout;
    QWidget *add_product_page;
    QWidget *widget_4;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QPushButton *addproduct_btn;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_39;
    QLineEdit *product_name;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_40;
    QComboBox *comboBox_category;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_41;
    QLineEdit *product_price;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_42;
    QLineEdit *product_stock;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_43;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_44;
    QPushButton *upload_image_btn;
    QLabel *label_45;
    QWidget *view_products_page;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_4;
    QWidget *changeprofile_setting_page;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_5;
    QWidget *agreement_policy_page;
    QPushButton *pushButton_2;
    QWidget *widget_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;

    void setupUi(QMainWindow *SellerWindow)
    {
        if (SellerWindow->objectName().isEmpty())
            SellerWindow->setObjectName("SellerWindow");
        SellerWindow->resize(1167, 650);
        centralwidget = new QWidget(SellerWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1161, 621));
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1161, 621));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        login_page = new QWidget();
        login_page->setObjectName("login_page");
        login_page->setStyleSheet(QString::fromUtf8("QWidget#login_page{\n"
"background-color: white;\n"
"}"));
        label_5 = new QLabel(login_page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(168, 143, 21, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        login_btn_loginpage = new QPushButton(login_page);
        login_btn_loginpage->setObjectName("login_btn_loginpage");
        login_btn_loginpage->setGeometry(QRect(320, 450, 131, 61));
        login_btn_loginpage->setStyleSheet(QString::fromUtf8("background-color: #BD1616;\n"
"color: #FFFFFF;\n"
"border-radius: 10px;\n"
"font-size: 25px;\n"
"font-weight: bold"));
        label_2 = new QLabel(login_page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 140, 81, 20));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"color: #11405C;"));
        label = new QLabel(login_page);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 10, 501, 51));
        label->setStyleSheet(QString::fromUtf8("color: #BD1616;\n"
"font-size: 35px;\n"
"font-weight: bold;"));
        email_input_login = new QLineEdit(login_page);
        email_input_login->setObjectName("email_input_login");
        email_input_login->setGeometry(QRect(80, 170, 371, 61));
        email_input_login->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #C81818;\n"
"background-color: #FFFFFF;\n"
"font-size: 25px;"));
        password_input_login = new QLineEdit(login_page);
        password_input_login->setObjectName("password_input_login");
        password_input_login->setGeometry(QRect(80, 300, 371, 61));
        password_input_login->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #C81818;\n"
"background-color: #FFFFFF;\n"
"font-size: 25px;"));
        forget_password_btn_login = new QPushButton(login_page);
        forget_password_btn_login->setObjectName("forget_password_btn_login");
        forget_password_btn_login->setGeometry(QRect(80, 370, 171, 31));
        forget_password_btn_login->setStyleSheet(QString::fromUtf8("font-size: 20px;\n"
"color: #11405C;\n"
"font-weight: bold;\n"
"border-width: 1px;\n"
"border-color: red;\n"
"border-radius: 2px;"));
        label_4 = new QLabel(login_page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(205, 273, 63, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        register_btn_loginpage = new QPushButton(login_page);
        register_btn_loginpage->setObjectName("register_btn_loginpage");
        register_btn_loginpage->setGeometry(QRect(80, 450, 131, 61));
        register_btn_loginpage->setStyleSheet(QString::fromUtf8("border-color: #BD1616;\n"
"border-style:solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"font-size: 25px;\n"
"font-weight: bold;"));
        label_3 = new QLabel(login_page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 270, 111, 20));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"color: #11405C;"));
        eyepassword_hide_login = new QPushButton(login_page);
        eyepassword_hide_login->setObjectName("eyepassword_hide_login");
        eyepassword_hide_login->setGeometry(QRect(418, 316, 21, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/sellereyepass/hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        eyepassword_hide_login->setIcon(icon);
        eyepassword_hide_login->setFlat(true);
        eyepassword_view_login = new QPushButton(login_page);
        eyepassword_view_login->setObjectName("eyepassword_view_login");
        eyepassword_view_login->setGeometry(QRect(418, 316, 21, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/sellereyepass/view.png"), QSize(), QIcon::Normal, QIcon::Off);
        eyepassword_view_login->setIcon(icon1);
        eyepassword_view_login->setFlat(true);
        label_35 = new QLabel(login_page);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(510, 60, 651, 471));
        label_35->setPixmap(QPixmap(QString::fromUtf8(":/imgs/seller_login/seller_login_illustration.png")));
        stackedWidget->addWidget(login_page);
        Register_page = new QWidget();
        Register_page->setObjectName("Register_page");
        Register_page->setStyleSheet(QString::fromUtf8("QWidget#Register_page{\n"
"background-color: white;\n"
"}"));
        label_10 = new QLabel(Register_page);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(180, 110, 21, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        label_7 = new QLabel(Register_page);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(380, 10, 501, 51));
        label_7->setStyleSheet(QString::fromUtf8("color: #BD1616;\n"
"font-size: 35px;\n"
"font-weight: bold;"));
        login_btn_rpage = new QPushButton(Register_page);
        login_btn_rpage->setObjectName("login_btn_rpage");
        login_btn_rpage->setGeometry(QRect(200, 540, 121, 61));
        login_btn_rpage->setStyleSheet(QString::fromUtf8("border-color: #BD1616;\n"
"border-style:solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"font-size: 25px;\n"
"font-weight: bold;"));
        fullname_input = new QLineEdit(Register_page);
        fullname_input->setObjectName("fullname_input");
        fullname_input->setGeometry(QRect(260, 100, 361, 41));
        fullname_input->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #C81818;\n"
"background-color: #FFFFFF;\n"
"font-size: 25px;"));
        register_btnn_rpage = new QPushButton(Register_page);
        register_btnn_rpage->setObjectName("register_btnn_rpage");
        register_btnn_rpage->setGeometry(QRect(350, 540, 121, 61));
        register_btnn_rpage->setStyleSheet(QString::fromUtf8("background-color: #BD1616;\n"
"color: #FFFFFF;\n"
"border-radius: 10px;\n"
"font-size: 25px;\n"
"font-weight: bold"));
        label_8 = new QLabel(Register_page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(60, 105, 131, 20));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"color: #11405C;"));
        label_12 = new QLabel(Register_page);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(170, 270, 21, 20));
        label_12->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        label_13 = new QLabel(Register_page);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(240, 320, 21, 20));
        label_13->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        label_9 = new QLabel(Register_page);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(60, 315, 191, 21));
        label_9->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"color: #11405C;"));
        label_11 = new QLabel(Register_page);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(180, 170, 21, 20));
        label_11->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        email_input_register = new QLineEdit(Register_page);
        email_input_register->setObjectName("email_input_register");
        email_input_register->setGeometry(QRect(260, 210, 361, 41));
        email_input_register->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #C81818;\n"
"background-color: #FFFFFF;\n"
"font-size: 25px;"));
        label_14 = new QLabel(Register_page);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(60, 265, 121, 20));
        label_14->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"color: #11405C;"));
        password_input_register = new QLineEdit(Register_page);
        password_input_register->setObjectName("password_input_register");
        password_input_register->setGeometry(QRect(260, 260, 361, 41));
        password_input_register->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #C81818;\n"
"background-color: #FFFFFF;\n"
"font-size: 25px;"));
        label_15 = new QLabel(Register_page);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(60, 215, 81, 20));
        label_15->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"color: #11405C;"));
        phonenumber_register = new QLineEdit(Register_page);
        phonenumber_register->setObjectName("phonenumber_register");
        phonenumber_register->setGeometry(QRect(260, 310, 361, 41));
        phonenumber_register->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #C81818;\n"
"background-color: #FFFFFF;\n"
"font-size: 25px;"));
        day_register = new QLineEdit(Register_page);
        day_register->setObjectName("day_register");
        day_register->setGeometry(QRect(260, 360, 71, 41));
        day_register->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #C81818;\n"
"background-color: #FFFFFF;\n"
"font-size: 20px;"));
        day_register->setAlignment(Qt::AlignCenter);
        month_register = new QLineEdit(Register_page);
        month_register->setObjectName("month_register");
        month_register->setGeometry(QRect(410, 360, 71, 41));
        month_register->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #C81818;\n"
"background-color: #FFFFFF;\n"
"font-size: 20px;"));
        month_register->setAlignment(Qt::AlignCenter);
        year_register = new QLineEdit(Register_page);
        year_register->setObjectName("year_register");
        year_register->setGeometry(QRect(550, 360, 71, 41));
        year_register->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #C81818;\n"
"background-color: #FFFFFF;\n"
"font-size: 20px;"));
        year_register->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(Register_page);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(60, 365, 161, 20));
        label_16->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"color: #11405C;\n"
""));
        label_17 = new QLabel(Register_page);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(800, 450, 21, 20));
        label_17->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        username_input = new QLineEdit(Register_page);
        username_input->setObjectName("username_input");
        username_input->setGeometry(QRect(260, 160, 361, 41));
        username_input->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 10px;\n"
"border-width: 2px;\n"
"border-color: #C81818;\n"
"background-color: #FFFFFF;\n"
"font-size: 25px;"));
        label_21 = new QLabel(Register_page);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(134, 220, 21, 20));
        label_21->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        label_22 = new QLabel(Register_page);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(60, 165, 131, 20));
        label_22->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"color: #11405C;"));
        eyepassword_hide_register = new QPushButton(Register_page);
        eyepassword_hide_register->setObjectName("eyepassword_hide_register");
        eyepassword_hide_register->setGeometry(QRect(590, 265, 21, 31));
        eyepassword_hide_register->setIcon(icon);
        eyepassword_hide_register->setFlat(true);
        eyepassword_view_register = new QPushButton(Register_page);
        eyepassword_view_register->setObjectName("eyepassword_view_register");
        eyepassword_view_register->setGeometry(QRect(590, 265, 21, 31));
        eyepassword_view_register->setIcon(icon1);
        eyepassword_view_register->setFlat(true);
        profile_photo_image = new QPushButton(Register_page);
        profile_photo_image->setObjectName("profile_photo_image");
        profile_photo_image->setGeometry(QRect(260, 462, 141, 31));
        gender_comboBox = new QComboBox(Register_page);
        gender_comboBox->addItem(QString());
        gender_comboBox->addItem(QString());
        gender_comboBox->setObjectName("gender_comboBox");
        gender_comboBox->setGeometry(QRect(260, 420, 81, 31));
        gender_comboBox->setStyleSheet(QString::fromUtf8("background-color: #C81818;\n"
"color : #ffffff;\n"
"font-weight: bold;"));
        label_34 = new QLabel(Register_page);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(60, 415, 101, 20));
        label_34->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"color: #11405C;\n"
""));
        label_36 = new QLabel(Register_page);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(60, 465, 161, 20));
        label_36->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-weight: bold;\n"
"color: #11405C;\n"
""));
        label_37 = new QLabel(Register_page);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(590, 120, 541, 411));
        label_37->setPixmap(QPixmap(QString::fromUtf8(":/imgs/seller_register/seller_register_illustration.png")));
        label_37->setScaledContents(false);
        label_32 = new QLabel(Register_page);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(220, 370, 21, 20));
        label_32->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        label_38 = new QLabel(Register_page);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(150, 420, 21, 20));
        label_38->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-weight:bold;\n"
"font-size: 25px;"));
        checkbox_agreeto_policy = new QCheckBox(Register_page);
        checkbox_agreeto_policy->setObjectName("checkbox_agreeto_policy");
        checkbox_agreeto_policy->setGeometry(QRect(60, 510, 21, 24));
        agreements_btn = new QPushButton(Register_page);
        agreements_btn->setObjectName("agreements_btn");
        agreements_btn->setGeometry(QRect(77, 506, 511, 29));
        agreements_btn->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: #11405C;"));
        agreements_btn->setFlat(true);
        stackedWidget->addWidget(Register_page);
        forget_password = new QWidget();
        forget_password->setObjectName("forget_password");
        id_input_forgot = new QLineEdit(forget_password);
        id_input_forgot->setObjectName("id_input_forgot");
        id_input_forgot->setGeometry(QRect(410, 320, 261, 51));
        id_input_forgot->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border-color: #B6AFAF;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"text-align: center;"));
        id_input_forgot->setAlignment(Qt::AlignCenter);
        newpassword_input = new QLineEdit(forget_password);
        newpassword_input->setObjectName("newpassword_input");
        newpassword_input->setGeometry(QRect(410, 480, 261, 51));
        newpassword_input->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border-color: #B6AFAF;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"text-align: center;"));
        newpassword_input->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(forget_password);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(390, 40, 271, 101));
        label_18->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-weight: bold;\n"
"font-size: 30px;"));
        label_19 = new QLabel(forget_password);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(570, 100, 31, 41));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/imgs/home/seller_forget.png")));
        label_19->setScaledContents(true);
        label_20 = new QLabel(forget_password);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(410, 170, 241, 61));
        label_20->setStyleSheet(QString::fromUtf8("color: grey;\n"
"font-weight: bold;\n"
"font-size: 16px;"));
        confirmnewpassword_btn = new QPushButton(forget_password);
        confirmnewpassword_btn->setObjectName("confirmnewpassword_btn");
        confirmnewpassword_btn->setGeometry(QRect(430, 540, 211, 41));
        confirmnewpassword_btn->setStyleSheet(QString::fromUtf8("border-radius: 17px;\n"
"background-color: #BD1616 ;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"color: white;"));
        verifyidentity = new QPushButton(forget_password);
        verifyidentity->setObjectName("verifyidentity");
        verifyidentity->setGeometry(QRect(700, 320, 211, 41));
        verifyidentity->setStyleSheet(QString::fromUtf8("border-radius: 17px;\n"
"background-color: #BD1616 ;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"color: white;"));
        email_input_forgot = new QLineEdit(forget_password);
        email_input_forgot->setObjectName("email_input_forgot");
        email_input_forgot->setGeometry(QRect(410, 250, 261, 51));
        email_input_forgot->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border-color: #B6AFAF;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"text-align: center;"));
        email_input_forgot->setAlignment(Qt::AlignCenter);
        username_input_forgot = new QLineEdit(forget_password);
        username_input_forgot->setObjectName("username_input_forgot");
        username_input_forgot->setGeometry(QRect(410, 390, 261, 51));
        username_input_forgot->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border-color: #B6AFAF;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"text-align: center;"));
        username_input_forgot->setAlignment(Qt::AlignCenter);
        eyepassword_view_forget = new QPushButton(forget_password);
        eyepassword_view_forget->setObjectName("eyepassword_view_forget");
        eyepassword_view_forget->setGeometry(QRect(644, 492, 21, 31));
        eyepassword_view_forget->setIcon(icon1);
        eyepassword_view_forget->setFlat(true);
        eyepassword_hide_forget = new QPushButton(forget_password);
        eyepassword_hide_forget->setObjectName("eyepassword_hide_forget");
        eyepassword_hide_forget->setGeometry(QRect(644, 492, 21, 31));
        eyepassword_hide_forget->setIcon(icon);
        eyepassword_hide_forget->setFlat(true);
        back_btn = new QPushButton(forget_password);
        back_btn->setObjectName("back_btn");
        back_btn->setGeometry(QRect(990, 550, 161, 31));
        back_btn->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: white;\n"
"background-color: black;\n"
"border-radius: 3px;"));
        stackedWidget->addWidget(forget_password);
        id_input_forgot->raise();
        newpassword_input->raise();
        label_18->raise();
        label_19->raise();
        label_20->raise();
        confirmnewpassword_btn->raise();
        verifyidentity->raise();
        email_input_forgot->raise();
        username_input_forgot->raise();
        eyepassword_hide_forget->raise();
        eyepassword_view_forget->raise();
        back_btn->raise();
        home_page = new QWidget();
        home_page->setObjectName("home_page");
        frame = new QFrame(home_page);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1161, 621));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 1161, 71));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame#frame_2{\n"
"\n"
"background-color: white;\n"
"border-bottom-style: solid;\n"
"border-bottom-color: rgb(170, 0, 0);\n"
"border-bottom-width: 5px;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_29 = new QLabel(frame_2);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(30, 10, 221, 51));
        label_29->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font-size: 35px;\n"
"color: #BD1616;\n"
""));
        add_product = new QPushButton(frame_2);
        add_product->setObjectName("add_product");
        add_product->setGeometry(QRect(418, 30, 111, 29));
        add_product->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-weight: bold;\n"
""));
        add_product->setFlat(true);
        profile_stting_btn = new QPushButton(frame_2);
        profile_stting_btn->setObjectName("profile_stting_btn");
        profile_stting_btn->setGeometry(QRect(730, 30, 111, 29));
        profile_stting_btn->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-weight: bold;\n"
""));
        profile_stting_btn->setFlat(true);
        view_products = new QPushButton(frame_2);
        view_products->setObjectName("view_products");
        view_products->setGeometry(QRect(568, 30, 131, 29));
        view_products->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-weight: bold;\n"
""));
        view_products->setFlat(true);
        label_30 = new QLabel(frame_2);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(912, 30, 121, 20));
        label_30->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font-size: 15px;\n"
"color: #BD1616;\n"
""));
        acc_balance_value = new QLabel(frame_2);
        acc_balance_value->setObjectName("acc_balance_value");
        acc_balance_value->setGeometry(QRect(1040, 30, 81, 20));
        acc_balance_value->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font-size: 15px;\n"
"color: #BD1616;\n"
""));
        home_btn = new QPushButton(frame_2);
        home_btn->setObjectName("home_btn");
        home_btn->setGeometry(QRect(298, 30, 111, 29));
        home_btn->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-weight: bold;\n"
""));
        home_btn->setFlat(true);
        stackedWidget_2 = new QStackedWidget(frame);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, 70, 1161, 541));
        home_pagee = new QWidget();
        home_pagee->setObjectName("home_pagee");
        home_pagee->setStyleSheet(QString::fromUtf8("QWidget#home_pagee{\n"
"background-image: url(:/imgs/seller_home/seller_background_home.png);\n"
"} /*for making its children not inherit anything*/"));
        label_23 = new QLabel(home_pagee);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(500, 110, 211, 61));
        label_23->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font-size: 50px;\n"
"color: #000000;\n"
""));
        label_24 = new QLabel(home_pagee);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(410, 200, 191, 61));
        label_24->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font-size: 50px;\n"
"color: #BD1616;\n"
""));
        label_25 = new QLabel(home_pagee);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(620, 200, 191, 61));
        label_25->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font-size: 50px;\n"
"color: #11405C;\n"
""));
        label_26 = new QLabel(home_pagee);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(520, 280, 181, 71));
        label_26->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font-size: 50px;\n"
"color: #000000;\n"
""));
        label_27 = new QLabel(home_pagee);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(380, 370, 471, 81));
        label_27->setStyleSheet(QString::fromUtf8("font-weight: light;\n"
"font: 350 13pt \"Segoe UI\";"));
        add_products_now = new QPushButton(home_pagee);
        add_products_now->setObjectName("add_products_now");
        add_products_now->setGeometry(QRect(490, 460, 251, 51));
        add_products_now->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: white;\n"
"font-size: 20px;\n"
"\n"
"background-color: #BD1616;\n"
"border-radius: 8px;"));
        add_products_now->setFlat(true);
        label_28 = new QLabel(home_pagee);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(430, 20, 191, 61));
        label_28->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: white;\n"
"font-size: 40px;\n"
""));
        name_of_seller = new QLabel(home_pagee);
        name_of_seller->setObjectName("name_of_seller");
        name_of_seller->setGeometry(QRect(620, 20, 521, 61));
        name_of_seller->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: white;\n"
"font-size: 40px;\n"
""));
        logout = new QPushButton(home_pagee);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(10, 490, 93, 31));
        logout->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: white;\n"
"background-color: black;\n"
"font-size: 20px;\n"
"border-radius: 4px;"));
        logout->setFlat(true);
        stackedWidget_2->addWidget(home_pagee);
        add_product_page = new QWidget();
        add_product_page->setObjectName("add_product_page");
        widget_4 = new QWidget(add_product_page);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 0, 1161, 551));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget#widget_4{\n"
"\n"
"	background-image: url(:/imgs/seller_home/add_product_background.png);\n"
"	background-position: center;\n"
"\n"
"background-repeat: no-repeat;\n"
"}"));
        layoutWidget_2 = new QWidget(widget_4);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(270, 30, 621, 481));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        addproduct_btn = new QPushButton(layoutWidget_2);
        addproduct_btn->setObjectName("addproduct_btn");
        addproduct_btn->setMinimumSize(QSize(0, 80));
        addproduct_btn->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: white;\n"
"background-color: #BD1616;\n"
"border-radius: 5px;\n"
"font-size: 30px;"));

        gridLayout_3->addWidget(addproduct_btn, 5, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_39 = new QLabel(layoutWidget_2);
        label_39->setObjectName("label_39");
        label_39->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: #11405C;\n"
"font-size: 25px;"));

        horizontalLayout_7->addWidget(label_39);

        product_name = new QLineEdit(layoutWidget_2);
        product_name->setObjectName("product_name");
        product_name->setMinimumSize(QSize(0, 30));
        product_name->setMaximumSize(QSize(500, 16777215));

        horizontalLayout_7->addWidget(product_name);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_40 = new QLabel(layoutWidget_2);
        label_40->setObjectName("label_40");
        label_40->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: #11405C;\n"
"font-size: 25px;"));

        horizontalLayout_8->addWidget(label_40);

        comboBox_category = new QComboBox(layoutWidget_2);
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->setObjectName("comboBox_category");
        comboBox_category->setMinimumSize(QSize(0, 30));
        comboBox_category->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: white;\n"
"font-size: 20px;\n"
"background-color: #BD1616"));

        horizontalLayout_8->addWidget(comboBox_category);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_41 = new QLabel(layoutWidget_2);
        label_41->setObjectName("label_41");
        label_41->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: #11405C;\n"
"font-size: 25px;"));

        horizontalLayout_9->addWidget(label_41);

        product_price = new QLineEdit(layoutWidget_2);
        product_price->setObjectName("product_price");
        product_price->setMinimumSize(QSize(0, 30));
        product_price->setMaximumSize(QSize(500, 16777215));
        product_price->setMaxLength(4);

        horizontalLayout_9->addWidget(product_price);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_42 = new QLabel(layoutWidget_2);
        label_42->setObjectName("label_42");
        label_42->setMinimumSize(QSize(100, 0));
        label_42->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: #11405C;\n"
"font-size: 25px;"));
        label_42->setScaledContents(false);

        horizontalLayout_10->addWidget(label_42);

        product_stock = new QLineEdit(layoutWidget_2);
        product_stock->setObjectName("product_stock");
        product_stock->setMinimumSize(QSize(0, 30));
        product_stock->setMaximumSize(QSize(500, 16777215));
        product_stock->setMaxLength(3);

        horizontalLayout_10->addWidget(product_stock);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_43 = new QLabel(layoutWidget_2);
        label_43->setObjectName("label_43");
        label_43->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: #11405C;\n"
"font-size: 25px;"));

        horizontalLayout_11->addWidget(label_43);

        dateEdit = new QDateEdit(layoutWidget_2);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout_11->addWidget(dateEdit);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_44 = new QLabel(layoutWidget_2);
        label_44->setObjectName("label_44");
        label_44->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: #11405C;\n"
"font-size: 25px;"));

        horizontalLayout_12->addWidget(label_44);

        upload_image_btn = new QPushButton(layoutWidget_2);
        upload_image_btn->setObjectName("upload_image_btn");
        upload_image_btn->setMinimumSize(QSize(0, 30));

        horizontalLayout_12->addWidget(upload_image_btn);


        verticalLayout_2->addLayout(horizontalLayout_12);


        gridLayout_3->addLayout(verticalLayout_2, 1, 1, 1, 1);

        label_45 = new QLabel(layoutWidget_2);
        label_45->setObjectName("label_45");
        label_45->setMinimumSize(QSize(0, 0));
        label_45->setMaximumSize(QSize(16777215, 100));
        label_45->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font-size: 50px;\n"
""));
        label_45->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_45, 0, 1, 1, 1);

        stackedWidget_2->addWidget(add_product_page);
        view_products_page = new QWidget();
        view_products_page->setObjectName("view_products_page");
        scrollArea_3 = new QScrollArea(view_products_page);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setGeometry(QRect(0, 0, 1161, 551));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 1159, 549));
        scrollArea_3->setWidget(scrollAreaWidgetContents_4);
        stackedWidget_2->addWidget(view_products_page);
        changeprofile_setting_page = new QWidget();
        changeprofile_setting_page->setObjectName("changeprofile_setting_page");
        scrollArea_4 = new QScrollArea(changeprofile_setting_page);
        scrollArea_4->setObjectName("scrollArea_4");
        scrollArea_4->setGeometry(QRect(0, 0, 1161, 551));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName("scrollAreaWidgetContents_5");
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 1159, 549));
        scrollArea_4->setWidget(scrollAreaWidgetContents_5);
        stackedWidget_2->addWidget(changeprofile_setting_page);
        stackedWidget->addWidget(home_page);
        agreement_policy_page = new QWidget();
        agreement_policy_page->setObjectName("agreement_policy_page");
        agreement_policy_page->setStyleSheet(QString::fromUtf8("QWidget#agreement_policy_page{\n"
"background-color: white;\n"
"}"));
        pushButton_2 = new QPushButton(agreement_policy_page);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 560, 181, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: white;\n"
"background-color: black;\n"
"border-radius: 3px;\n"
"font-size: 25px;"));
        widget_2 = new QWidget(agreement_policy_page);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(190, 40, 771, 511));
        scrollArea = new QScrollArea(widget_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 771, 511));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 769, 509));
        textBrowser = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(0, 0, 771, 511));
        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(agreement_policy_page);
        SellerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SellerWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1167, 26));
        SellerWindow->setMenuBar(menubar);

        retranslateUi(SellerWindow);

        QMetaObject::connectSlotsByName(SellerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SellerWindow)
    {
        SellerWindow->setWindowTitle(QCoreApplication::translate("SellerWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("SellerWindow", "*", nullptr));
        login_btn_loginpage->setText(QCoreApplication::translate("SellerWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("SellerWindow", "E-mail", nullptr));
        label->setText(QCoreApplication::translate("SellerWindow", "Supermarket online shopping", nullptr));
        forget_password_btn_login->setText(QCoreApplication::translate("SellerWindow", "Forgot password?", nullptr));
        label_4->setText(QCoreApplication::translate("SellerWindow", "*", nullptr));
        register_btn_loginpage->setText(QCoreApplication::translate("SellerWindow", "Register", nullptr));
        label_3->setText(QCoreApplication::translate("SellerWindow", "Password", nullptr));
        eyepassword_hide_login->setText(QString());
        eyepassword_view_login->setText(QString());
        label_35->setText(QString());
        label_10->setText(QCoreApplication::translate("SellerWindow", "*", nullptr));
        label_7->setText(QCoreApplication::translate("SellerWindow", "Supermarket online Shopping", nullptr));
        login_btn_rpage->setText(QCoreApplication::translate("SellerWindow", "Login", nullptr));
        register_btnn_rpage->setText(QCoreApplication::translate("SellerWindow", "Register", nullptr));
        label_8->setText(QCoreApplication::translate("SellerWindow", "Full Name", nullptr));
        label_12->setText(QCoreApplication::translate("SellerWindow", "*", nullptr));
        label_13->setText(QCoreApplication::translate("SellerWindow", "*", nullptr));
        label_9->setText(QCoreApplication::translate("SellerWindow", "Phone Number", nullptr));
        label_11->setText(QCoreApplication::translate("SellerWindow", "*", nullptr));
        label_14->setText(QCoreApplication::translate("SellerWindow", "Password", nullptr));
        label_15->setText(QCoreApplication::translate("SellerWindow", "E-mail", nullptr));
        day_register->setPlaceholderText(QCoreApplication::translate("SellerWindow", "Day", nullptr));
        month_register->setPlaceholderText(QCoreApplication::translate("SellerWindow", "Month", nullptr));
        year_register->setPlaceholderText(QCoreApplication::translate("SellerWindow", "Year", nullptr));
        label_16->setText(QCoreApplication::translate("SellerWindow", "Date Of Birth", nullptr));
        label_17->setText(QCoreApplication::translate("SellerWindow", "*", nullptr));
        label_21->setText(QCoreApplication::translate("SellerWindow", "*", nullptr));
        label_22->setText(QCoreApplication::translate("SellerWindow", "Username", nullptr));
        eyepassword_hide_register->setText(QString());
        eyepassword_view_register->setText(QString());
        profile_photo_image->setText(QCoreApplication::translate("SellerWindow", "upload your photo", nullptr));
        gender_comboBox->setItemText(0, QCoreApplication::translate("SellerWindow", "male", nullptr));
        gender_comboBox->setItemText(1, QCoreApplication::translate("SellerWindow", "female", nullptr));

        label_34->setText(QCoreApplication::translate("SellerWindow", "Gender", nullptr));
        label_36->setText(QCoreApplication::translate("SellerWindow", "Profile Photo", nullptr));
        label_37->setText(QString());
        label_32->setText(QCoreApplication::translate("SellerWindow", "*", nullptr));
        label_38->setText(QCoreApplication::translate("SellerWindow", "*", nullptr));
        checkbox_agreeto_policy->setText(QString());
        agreements_btn->setText(QCoreApplication::translate("SellerWindow", "I agree to the terms of supermarket seller agreement and privacy policy", nullptr));
        id_input_forgot->setText(QString());
        id_input_forgot->setPlaceholderText(QCoreApplication::translate("SellerWindow", "Enter your ID ...", nullptr));
        newpassword_input->setText(QString());
        newpassword_input->setPlaceholderText(QCoreApplication::translate("SellerWindow", "Enter New Password", nullptr));
#if QT_CONFIG(whatsthis)
        label_18->setWhatsThis(QCoreApplication::translate("SellerWindow", "<html><head/><body><p align=\"center\">Enter your</p><p align=\"center\">Verification code</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_18->setText(QCoreApplication::translate("SellerWindow", "<html><head/><body><p align=\"center\">Forgot Password</p><p align=\"center\">Page</p></body></html>", nullptr));
        label_19->setText(QString());
        label_20->setText(QCoreApplication::translate("SellerWindow", "<html><head/><body><p align=\"center\">Enter Your ID</p><p align=\"center\">to make new password</p></body></html>", nullptr));
        confirmnewpassword_btn->setText(QCoreApplication::translate("SellerWindow", "Confirm", nullptr));
        verifyidentity->setText(QCoreApplication::translate("SellerWindow", "Verify your identity", nullptr));
        email_input_forgot->setText(QString());
        email_input_forgot->setPlaceholderText(QCoreApplication::translate("SellerWindow", "Enter Your Email...", nullptr));
        username_input_forgot->setText(QString());
        username_input_forgot->setPlaceholderText(QCoreApplication::translate("SellerWindow", "Enter your Username ...", nullptr));
        eyepassword_view_forget->setText(QString());
        eyepassword_hide_forget->setText(QString());
        back_btn->setText(QCoreApplication::translate("SellerWindow", "Back", nullptr));
        label_29->setText(QCoreApplication::translate("SellerWindow", "Supermarket", nullptr));
        add_product->setText(QCoreApplication::translate("SellerWindow", "Add Product", nullptr));
        profile_stting_btn->setText(QCoreApplication::translate("SellerWindow", "Profile Setting", nullptr));
        view_products->setText(QCoreApplication::translate("SellerWindow", "view my products", nullptr));
        label_30->setText(QCoreApplication::translate("SellerWindow", "Account Balance:", nullptr));
        acc_balance_value->setText(QString());
        home_btn->setText(QCoreApplication::translate("SellerWindow", "HOME", nullptr));
        label_23->setText(QCoreApplication::translate("SellerWindow", "Get Your", nullptr));
        label_24->setText(QCoreApplication::translate("SellerWindow", "Product", nullptr));
        label_25->setText(QCoreApplication::translate("SellerWindow", "A Buyer", nullptr));
        label_26->setText(QCoreApplication::translate("SellerWindow", "Quickly", nullptr));
        label_27->setText(QCoreApplication::translate("SellerWindow", "<html><head/><body><p>we provide you the best way to sell your products</p><p align=\"center\">whatever it is</p></body></html>", nullptr));
        add_products_now->setText(QCoreApplication::translate("SellerWindow", "Add your product now", nullptr));
        label_28->setText(QCoreApplication::translate("SellerWindow", "Welcome,", nullptr));
        name_of_seller->setText(QString());
        logout->setText(QCoreApplication::translate("SellerWindow", "logout", nullptr));
        addproduct_btn->setText(QCoreApplication::translate("SellerWindow", "Add Product", nullptr));
        label_39->setText(QCoreApplication::translate("SellerWindow", "Name", nullptr));
        label_40->setText(QCoreApplication::translate("SellerWindow", "Category", nullptr));
        comboBox_category->setItemText(0, QCoreApplication::translate("SellerWindow", "Electronics", nullptr));
        comboBox_category->setItemText(1, QCoreApplication::translate("SellerWindow", "VideoGames", nullptr));
        comboBox_category->setItemText(2, QCoreApplication::translate("SellerWindow", "Groceries", nullptr));
        comboBox_category->setItemText(3, QCoreApplication::translate("SellerWindow", "Office", nullptr));
        comboBox_category->setItemText(4, QCoreApplication::translate("SellerWindow", "Beauty", nullptr));
        comboBox_category->setItemText(5, QCoreApplication::translate("SellerWindow", "HomeFurniture", nullptr));
        comboBox_category->setItemText(6, QCoreApplication::translate("SellerWindow", "SportsSupplies", nullptr));

        label_41->setText(QCoreApplication::translate("SellerWindow", "Price", nullptr));
        label_42->setText(QCoreApplication::translate("SellerWindow", "Stock", nullptr));
        label_43->setText(QCoreApplication::translate("SellerWindow", "Expiration date", nullptr));
        label_44->setText(QCoreApplication::translate("SellerWindow", "Image of product", nullptr));
        upload_image_btn->setText(QCoreApplication::translate("SellerWindow", "choose file..", nullptr));
        label_45->setText(QCoreApplication::translate("SellerWindow", "Add Product", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SellerWindow", "Back", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("SellerWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">We collect your personal information in order to provide and continually improve our products and services.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Here a"
                        "re the types of personal information we collect:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Information You Give Us: We receive and store any information you provide in relation to Supermarket Services. Click here to see examples of what we collect. You can choose not to provide certain information, but then you might not be able to take advantage of many of our Supermarket Services.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Automatic Information: We automatically collect and store certain types of information about your use of Supermarket Services, including information about your interaction with products, content, and services available through Supermarket Services. Like many web"
                        "sites, we use &quot;cookies&quot; and other unique identifiers, and we obtain certain types of information when your web browser or device accesses Supermarket Services and other content served by or on behalf of Supermarket on other websites. Our physical stores may use cameras, computer vision, sensors, and other technology to gather information about your activity in the store, such as the products and services you interact with. Click here to see examples of what we collect.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Information from Other Sources: We might receive information about you from other sources, such as updated delivery and address information from our carriers, which we use to correct our records and deliver your next purchase more easily. Click here to see additional examples of the information we receive.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inde"
                        "nt:0; text-indent:0px;\">For What Purposes Does Supermarket Use Your Personal Information?</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">We use your personal information to operate, provide, develop, and improve the products and services that we offer our customers. These purposes include:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Purchase and delivery of products and services. We use your personal information to take and handle orders, deliver products and services, process payments, and communicate with you about orders, products and services, and promotional offers.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-ind"
                        "ent:0px;\">Provide, troubleshoot, and improve Supermarket Services. We use your personal information to provide functionality, analyze performance, fix errors, and improve the usability and effectiveness of the Supermarket Services.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Recommendations and personalization. We use your personal information to recommend features, products, and services that might be of interest to you, identify your preferences, and personalize your experience with Supermarket Services.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Provide voice, image and camera services. When you use our voice, image and camera services, we use your voice input, images, videos, and other personal information to respond to your requests, provide the requested service to you, and improve our services. For more information about Alexa voice s"
                        "ervices , click here.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Comply with legal obligations. In certain cases, we collect and use your personal information to comply with laws. For instance, we collect from sellers information regarding place of establishment and bank account information for identity verification and other purposes.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Communicate with you. We use your personal information to communicate with you in relation to Supermarket Services via different channels (e.g., by phone, email, chat).</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Advertising. We use your personal information to display interest-based ads for features, products, and services that might be of interest to you. We do not use information t"
                        "hat personally identifies you to display interest-based ads. To learn more, please read our Interest-Based Ads notice.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Fraud Prevention and Credit Risks. We use personal information to prevent and detect fraud and abuse in order to protect the security of our customers, Supermarket, and others. We may also use scoring methods to assess and manage credit risks.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">What About Cookies and Other Identifiers?</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">To enable our systems to recognize your browser or device and to provide and improve Supermarket Services, we use cookies and other identifiers. For more information about cookies and how we use them, please read our Cookies Notice.<"
                        "/p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Does Supermarket Share Your Personal Information?</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Information about our customers is an important part of our business, and we are not in the business of selling our customers' personal information to others. We share customers' personal information only as described below and with subsidiaries Supermarket.com, Inc. controls that either are subject to this Privacy Notice or follow practices at least as protective as those described in this Privacy Notice.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent"
                        ":0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Transactions involving Third Parties: We make available to you services, products, applications, or skills provided by third parties for use on or through Supermarket Services. For example, you can order products from third parties through our stores, download applications from third-party application providers from our App Store, and enable third-party skills through our Alexa services. We also offer services or sell product lines jointly with third-party businesses, such as co-branded credit cards. You can tell when a third party is involved in your transactions, and we share customers' personal information related to those transactions with that third party.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Third-Party Service Providers: We employ other companies and individuals to perfor"
                        "m functions on our behalf. Examples include fulfilling orders for products or services, delivering packages, sending postal mail and email, removing repetitive information from customer lists, analyzing data, providing marketing assistance, providing search results and links (including paid listings and links), processing payments, transmitting content, scoring, assessing and managing credit risk, and providing customer service. These third-party service providers have access to personal information needed to perform their functions, but may not use it for other purposes.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Business Transfers: As we continue to develop our business, we might sell or buy other businesses or services. In such transactions, customer information generally is one of the transferred business assets but remains subject to the promises made in any pre-existing Privacy Notice (unless, of course, the customer co"
                        "nsents otherwise). Also, in the unlikely event that Supermarket.com, Inc. or substantially all of its assets are acquired, customer information will of course be one of the transferred assets.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Protection of Supermarket and Others: We release account and other personal information when we believe release is appropriate to comply with the law; enforce or apply our Conditions of Use and other agreements; or protect the rights, property, or safety of Supermarket, our users, or others. This includes exchanging information with other companies and organizations for fraud protection and credit risk reduction.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Other than as set out above, you will receive notice when personal information about you might be shared with third parties, and you will have an opportunity"
                        " to choose not to share the information.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">How Secure Is Information About Me?</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">We design our systems with your security and privacy in mind.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">We work to protect the security of your personal information during transmission by using encryption protocols and software.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0p"
                        "x; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">We follow the Payment Card Industry Data Security Standard (PCI DSS) when handling credit card data.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">We maintain physical, electronic, and procedural safeguards in connection with the collection, storage, and disclosure of customer personal information. Our security procedures mean that we may ask to verify your identity before we disclose personal information to you.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Our devices offer security features to protect them against unauthorized access and loss of data. You can control these features and configure them based on your needs. Click here for more information on how to manage the security settings of your device.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-l"
                        "eft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">It is important for you to protect against unauthorized access to your password and to your computers, devices, and applications. We recommend using a unique password for your Supermarket account that is not used for other online accounts. Be sure to sign off when finished using a shared computer. Click here for more information on how to sign off.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">What About Advertising?</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Third-Party Advertisers and Links to Other Websites: Supermarket Services may include third-party advertising and links to other websites and apps. Third-party advertising partners may collect information about you when you interact with their content, advertising, and services. For more information about third-party adverti"
                        "sing at Supermarket, including interest-based ads, please read our Interest-Based Ads notice. To adjust your advertising preferences, please go to the Your Ads Privacy Choices page.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Use of Third-Party Advertising Services: We provide ad companies with information that allows them to serve you with more useful and relevant Supermarket ads and to measure their effectiveness. We never share your name or other information that directly identifies you when we do this. Instead, we use an advertising identifier like a cookie, a device identifier, or a code derived from applying irreversible cryptography to other information like an email address. For example, if you have already downloaded one of our apps, we will share your advertising identifier and data about that event so that you will not be served an ad to download the app again. While we do not share your specific shopping actions li"
                        "ke purchases, product views, or searches with ad companies, we may share an advertising identifier and an estimate of the value of the ads they show you on our behalf so they can serve you with more effective Supermarket ads. Some ad companies also use this information to serve you relevant ads from other advertisers. You can learn more about how to opt-out of personalized advertising (such as cross-context behavioral advertising) by going to the Your Ads Privacy Choices page.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">What Information Can I Access?</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You can access your information, including your name, address, payment options, profile information, Prime membership, household settings, and purchase history in the &quot;Your Account&quot; section of the website. Click here for a list of examples that"
                        " you can access.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">What Choices Do I Have?</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you have any questions as to how we collect and use your personal information, please contact our Customer Service. Many of our Supermarket Services also include settings that provide you with options as to how your information is being used.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">As described above, you can c"
                        "hoose not to provide certain information, but then you might not be able to take advantage of many of the Supermarket Services.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You can add or update certain information on pages such as those referenced in What Information Can I Access?. When you update information, we usually keep a copy of the prior version for our records.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you do not want to receive email or other communications from us, please adjust your Customer Communication Preferences. If you don't want to receive in-app notifications from us, please adjust your notification settings in the app or device.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You may adjust your personalized advertising preferences by vis"
                        "iting Your Ads Privacy Choices.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The Help feature on most browsers and devices will tell you how to prevent your browser or device from accepting new cookies or other identifiers, how to have the browser notify you when you receive a new cookie, or how to block cookies altogether. Because cookies and identifiers allow you to take advantage of some essential features of Supermarket Services, we recommend that you leave them turned on. For instance, if you block or otherwise reject our cookies, you will not be able to add items to your Shopping Cart, proceed to Checkout, or use any Services that require you to Sign in. For more information about cookies and other identifiers, see our Cookies Notice.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you want to browse our websites without linking the browsi"
                        "ng history to your account, you may do so by logging out of your account here and blocking cookies on your browser.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You can manage the recommendations you receive in our store here, remove recommendations you don\342\200\231t want to see here by selecting View All and Manage then selecting the Remove Items toggle that appears at the top of the page, and edit your browsing history here.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You will also be able to opt out of certain other types of data usage by updating your settings on the applicable Supermarket website (e.g., in &quot;Manage Your Content and Devices&quot;), device, or application. For more information click here. Most non-Supermarket devices also provide users with the ability to change device permissions (e.g., disable/access location servic"
                        "es, contacts). For most devices, these controls are located in the device's settings menu. If you have questions about how to change your device permissions on devices manufactured by third parties, we recommend you contact your mobile service carrier or your device manufacturer.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you are a seller, you can add or update certain information in Seller Central, update your account information by accessing your Seller Account Information, and adjust your email or other communications you receive from us by updating your Notification Preferences.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you are an author, you can add or update the information you have provided in the Author Portal and Author Central by accessing your accounts in the Author Portal and Author Central, respectively.</p>\n"
"<p style="
                        "\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you shop in our physical stores, you can manage how certain data is used to analyze the performance of our products and services, as well as learn more here.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">In addition, to the extent required by applicable law, you may have the right to request access to or delete your personal information. If you wish to do any of these things, you may go to Data Privacy Queries. Depending on your data choices, certain services may be limited or unavailable.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Are Children Allowed to Use Supermarket Se"
                        "rvices?</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Supermarket does not sell products for purchase by children. We sell children's products for purchase by adults. If you are under 18, you may use Supermarket Services only with the involvement of a parent or guardian. We do not knowingly collect personal information from children under the age of 13 without the consent of the child's parent or guardian. For more information, please see our Children's Privacy Disclosure.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">EU-US and Swiss-US Privacy Shield</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Supermarket"
                        ".com, Inc. participates in the EU-US and Swiss-US Privacy Shield frameworks. Click here to learn more.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Additional State-Specific Privacy Disclosures</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Click here to read additional state-specific privacy disclosures as required under applicable laws.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Conditions of Use, Notices, and Revisions</p>\n"
"<p style=\" margi"
                        "n-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you choose to use Supermarket Services, your use and any dispute over privacy is subject to this Notice and our Conditions of Use, including limitations on damages, resolution of disputes, and application of the law of the state of Washington. If you have any concern about privacy at Supermarket, please contact us with a thorough description, and we will try to resolve it. Our business changes constantly, and our Privacy Notice will change also. You should check our websites frequently to see recent changes. Unless stated otherwise, our current Privacy Notice applies to all information that we have about you and your account. We stand behind the promises we make, however, and will never materially change our policies and practices to make them less protective of customer information collected in the past without the consent of affected customers.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px"
                        "; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Related Practices and Information</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Conditions of Use</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Seller Program Policies</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Help pages</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Most Recent Purchases</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Community Guidelines</p>\n"
"<p style=\""
                        " margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Examples of Information Collected</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Information You Give Us When You Use Supermarket Services</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You provide information to us when you:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">search or shop for products or services in our stores;</p>\n"
"<p style=\""
                        " margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">add or remove an item from your cart, or place an order through or use Supermarket Services;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">download, stream, view, or use content on a device or through a service or application on a device;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">provide information in Your Account (and you might have more than one if you have used more than one email address or mobile number when shopping with us) or Your Profile ;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">talk to or otherwise interact with our Alexa Voice service;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-in"
                        "dent:0; text-indent:0px;\">upload your contacts;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">configure your settings on, provide data access permissions for, or interact with an Supermarket device or service;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">provide information in your Seller Account , Kindle Direct Publishing account , Developer account , or any other account we make available that allows you to develop or offer software, goods, or services to Supermarket customers;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">offer your products or services on or through Supermarket Services;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">communicate with us by phone, email, or otherw"
                        "ise;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">complete a questionnaire, a support ticket, or a contest entry form;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">upload or stream images, videos or other files to Prime Photos, Supermarket Drive, or other Supermarket Services;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">use our services such as Prime Video;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">compile Playlists, Watchlists, Wish Lists or other gift registries;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">participate in Discussion Boards or other community features;</p>\n"
"<p style=\" marg"
                        "in-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">provide and rate Reviews;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">specify a Special Occasion Reminder; or</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">employ Product Availability Alerts , such as Available to Order Notifications.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">As a result of those actions, you might supply us with such information as:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">identifying informatio"
                        "n such as your name, address, and phone numbers;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">payment information;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">your age;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">your location information;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">your IP address;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">people, addresses and phone numbers listed in your Addresses;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">email addresses of your friends and other people;</p>\n"
"<p styl"
                        "e=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">content of reviews and emails to us;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">personal description and photograph in Your Profile;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">voice recordings when you speak to Alexa;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">images and videos collected or stored in connection with Supermarket Services;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">information and documents regarding identity, including Social Security and driver's license numbers;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-rig"
                        "ht:0px; -qt-block-indent:0; text-indent:0px;\">corporate and financial information;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">credit history information; and</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">device log files and configurations, including Wi-Fi credentials, if you choose to automatically synchronize them with your other Supermarket devices.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Automatic Information</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Examples of the information we collect and analyze include:"
                        "</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">the internet protocol (IP) address used to connect your computer to the internet;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">login, email address, and password;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">the location of your device or computer;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">content interaction information, such as content downloads, streams, and playback details, including duration and number of simultaneous streams and downloads, and network details for stre"
                        "aming and download quality, including information about your internet service provider;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">device metrics such as when a device is in use, application usage, connectivity data, and any errors or event failures;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Supermarket Services metrics (e.g., the occurrences of technical errors, your interactions with service features and content, your settings preferences and backup information, location of your device running an application, information about uploaded images and files such as the file name, dates, times and location of your images);</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">version and time zone settings;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">purchase and content use history, which we sometimes aggregate with similar information from other customers to create features like Top Sellers;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">the full Uniform Resource Locator (URL) clickstream to, through, and from our websites, including date and time; products and content you viewed or searched for; page response times, download errors, length of visits to certain pages, and page interaction information (such as scrolling, clicks, and mouse-overs);</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">phone numbers used to call our customer service number; and</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">images or videos when you shop in our stores, or stor"
                        "es using Supermarket Services.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">We may also use device identifiers, cookies, and other technologies on devices, applications, and our web pages to collect browsing, usage, or other technical information.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Information from Other Sources</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Examples of information we receive from other sources include:</p>\n"
"<p style=\""
                        "-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">updated delivery and address information from our carriers or other third parties, which we use to correct our records and deliver your next purchase or communication more easily;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">account information, purchase or redemption information, and page-view information from some merchants with which we operate co-branded businesses or for which we provide technical, fulfillment, advertising, or other services;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">information about your interactions with products and services offered by our subsidiarie"
                        "s;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">search results and links, including paid listings (such as Sponsored Links);</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">information about internet-connected devices and services linked with Alexa; and</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">credit history information from credit bureaus, which we use to help prevent and detect fraud and to offer certain credit or financial services to some customers.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Information You Can Access</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br "
                        "/></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Examples of information you can access through Supermarket Services include:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">status of recent orders (including subscriptions);</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">your complete order history;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">personally identifiable information (including name, email, password, and address book);</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block"
                        "-indent:0; text-indent:0px;\">payment settings (including payment card information, promotional certificate and gift card balances, and 1-Click settings);</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">email notification settings (including Product Availability Alerts, Delivers, Special Occasion Reminders and newsletters);</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">recommendations and the products you recently viewed that are the basis for recommendations (including Recommended for You and Improve Your Recommendations);</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">shopping lists and gift registries (including Wish Lists and Baby and Wedding Registries);</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; t"
                        "ext-indent:0px;\">your content, devices, services, and related settings, and communications and personalized advertising preferences;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">content that you recently viewed;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">voice recordings associated with your account;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Your Profile (including your product Reviews, Recommendations, Reminders and personal profile);</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you are a seller, you can access your account and other information, and adjust your communications preferences, by updating your account in Seller Central.</p>\n"
"<p style=\" margin-top:0px; ma"
                        "rgin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you are an author, you can access your account and other information, and update your accounts, on the Kindle Direct Publishing (KDP) or Author Central website, as applicable.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you are a developer participating in our Developer Services Program, you can access your account and other information, and adjust your communications preferences, by updating your accounts in the Developer Services Portal.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SellerWindow: public Ui_SellerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLERWINDOW_H
