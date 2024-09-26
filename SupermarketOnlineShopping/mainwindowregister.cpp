#include "mainwindowregister.h"
#include "ui_mainwindowregister.h"
#include <string>
#include <iostream>
#include "main_.h"
#include <QMessageBox>
#include <mainwindowlogin.h>
#include <QDebug>
#include <fstream>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QtSql/QSqlError>
#include <QtPlugin>
#include <main_.h>

MainWindowRegister::MainWindowRegister(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowRegister)
{
    ui->setupUi(this);
    setWindowTitle("Register");
    setWindowIcon(QIcon(":/imgs/login_page/iconofshopping.svg"));
    setStyleSheet("MainWindowRegister{background-color: #ffffff;}"); // to make the background color or image not override on all the background of all widgets (children) so it's kinda selector
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    ui->pushButton_3->hide();
}

MainWindowRegister::~MainWindowRegister()
{
    delete ui;
}


void MainWindowRegister::on_pushButton_1_clicked()
{
    bool email_correct = true;
    int last_index = no_actualusers;
    QString fullname = ui->lineEdit_2->text();
    QString email = ui->lineEdit_3->text();
    QString password = ui->lineEdit_4->text();
    QString phone_number = ui->lineEdit_5->text();
    QString location = ui->lineEdit_6->text();

    if (fullname.toStdString()[0]== 32 || fullname.isEmpty() || email.toStdString()[0]== 32 || email.isEmpty() || password.toStdString()[0]== 32 || password.isEmpty() ||phone_number.toStdString()[0]== 32 || phone_number.isEmpty()|| location.toStdString()[0]== 32 || location.isEmpty() ){
        QMessageBox::critical(this,"Error","There is missing input , You must fill all inputs");
        return;
    }

    //so we convert qstring to stdstring , String is array of characters
    int j = 0;
    bool email_check1 = false; //to check @
    bool email_check2 = false; // to check .
    while (email.toStdString()[j] != '\0') {
        if (email[j] == '@') {
            email_check1 = true;
        }
        if (email.toStdString()[j] == '.') {
            email_check2 = true;
        }
        j++;
    }
    if (email_check1 && email_check2) {
        for (int k = 0;k < no_actualusers;k++){
            if (email.toStdString() == customer[k].name)
                email_correct = false;
        }

    }
    else {
        QMessageBox::critical(this,"Wrong Email","Wrong emal Format..Try Again");
        return;
    }
    if (email_correct)
        ui->lineEdit_3->setStyleSheet("border-style: solid;border-color: green;border-width:2px;border-style: solid;border-radius: 10px;font-size: 25px;");
    else{
        QMessageBox::critical(this,"Same Email","You have registered by this email before , Please Login");
        return;
    }

    int len_phone = phone_number.length();
    if (len_phone != 11) {
        QMessageBox::critical(this,"Wrong Phone Number","Wrong Phone Number Format .. Try again");
        return;
    }
    bool password_check = password_checking(password.toStdString());
    if (!password_check){
        QMessageBox::critical(this,"Error","Password must consist of 8 characters or more");
        return;
    }
    customer[last_index].id = (customer[last_index - 1].id + 1);
    customer[last_index].name = fullname.toStdString();
    customer[last_index].email = email.toStdString();
    customer[last_index].password = password.toStdString();
    customer[last_index].phone_number = phone_number.toStdString();
    customer[last_index].address = location.toStdString();

    std::string user_id = "Your ID is #" + to_string(customer[last_index].id);
    QString id = QString::fromStdString(user_id);

    QSqlQuery sql_query;
    sql_query.prepare("INSERT INTO users_data (id,full_name,email,password,phone_number,address)"
                      "VALUES (:id,:fullname,:email,:password,:phone_number,:address)");
    sql_query.bindValue(":id",customer[last_index].id);
    sql_query.bindValue(":fullname",fullname);
    sql_query.bindValue(":email",email);
    sql_query.bindValue(":password",password);
    sql_query.bindValue(":phone_number",phone_number);
    sql_query.bindValue(":address",location);
    if(sql_query.exec()){
        QMessageBox::information(this,"You Successfully registered","Congratulations , You officially have account");
        QMessageBox::information(this,"You Successfully registered",id);

    }
    else{
        qDebug() << "db doesnt store the data";
        qDebug() << sql_query.lastError();

    }


    no_actualusers++;
    qDebug() << no_actualusers;
    hide();
    MainWindowLogin *Login = new MainWindowLogin();
    Login->show();



}


void MainWindowRegister::on_pushButton_2_clicked()
{
    hide();
    MainWindowLogin *login_page = new MainWindowLogin();
    login_page->show();
}


void MainWindowRegister::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_3->show();
    ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
}


void MainWindowRegister::on_pushButton_3_clicked()
{
    ui->pushButton_3->hide();
    ui->pushButton->show();
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
}

