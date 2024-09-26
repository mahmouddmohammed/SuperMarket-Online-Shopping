/********************************************************************************
** Form generated from reading UI file 'mainwindowhome.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWHOME_H
#define UI_MAINWINDOWHOME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowHome
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QFrame *frame_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QPushButton *dashboard_btn;
    QPushButton *category_btn;
    QPushButton *sellers_btn;
    QSpacerItem *verticalSpacer_3;
    QPushButton *cart_btn;
    QPushButton *previous_orders_btn;
    QPushButton *coupons_btn;
    QSpacerItem *verticalSpacer;
    QPushButton *profile_btn;
    QPushButton *logout_btn;
    QFrame *frame_3;
    QLineEdit *searchproductname_input;
    QLabel *welcome;
    QPushButton *searchproductname_btn;
    QFrame *frame_4;
    QStackedWidget *pages;
    QWidget *Dashboard;
    QScrollArea *scrollArea_16;
    QWidget *scrollAreaWidgetContents_5;
    QWidget *Categories;
    QScrollArea *scrollArea_11;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QPushButton *Officebtn;
    QPushButton *Electronics_btn;
    QPushButton *Beautybtn;
    QPushButton *HomeFurniturebtn;
    QPushButton *VideoGamesbtn;
    QPushButton *SportsSupplies;
    QPushButton *Groceries_btn;
    QWidget *Electronics;
    QScrollArea *scrollArea;
    QWidget *scrollContentContainer;
    QWidget *VideoGames;
    QScrollArea *scrollArea_7;
    QWidget *scrollContentContainer_7;
    QWidget *Groceries;
    QScrollArea *scrollArea_3;
    QWidget *scrollContentContainer_3;
    QWidget *Beauty;
    QScrollArea *scrollArea_2;
    QWidget *scrollContentContainer_2;
    QWidget *Office;
    QScrollArea *scrollArea_5;
    QWidget *scrollContentContainer_5;
    QWidget *Home_Furniture;
    QScrollArea *scrollArea_4;
    QWidget *scrollContentContainer_4;
    QWidget *Sports_Supplies;
    QScrollArea *scrollArea_6;
    QWidget *scrollContentContainer_6;
    QWidget *cart;
    QScrollArea *scrollArea_8;
    QWidget *scrollContentContainer_8;
    QWidget *checkout;
    QScrollArea *scrollArea_9;
    QWidget *scrollContentContainer_9;
    QWidget *widget;
    QWidget *checkout_container;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_2;
    QFrame *frame_5;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *name_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *phone_label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *Location;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLabel *cart_id;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLabel *price_before;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QLabel *discount;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QLabel *price_after;
    QFrame *frame_6;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *paywith_visa;
    QPushButton *paywith_paypal;
    QPushButton *cashon_delivery;
    QWidget *visa_pay_container;
    QLineEdit *credit_id;
    QLineEdit *cvv;
    QLineEdit *month;
    QPushButton *visa_pay_btn;
    QLineEdit *year;
    QLabel *label_3;
    QWidget *previous_orders;
    QScrollArea *scrollArea_10;
    QWidget *scrollContentContainer_10;
    QWidget *profile_setting;
    QScrollArea *scrollArea_12;
    QWidget *scrollContentContainer_11;
    QWidget *sellers_page;
    QScrollArea *scrollArea_13;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *sellersproducts_page;
    QScrollArea *scrollArea_14;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *searchbyname_products_page;
    QScrollArea *scrollArea_15;
    QWidget *scrollAreaWidgetContents_4;
    QWidget *coupons_page;
    QWidget *coupons_widget;
    QMenuBar *menubar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindowHome)
    {
        if (MainWindowHome->objectName().isEmpty())
            MainWindowHome->setObjectName("MainWindowHome");
        MainWindowHome->resize(1167, 650);
        centralwidget = new QWidget(MainWindowHome);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1161, 621));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 151, 621));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame#frame_2 {\n"
"/*background-color: white;*/\n"
"/*background-color: #F4F4F4;*/\n"
"background-color: #1B7FBD;\n"
"\n"
"/*border-color:#112f91 ;*/\n"
"border-color: black;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"/*border-right-color: none;*/\n"
"border-radius: 5px;\n"
"\n"
"\n"
"}\n"
"QFrame QPushButton {\n"
"    color:#112f91;\n"
"    background-color: white;\n"
"	border-radius: 5px;\n"
"	font-weight: bold;\n"
"	font-size: 16px;\n"
"	\n"
"\n"
"}\n"
"\n"
"Qframe QPushButton:hover{\n"
"    color:white;\n"
"    background-color: #112f91;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 131, 591));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"border: none;\n"
""));

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        dashboard_btn = new QPushButton(layoutWidget);
        dashboard_btn->setObjectName("dashboard_btn");
        dashboard_btn->setMinimumSize(QSize(0, 30));
        dashboard_btn->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(dashboard_btn);

        category_btn = new QPushButton(layoutWidget);
        category_btn->setObjectName("category_btn");
        category_btn->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(category_btn);

        sellers_btn = new QPushButton(layoutWidget);
        sellers_btn->setObjectName("sellers_btn");
        sellers_btn->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(sellers_btn);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        cart_btn = new QPushButton(layoutWidget);
        cart_btn->setObjectName("cart_btn");
        cart_btn->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(cart_btn);

        previous_orders_btn = new QPushButton(layoutWidget);
        previous_orders_btn->setObjectName("previous_orders_btn");
        previous_orders_btn->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(previous_orders_btn);

        coupons_btn = new QPushButton(layoutWidget);
        coupons_btn->setObjectName("coupons_btn");
        coupons_btn->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(coupons_btn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        profile_btn = new QPushButton(layoutWidget);
        profile_btn->setObjectName("profile_btn");
        profile_btn->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(profile_btn);

        logout_btn = new QPushButton(layoutWidget);
        logout_btn->setObjectName("logout_btn");
        logout_btn->setStyleSheet(QString::fromUtf8("background-color: red;\n"
"color: white;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(logout_btn);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(150, 0, 1011, 61));
        frame_3->setStyleSheet(QString::fromUtf8("/*background-color: #0A4D68;*/\n"
"background-color: #1B7FBD;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        searchproductname_input = new QLineEdit(frame_3);
        searchproductname_input->setObjectName("searchproductname_input");
        searchproductname_input->setGeometry(QRect(30, 5, 641, 51));
        searchproductname_input->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius:25px;"));
        welcome = new QLabel(frame_3);
        welcome->setObjectName("welcome");
        welcome->setGeometry(QRect(700, 10, 231, 41));
        welcome->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: blue;\n"
"color: #F6EF98;\n"
"font-weight:bold;\n"
"font-size: 15px;\n"
""));
        searchproductname_btn = new QPushButton(frame_3);
        searchproductname_btn->setObjectName("searchproductname_btn");
        searchproductname_btn->setGeometry(QRect(610, 5, 51, 51));
        searchproductname_btn->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius:20px;\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/home/magnifier_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchproductname_btn->setIcon(icon);
        searchproductname_btn->setIconSize(QSize(35, 35));
        frame_4 = new QFrame(frame);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(150, 60, 1011, 561));
        frame_4->setStyleSheet(QString::fromUtf8("/*background-color: green;*/"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        pages = new QStackedWidget(frame_4);
        pages->setObjectName("pages");
        pages->setGeometry(QRect(0, 0, 1011, 561));
        Dashboard = new QWidget();
        Dashboard->setObjectName("Dashboard");
        scrollArea_16 = new QScrollArea(Dashboard);
        scrollArea_16->setObjectName("scrollArea_16");
        scrollArea_16->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_16->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName("scrollAreaWidgetContents_5");
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_16->setWidget(scrollAreaWidgetContents_5);
        pages->addWidget(Dashboard);
        Categories = new QWidget();
        Categories->setObjectName("Categories");
        scrollArea_11 = new QScrollArea(Categories);
        scrollArea_11->setObjectName("scrollArea_11");
        scrollArea_11->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_11->setStyleSheet(QString::fromUtf8("font-size:40px;\n"
"font-weight: bold;\n"
"border-radius: 5px;"));
        scrollArea_11->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1011, 561));
        layoutWidget1 = new QWidget(scrollAreaWidgetContents);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 0, 1011, 616));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Officebtn = new QPushButton(layoutWidget1);
        Officebtn->setObjectName("Officebtn");
        Officebtn->setMinimumSize(QSize(0, 200));

        gridLayout->addWidget(Officebtn, 1, 1, 1, 1);

        Electronics_btn = new QPushButton(layoutWidget1);
        Electronics_btn->setObjectName("Electronics_btn");
        Electronics_btn->setMinimumSize(QSize(0, 200));

        gridLayout->addWidget(Electronics_btn, 0, 0, 1, 1);

        Beautybtn = new QPushButton(layoutWidget1);
        Beautybtn->setObjectName("Beautybtn");
        Beautybtn->setMinimumSize(QSize(0, 200));

        gridLayout->addWidget(Beautybtn, 1, 0, 1, 1);

        HomeFurniturebtn = new QPushButton(layoutWidget1);
        HomeFurniturebtn->setObjectName("HomeFurniturebtn");
        HomeFurniturebtn->setMinimumSize(QSize(0, 200));

        gridLayout->addWidget(HomeFurniturebtn, 1, 2, 1, 1);

        VideoGamesbtn = new QPushButton(layoutWidget1);
        VideoGamesbtn->setObjectName("VideoGamesbtn");
        VideoGamesbtn->setMinimumSize(QSize(0, 200));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/categories/pexels-stas-knop-1298601.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VideoGamesbtn->setIcon(icon1);
        VideoGamesbtn->setIconSize(QSize(0, 0));

        gridLayout->addWidget(VideoGamesbtn, 0, 1, 1, 1);

        SportsSupplies = new QPushButton(layoutWidget1);
        SportsSupplies->setObjectName("SportsSupplies");
        SportsSupplies->setMinimumSize(QSize(0, 200));

        gridLayout->addWidget(SportsSupplies, 2, 1, 1, 1);

        Groceries_btn = new QPushButton(layoutWidget1);
        Groceries_btn->setObjectName("Groceries_btn");
        Groceries_btn->setMinimumSize(QSize(0, 200));

        gridLayout->addWidget(Groceries_btn, 0, 2, 1, 1);

        scrollArea_11->setWidget(scrollAreaWidgetContents);
        pages->addWidget(Categories);
        Electronics = new QWidget();
        Electronics->setObjectName("Electronics");
        scrollArea = new QScrollArea(Electronics);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea->setWidgetResizable(true);
        scrollContentContainer = new QWidget();
        scrollContentContainer->setObjectName("scrollContentContainer");
        scrollContentContainer->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea->setWidget(scrollContentContainer);
        pages->addWidget(Electronics);
        VideoGames = new QWidget();
        VideoGames->setObjectName("VideoGames");
        scrollArea_7 = new QScrollArea(VideoGames);
        scrollArea_7->setObjectName("scrollArea_7");
        scrollArea_7->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_7->setWidgetResizable(true);
        scrollContentContainer_7 = new QWidget();
        scrollContentContainer_7->setObjectName("scrollContentContainer_7");
        scrollContentContainer_7->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_7->setWidget(scrollContentContainer_7);
        pages->addWidget(VideoGames);
        Groceries = new QWidget();
        Groceries->setObjectName("Groceries");
        scrollArea_3 = new QScrollArea(Groceries);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_3->setWidgetResizable(true);
        scrollContentContainer_3 = new QWidget();
        scrollContentContainer_3->setObjectName("scrollContentContainer_3");
        scrollContentContainer_3->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_3->setWidget(scrollContentContainer_3);
        pages->addWidget(Groceries);
        Beauty = new QWidget();
        Beauty->setObjectName("Beauty");
        scrollArea_2 = new QScrollArea(Beauty);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_2->setWidgetResizable(true);
        scrollContentContainer_2 = new QWidget();
        scrollContentContainer_2->setObjectName("scrollContentContainer_2");
        scrollContentContainer_2->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_2->setWidget(scrollContentContainer_2);
        pages->addWidget(Beauty);
        Office = new QWidget();
        Office->setObjectName("Office");
        scrollArea_5 = new QScrollArea(Office);
        scrollArea_5->setObjectName("scrollArea_5");
        scrollArea_5->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_5->setWidgetResizable(true);
        scrollContentContainer_5 = new QWidget();
        scrollContentContainer_5->setObjectName("scrollContentContainer_5");
        scrollContentContainer_5->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_5->setWidget(scrollContentContainer_5);
        pages->addWidget(Office);
        Home_Furniture = new QWidget();
        Home_Furniture->setObjectName("Home_Furniture");
        scrollArea_4 = new QScrollArea(Home_Furniture);
        scrollArea_4->setObjectName("scrollArea_4");
        scrollArea_4->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_4->setWidgetResizable(true);
        scrollContentContainer_4 = new QWidget();
        scrollContentContainer_4->setObjectName("scrollContentContainer_4");
        scrollContentContainer_4->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_4->setWidget(scrollContentContainer_4);
        pages->addWidget(Home_Furniture);
        Sports_Supplies = new QWidget();
        Sports_Supplies->setObjectName("Sports_Supplies");
        scrollArea_6 = new QScrollArea(Sports_Supplies);
        scrollArea_6->setObjectName("scrollArea_6");
        scrollArea_6->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_6->setWidgetResizable(true);
        scrollContentContainer_6 = new QWidget();
        scrollContentContainer_6->setObjectName("scrollContentContainer_6");
        scrollContentContainer_6->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_6->setWidget(scrollContentContainer_6);
        pages->addWidget(Sports_Supplies);
        cart = new QWidget();
        cart->setObjectName("cart");
        scrollArea_8 = new QScrollArea(cart);
        scrollArea_8->setObjectName("scrollArea_8");
        scrollArea_8->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_8->setStyleSheet(QString::fromUtf8("background-color: white;"));
        scrollArea_8->setWidgetResizable(true);
        scrollContentContainer_8 = new QWidget();
        scrollContentContainer_8->setObjectName("scrollContentContainer_8");
        scrollContentContainer_8->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_8->setWidget(scrollContentContainer_8);
        pages->addWidget(cart);
        checkout = new QWidget();
        checkout->setObjectName("checkout");
        checkout->setStyleSheet(QString::fromUtf8(""));
        scrollArea_9 = new QScrollArea(checkout);
        scrollArea_9->setObjectName("scrollArea_9");
        scrollArea_9->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_9->setWidgetResizable(true);
        scrollContentContainer_9 = new QWidget();
        scrollContentContainer_9->setObjectName("scrollContentContainer_9");
        scrollContentContainer_9->setGeometry(QRect(0, 0, 1009, 559));
        widget = new QWidget(scrollContentContainer_9);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1011, 561));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"\n"
"	background-color: white;\n"
"\n"
"}"));
        checkout_container = new QWidget(widget);
        checkout_container->setObjectName("checkout_container");
        checkout_container->setGeometry(QRect(20, 30, 661, 511));
        checkout_container->setStyleSheet(QString::fromUtf8("QWidget#checkout_container{\n"
"\n"
"	background-image: url(:/imgs/checkout/background_checkout.png);\n"
"	background-repeat: no-repeat;\n"
"  \n"
"   /*background-position: center;*/\n"
"\n"
"}"));
        layoutWidget_2 = new QWidget(checkout_container);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 20, 621, 471));
        gridLayout_2 = new QGridLayout(layoutWidget_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(layoutWidget_2);
        frame_5->setObjectName("frame_5");
        frame_5->setStyleSheet(QString::fromUtf8("/*background-color: white;*/\n"
"border-radius: 10px;\n"
"font-weight: bold;\n"
"font-size: 20px;"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        layoutWidget_3 = new QWidget(frame_5);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(30, 10, 571, 381));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget_3);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        name_label = new QLabel(layoutWidget_3);
        name_label->setObjectName("name_label");

        horizontalLayout->addWidget(name_label);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        phone_label = new QLabel(layoutWidget_3);
        phone_label->setObjectName("phone_label");

        horizontalLayout_2->addWidget(phone_label);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_6 = new QLabel(layoutWidget_3);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        Location = new QLabel(layoutWidget_3);
        Location->setObjectName("Location");

        horizontalLayout_3->addWidget(Location);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName("label_8");

        horizontalLayout_4->addWidget(label_8);

        cart_id = new QLabel(layoutWidget_3);
        cart_id->setObjectName("cart_id");

        horizontalLayout_4->addWidget(cart_id);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_10 = new QLabel(layoutWidget_3);
        label_10->setObjectName("label_10");

        horizontalLayout_5->addWidget(label_10);

        price_before = new QLabel(layoutWidget_3);
        price_before->setObjectName("price_before");

        horizontalLayout_5->addWidget(price_before);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_14 = new QLabel(layoutWidget_3);
        label_14->setObjectName("label_14");

        horizontalLayout_7->addWidget(label_14);

        discount = new QLabel(layoutWidget_3);
        discount->setObjectName("discount");

        horizontalLayout_7->addWidget(discount);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_12 = new QLabel(layoutWidget_3);
        label_12->setObjectName("label_12");

        horizontalLayout_6->addWidget(label_12);

        price_after = new QLabel(layoutWidget_3);
        price_after->setObjectName("price_after");

        horizontalLayout_6->addWidget(price_after);


        verticalLayout_2->addLayout(horizontalLayout_6);


        gridLayout_2->addWidget(frame_5, 0, 0, 1, 1);

        frame_6 = new QFrame(layoutWidget_2);
        frame_6->setObjectName("frame_6");
        frame_6->setMaximumSize(QSize(16777215, 60));
        frame_6->setStyleSheet(QString::fromUtf8("/*background-color: black;*/"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        layoutWidget_4 = new QWidget(frame_6);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(4, 10, 621, 51));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        paywith_visa = new QPushButton(layoutWidget_4);
        paywith_visa->setObjectName("paywith_visa");
        paywith_visa->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"background-color: #1B7FBD ;\n"
"color: white;\n"
"font-size:24px;\n"
"border-radius: 5px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/checkout/visa_PNG15.png"), QSize(), QIcon::Normal, QIcon::Off);
        paywith_visa->setIcon(icon2);
        paywith_visa->setIconSize(QSize(27, 27));

        horizontalLayout_8->addWidget(paywith_visa);

        paywith_paypal = new QPushButton(layoutWidget_4);
        paywith_paypal->setObjectName("paywith_paypal");
        paywith_paypal->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"background-color: #1B7FBD ;\n"
"color: white;\n"
"font-size:25px;\n"
"border-radius: 5px;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgs/checkout/174861.png"), QSize(), QIcon::Normal, QIcon::Off);
        paywith_paypal->setIcon(icon3);
        paywith_paypal->setIconSize(QSize(27, 27));

        horizontalLayout_8->addWidget(paywith_paypal);

        cashon_delivery = new QPushButton(layoutWidget_4);
        cashon_delivery->setObjectName("cashon_delivery");
        cashon_delivery->setMinimumSize(QSize(0, 0));
        cashon_delivery->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"background-color: #112F91 ;\n"
"color: white;\n"
"font-size:20px;\n"
"border-radius: 5px;"));

        horizontalLayout_8->addWidget(cashon_delivery);


        gridLayout_2->addWidget(frame_6, 1, 0, 1, 1);

        visa_pay_container = new QWidget(widget);
        visa_pay_container->setObjectName("visa_pay_container");
        visa_pay_container->setGeometry(QRect(730, 50, 251, 461));
        credit_id = new QLineEdit(visa_pay_container);
        credit_id->setObjectName("credit_id");
        credit_id->setGeometry(QRect(12, 110, 231, 41));
        credit_id->setMaxLength(16);
        cvv = new QLineEdit(visa_pay_container);
        cvv->setObjectName("cvv");
        cvv->setGeometry(QRect(10, 180, 231, 41));
        cvv->setMaxLength(3);
        month = new QLineEdit(visa_pay_container);
        month->setObjectName("month");
        month->setGeometry(QRect(50, 260, 61, 41));
        visa_pay_btn = new QPushButton(visa_pay_container);
        visa_pay_btn->setObjectName("visa_pay_btn");
        visa_pay_btn->setGeometry(QRect(20, 370, 221, 41));
        visa_pay_btn->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"background-color: #112F91 ;\n"
"color: white;\n"
"font-size:20px;\n"
"border-radius: 5px;"));
        year = new QLineEdit(visa_pay_container);
        year->setObjectName("year");
        year->setGeometry(QRect(140, 260, 61, 41));
        label_3 = new QLabel(visa_pay_container);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(72, -10, 101, 51));
        label_3->setStyleSheet(QString::fromUtf8("background-color: black;\n"
"font-weight: bold;\n"
"color: white;\n"
"border-radius: 5px;"));
        label_3->setAlignment(Qt::AlignCenter);
        scrollArea_9->setWidget(scrollContentContainer_9);
        pages->addWidget(checkout);
        previous_orders = new QWidget();
        previous_orders->setObjectName("previous_orders");
        scrollArea_10 = new QScrollArea(previous_orders);
        scrollArea_10->setObjectName("scrollArea_10");
        scrollArea_10->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_10->setStyleSheet(QString::fromUtf8(""));
        scrollArea_10->setWidgetResizable(true);
        scrollContentContainer_10 = new QWidget();
        scrollContentContainer_10->setObjectName("scrollContentContainer_10");
        scrollContentContainer_10->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_10->setWidget(scrollContentContainer_10);
        pages->addWidget(previous_orders);
        profile_setting = new QWidget();
        profile_setting->setObjectName("profile_setting");
        scrollArea_12 = new QScrollArea(profile_setting);
        scrollArea_12->setObjectName("scrollArea_12");
        scrollArea_12->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_12->setStyleSheet(QString::fromUtf8(""));
        scrollArea_12->setWidgetResizable(true);
        scrollContentContainer_11 = new QWidget();
        scrollContentContainer_11->setObjectName("scrollContentContainer_11");
        scrollContentContainer_11->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_12->setWidget(scrollContentContainer_11);
        pages->addWidget(profile_setting);
        sellers_page = new QWidget();
        sellers_page->setObjectName("sellers_page");
        scrollArea_13 = new QScrollArea(sellers_page);
        scrollArea_13->setObjectName("scrollArea_13");
        scrollArea_13->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_13->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_13->setWidget(scrollAreaWidgetContents_2);
        pages->addWidget(sellers_page);
        sellersproducts_page = new QWidget();
        sellersproducts_page->setObjectName("sellersproducts_page");
        scrollArea_14 = new QScrollArea(sellersproducts_page);
        scrollArea_14->setObjectName("scrollArea_14");
        scrollArea_14->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_14->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_14->setWidget(scrollAreaWidgetContents_3);
        pages->addWidget(sellersproducts_page);
        searchbyname_products_page = new QWidget();
        searchbyname_products_page->setObjectName("searchbyname_products_page");
        scrollArea_15 = new QScrollArea(searchbyname_products_page);
        scrollArea_15->setObjectName("scrollArea_15");
        scrollArea_15->setGeometry(QRect(0, 0, 1011, 561));
        scrollArea_15->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 1009, 559));
        scrollArea_15->setWidget(scrollAreaWidgetContents_4);
        pages->addWidget(searchbyname_products_page);
        coupons_page = new QWidget();
        coupons_page->setObjectName("coupons_page");
        coupons_widget = new QWidget(coupons_page);
        coupons_widget->setObjectName("coupons_widget");
        coupons_widget->setGeometry(QRect(0, 0, 1011, 561));
        pages->addWidget(coupons_page);
        MainWindowHome->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowHome);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1167, 26));
        MainWindowHome->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindowHome);
        toolBar->setObjectName("toolBar");
        MainWindowHome->addToolBar(Qt::BottomToolBarArea, toolBar);

        retranslateUi(MainWindowHome);

        QMetaObject::connectSlotsByName(MainWindowHome);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowHome)
    {
        MainWindowHome->setWindowTitle(QCoreApplication::translate("MainWindowHome", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindowHome", "<html><head/><body><p align=\"center\">All in </p><p align=\"center\">One</p></body></html>", nullptr));
        dashboard_btn->setText(QCoreApplication::translate("MainWindowHome", "Dashboard", nullptr));
        category_btn->setText(QCoreApplication::translate("MainWindowHome", "Categories", nullptr));
        sellers_btn->setText(QCoreApplication::translate("MainWindowHome", "Sellers", nullptr));
        cart_btn->setText(QCoreApplication::translate("MainWindowHome", "Go to cart", nullptr));
        previous_orders_btn->setText(QCoreApplication::translate("MainWindowHome", "Previous Orders", nullptr));
        coupons_btn->setText(QCoreApplication::translate("MainWindowHome", "Coupons", nullptr));
        profile_btn->setText(QCoreApplication::translate("MainWindowHome", "Profile Setting", nullptr));
        logout_btn->setText(QCoreApplication::translate("MainWindowHome", "Logout", nullptr));
        searchproductname_input->setPlaceholderText(QCoreApplication::translate("MainWindowHome", "Search by name", nullptr));
        welcome->setText(QString());
        searchproductname_btn->setText(QString());
        Officebtn->setText(QCoreApplication::translate("MainWindowHome", "Office", nullptr));
        Electronics_btn->setText(QCoreApplication::translate("MainWindowHome", "Electronics", nullptr));
        Beautybtn->setText(QCoreApplication::translate("MainWindowHome", "Beauty", nullptr));
        HomeFurniturebtn->setText(QCoreApplication::translate("MainWindowHome", "Home & Furniture", nullptr));
        VideoGamesbtn->setText(QCoreApplication::translate("MainWindowHome", "VideoGames", nullptr));
        SportsSupplies->setText(QCoreApplication::translate("MainWindowHome", "Sports Supplies", nullptr));
        Groceries_btn->setText(QCoreApplication::translate("MainWindowHome", "Groceries", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowHome", "Name:", nullptr));
        name_label->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindowHome", "Phone Number:", nullptr));
        phone_label->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindowHome", "Location: ", nullptr));
        Location->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindowHome", "Order ID: ", nullptr));
        cart_id->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindowHome", "Price Before Discount:", nullptr));
        price_before->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindowHome", "Discount: ", nullptr));
        discount->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindowHome", "Price After Discount:", nullptr));
        price_after->setText(QString());
        paywith_visa->setText(QCoreApplication::translate("MainWindowHome", "Pay With Visa", nullptr));
        paywith_paypal->setText(QCoreApplication::translate("MainWindowHome", "Pay With Paypal", nullptr));
        cashon_delivery->setText(QCoreApplication::translate("MainWindowHome", "Cash on delivery", nullptr));
        credit_id->setText(QString());
        credit_id->setPlaceholderText(QCoreApplication::translate("MainWindowHome", "Credit ID Number", nullptr));
        cvv->setPlaceholderText(QCoreApplication::translate("MainWindowHome", "CVV", nullptr));
        month->setPlaceholderText(QCoreApplication::translate("MainWindowHome", "Month", nullptr));
        visa_pay_btn->setText(QString());
        year->setPlaceholderText(QCoreApplication::translate("MainWindowHome", "year", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowHome", "Visa", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindowHome", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowHome: public Ui_MainWindowHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWHOME_H
