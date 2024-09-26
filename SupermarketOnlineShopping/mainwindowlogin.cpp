#include "mainwindowlogin.h"
#include "ui_mainwindowlogin.h"
#include <QtSvg>
#include <QLabel>
#include <QPixmap>
#include <mainwindowregister.h>
#include <main_.h>
#include <iostream>
#include <string>
#include <QString>
#include <QMessageBox>
#include "mainwindowhome.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
int user_index;
MainWindowLogin::MainWindowLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowLogin)
{
    ui->setupUi(this);
    setWindowTitle("Login");
    setWindowIcon(QIcon(":/imgs/login_page/iconofshopping.svg"));
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->hide->hide();
    //----------------------------
    // for forgot password page
    ui->newpassword_input->hide();
    ui->confirmnew->hide();
    ui->eyepassword_hide_forgot->hide();
    ui->eyepassword_view_forgot->hide();


}

MainWindowLogin::~MainWindowLogin()
{
    delete ui;
}

void MainWindowLogin::on_pushButton_2_clicked()
{
    hide();
    MainWindowRegister *register_page = new MainWindowRegister();
    register_page->show();
}


void MainWindowLogin::on_pushButton_3_clicked()
{

    std::string email_login = ui->lineEdit->text().toStdString();
    std::string password_login = ui->lineEdit_2->text().toStdString();
    // isEmpty() -> for QString
    // empty() -> for string
    if (email_login[0]== 32 || QString::fromStdString(email_login).isEmpty()|| password_login[0]== 32 || QString::fromStdString(password_login).isEmpty()){
        QMessageBox::critical(this,"Error","There is missing input , You must fill all inputs");
        return;
    }
    bool login_success = false;
    int no_index;
    for (int i = 0; i < no_actualusers; i++) {
        if (email_login == customer[i].email && password_login == customer[i].password) {
            login_success = true;
            no_index = i;
            user_index = i;
            break;
        }
    }
    if (login_success) {
        std::string user_id = "Your ID: " + to_string(customer[no_index].id);
        QString id = QString::fromStdString(user_id);
        QMessageBox::information(this,"Login Success",id);
        MainWindowHome *home_window = new MainWindowHome();
        hide();
        home_window->show();
        update_previousorders(); //to reload the data of the previous order of the user after login
    }
    else {
        QMessageBox::critical(this,"Invalid email or Password","Invalid Email or password ,Try Again!");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setStyleSheet("border-color: red;border-width:2px;border-style: solid;border-radius: 10px;background-color: #FFFFFF;font-size: 25px;");
        ui->lineEdit_2->setStyleSheet("border-color: red;border-width:2px;border-style: solid;border-radius: 10px;background-color: #FFFFFF;font-size: 25px;");
        return;
    }
    return;
}


void MainWindowLogin::on_hide_clicked()
{
    ui->hide->hide();
    ui->view->show();
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}


void MainWindowLogin::on_view_clicked()
{
    ui->view->hide();
    ui->hide->show();
    ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
}


void MainWindowLogin::on_pushButton_clicked()
{
    ui->pages->setCurrentIndex(1);
}




void MainWindowLogin::on_verifyidentity_clicked()
{
    int id = ui->id_input_forgot->text().toInt();
    string email = ui->email_input_forgot->text().toStdString();
    bool verify_identity = false;
    if (QString::number(id).isEmpty()|| id == 32|| QString::fromStdString(email).isEmpty() || email[0] == 32){
        QMessageBox::critical(this,"Error","You must fill the input");
        return;
    }

    for (int i = 0;i< no_actualusers;i++){
        if (id == customer[i].id && email == customer[i].email){
            verify_identity = true;
            user_index = i;
        }
    }
    if (verify_identity){
        ui->email_input_forgot->setReadOnly(true);
        ui->id_input_forgot->setReadOnly(true);
        ui->verifyidentity->setEnabled(false);
        ui->newpassword_input->show();
        ui->newpassword_input->setEchoMode(QLineEdit::Password);
        ui->confirmnew->show();
    }
    else {
        QMessageBox::critical(this,"Error","Your id and email dont matching together");
        return;
    }



}


void MainWindowLogin::on_confirmnew_clicked()
{
    string new_password = ui->newpassword_input->text().toStdString();
    if (QString::fromStdString(new_password).isEmpty() || new_password[0] == 32){
        QMessageBox::critical(this,"Error","You must fill the input");
        return;
    }
    bool password_check = password_checking(new_password);
    if (password_check){
        ui->confirmnew->setEnabled(false);
        customer[user_index].password = new_password;
        QSqlQuery query;
        query.prepare("UPDATE users_data SET password = :password WHERE id = :id");
        query.bindValue(":id", QString::number(customer[user_index].id));
        query.bindValue(":password", QString::fromStdString(customer[user_index].password));

        if(query.exec()){
            QMessageBox::information(this,"Success","You have changed your password successfully");
            QMessageBox::information(this,"Login","Please Login Again for security");
            ui->pages->setCurrentIndex(0);
        }
        else
            qDebug() << "db is not updated with password new value";


    }
    else {
        QMessageBox::critical(this,"Wrong","Sorry Password must be 8 or more than 8 characters");
        return;
    }

}


void MainWindowLogin::on_eyepassword_hide_forgot_clicked()
{
    ui->eyepassword_hide_forgot->hide();
    ui->eyepassword_view_forgot->show();
    ui->newpassword_input->setEchoMode(QLineEdit::Password);
}


void MainWindowLogin::on_eyepassword_view_forgot_clicked()
{
    ui->eyepassword_view_forgot->hide();
    ui->eyepassword_hide_forgot->show();
    ui->newpassword_input->setEchoMode(QLineEdit::Normal);
}


void MainWindowLogin::on_back_btn_clicked()
{
    ui->pages->setCurrentIndex(0);
}

