#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "mainwindowlogin.h"
#include "mainwindowregister.h"
#include <sellerwindow.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("SuperMarket");
    setWindowIcon(QIcon(":/imgs/login_page/iconofshopping.svg"));
    ui->widget_3->setStyleSheet("QWidget#widget_3 > * {border-style:solid;border-color:black;border-width:1px;background-color:white;border-radius:10px;}");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    MainWindowLogin *login_page = new MainWindowLogin();
    hide();
    login_page->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    MainWindowRegister *register_page = new MainWindowRegister();
    hide();
    register_page->show();
}




void MainWindow::on_seller_login_clicked()
{
    SellerWindow *seller_login = new SellerWindow(nullptr,"login");
    hide();
    seller_login->show();

}


void MainWindow::on_seller_register_clicked()
{
    SellerWindow *seller_register = new SellerWindow(nullptr,"register");
    hide();
    seller_register->show();
}

