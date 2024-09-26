#include "sellerwindow.h"
#include "ui_sellerwindow.h"
#include "main_.h"
#include <QStackedWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QGridLayout>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtPlugin>
#include <QStringList>
#include <QCompleter>
#include <QFileDialog>
#include <mainwindow.h>


int seller_index;
SellerWindow::SellerWindow(QWidget *parent,QString which_page) : // constructor , method that will always be executed each time you make object of that class
    QMainWindow(parent),
    ui(new Ui::SellerWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/imgs/login_page/iconofshopping.svg"));
    if (which_page == "login"){
        setWindowTitle("Login");

        ui->stackedWidget->setCurrentIndex(0);

    }
    else if (which_page == "register"){
        setWindowTitle("Register");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else {
        setWindowTitle("Home");
        ui->stackedWidget->setCurrentIndex(3);
    }

    // for login
    ui->password_input_login->setEchoMode(QLineEdit::Password);
    ui->eyepassword_hide_login->hide();
    //for register page
    ui->password_input_register->setEchoMode(QLineEdit::Password);
    ui->eyepassword_hide_register->hide();
    // for forgot password page
    ui->newpassword_input->hide();
    ui->confirmnewpassword_btn->hide();
    ui->eyepassword_hide_forget->hide();
    ui->eyepassword_view_forget->hide();

}

SellerWindow::~SellerWindow()
{
    delete ui;
}



void SellerWindow::on_login_btn_loginpage_clicked()
{
    bool acc_found = false; //flag
    string email = ui->email_input_login->text().toStdString();
    string password = ui->password_input_login->text().toStdString();

    QString id;
    if (no_sellers == 0){
        QMessageBox::critical(this,"Wrong email or password","There is no seller account registered");
        return;
    }
    for (int i = 0; i < no_sellers;i++){
        if (email == seller[i].email && password == seller[i].password){
            seller_index = i;
            id = "Your Id: " + QString::number(seller[seller_index].id);
            QMessageBox::information(this,"Login Successfully","Succeded");
            QMessageBox::information(this,"Don't Forget it",id);
            acc_found = true;
        }
    }


    if(acc_found){
        ui->name_of_seller->setText(QString::fromStdString(seller[seller_index].name));
        float account_balance = calc_accbalance();
        ui->acc_balance_value->setText(QString::number(account_balance)+ "$");
        ui->home_btn->setStyleSheet("background-color:#BD1616 ;color: #ffffff;font-weight: bold;font-size:15px;border-radius:5px;");
        ui->stackedWidget->setCurrentIndex(3);


    }
    else {
        QMessageBox::critical(this,"Wrong email or password","Try again");
        ui->email_input_login->clear();
        ui->password_input_login->clear();
        return;
    }


}


void SellerWindow::on_register_btn_loginpage_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void SellerWindow::on_login_btn_rpage_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void SellerWindow::on_register_btnn_rpage_clicked()
{
    QString seller_id;
    int last_seller_index = no_sellers - 1;
    if (no_sellers == 0)
        seller_id = QString::number(900);
    else
        seller_id = QString::number(seller[last_seller_index].id + 1);

    QString full_name = ui->fullname_input->text();
    QString username = ui->username_input->text();
    QString email = ui->email_input_register->text();
    QString password = ui->password_input_register->text();
    QString phone_number = ui->phonenumber_register->text();
    QString day_birth = ui->day_register->text();
    QString month_birth = ui->month_register->text();
    QString year_birth = ui->year_register->text();
    // in register you will store it in struct and in database , then in main_.cpp you will load the data
    QString gender = ui->gender_comboBox->currentText();
    QString profile_photo = profile_photo_image;

    if (profile_photo.isEmpty()){
        if (gender == "male")
            profile_photo = ":/imgs/gender/male.png";

        else if (gender == "female")
            profile_photo = ":/imgs/gender/female.png";
    }

    for (int i = 0; i < no_sellers;i++){
        if (username.toStdString() == seller[i].username){
            QMessageBox::critical(this,"Please Login","You registered by this username before");
            return;
        }
        if (email.toStdString() == seller[i].email){
            QMessageBox::critical(this,"Please Login","You registered by this email before");
            return;
        }
    }
    if (!email_checking(email.toStdString())){
        QMessageBox::critical(this,"Try again","Wrong input email");
        return;
    }
    if (!password_checking(password.toStdString())){
        QMessageBox::critical(this,"Error","Password must consist of 8 characters or more");
        return;
    }
    if (!phonenumber_checking(phone_number.toStdString())){
        QMessageBox::critical(this,"","Wrong Phone number format");
        return;
    }
    if (day_birth.toInt() < 1 || day_birth.toInt() > 31){
        QMessageBox::critical(this,"","Wrong day number");
        return;
    }
    if (month_birth.toInt() < 1 || month_birth.toInt() > 12){
        QMessageBox::critical(this,"","Wrong month number");
        return;
    }
    if (year_birth.toInt() > 2004){
        QMessageBox::critical(this,"","You must be 18 years old or more");
        return;
    }

    if (!(ui->checkbox_agreeto_policy->isChecked())){
        QMessageBox::critical(this,"Agree","Please Agree to our agreements and policy to continue");
        return;
    }

    int new_seller_index = last_seller_index + 1;
    seller[new_seller_index].id = seller_id.toInt();
    seller[new_seller_index].name = full_name.toStdString();
    seller[new_seller_index].username = username.toStdString();
    seller[new_seller_index].email = email.toStdString();
    seller[new_seller_index].password = password.toStdString();
    seller[new_seller_index].phone_number = phone_number.toStdString();
    seller[new_seller_index].gender = gender.toStdString();
    seller[new_seller_index].profile_photo = profile_photo;
    no_sellers++;

    QSqlQuery query;
    query.prepare("INSERT INTO sellers_data (id, full_name, username ,email , password , phone_number , gender , profile_image) VALUES (:id, :name, :username , :email, :password, :phone_number, :gender , :profile_image)");
    query.bindValue(":id",seller_id);
    query.bindValue(":name",full_name);
    query.bindValue(":username",username);
    query.bindValue(":email",email);
    query.bindValue(":password",password);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":gender",gender);
    query.bindValue(":profile_image",profile_photo);
    if (!query.exec())
        qDebug() << "There is something wrong in database, table seller";
    QMessageBox::information(this,"success","You Officially have seller account");
    QString id = "Your id: " + seller_id;
    QMessageBox::information(this,"Successfully Registered",id);
    ui->stackedWidget->setCurrentIndex(0);

}


void SellerWindow::on_add_product_clicked()
{
    ui->add_product->setStyleSheet("background-color:#BD1616 ;color: #ffffff;font-weight: bold;font-size:15px;border-radius:5px;");
    ui->home_btn->setStyleSheet("color: #000000;font-weight: bold;");
    ui->view_products->setStyleSheet("color: #000000;font-weight: bold;");
    ui->profile_stting_btn->setStyleSheet("color: #000000;font-weight: bold;");
    ui->stackedWidget_2->setCurrentIndex(1);

}


void SellerWindow::on_view_products_clicked()
{
    ui->view_products->setStyleSheet("background-color:#BD1616 ;color: #ffffff;font-weight: bold;font-size:15px;border-radius:5px;");
    ui->add_product->setStyleSheet("color: #000000;font-weight: bold;");
    ui->home_btn->setStyleSheet("color: #000000;font-weight: bold;");
    ui->profile_stting_btn->setStyleSheet("color: #000000;font-weight: bold;");

    ui->stackedWidget_2->setCurrentIndex(2);
    // widgets (containers)
    QWidget *scrollarea_containerr ,*container_ofproductscards;

    scrollarea_containerr = ui->scrollAreaWidgetContents_4;




    QLayout *existingLayoutforscroll = scrollarea_containerr->layout();
    if (existingLayoutforscroll != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayoutforscroll->takeAt(0)) != nullptr) {
            if (child->widget()){

                child->widget()->deleteLater();
            }

            delete child;
        }
        delete existingLayoutforscroll;
    }

    container_ofproductscards = new QWidget(scrollarea_containerr); //that container I do by code

    // layouts
    QVBoxLayout *scrollarea_layout;

    scrollarea_layout = new QVBoxLayout(scrollarea_containerr);

    QGridLayout *layout_ofproductscards = new QGridLayout(container_ofproductscards);

    bool check = false;
    int no_products;
    for (int i = 0 , prod_found = 0; i < 7 ; i++){
        no_products = noproducts_incategories[i];
        for (int j = 10 ; j < no_products ; j++){
            QLabel *product_expiration;
            if (category[i].products[j].seller == seller[seller_index].username){
                bool add_stock = false;
                qDebug() << QString::fromStdString(category[i].products[j].name);
                QWidget *product_card = new QWidget();
                QVBoxLayout *contentproduct_card = new QVBoxLayout();
                product_card->setLayout(contentproduct_card);
                QLabel *product_number = new QLabel("#" + QString::number((prod_found)+1),product_card);
                QLabel *product_name = new QLabel("Name: " + QString::fromStdString(category[i].products[j].name) ,product_card);
                QLabel *product_code = new QLabel("ID: " + QString::fromStdString(category[i].products[j].id),product_card);
                QLabel *product_category = new QLabel("Category: " +QString::fromStdString(category[i].products[j].category),product_card);
                QLabel *product_price = new QLabel("Price: " + QString::number(category[i].products[j].price) + "$",product_card);
                QLabel *product_stock = new QLabel("Stock: " + QString::number(category[i].products[j].stock),product_card);
                if (i == 2 || i ==4)
                    product_expiration = new QLabel("Expiration Date: " + QString::fromStdString(category[i].products[j].expiration_date),product_card);
                QLabel* product_image = new QLabel(product_card);
                product_image->setPixmap(QPixmap(category[i].products[j].image_url));
                product_image->setScaledContents(true); // Scales the pixmap to fit the size of the QLabel
                product_image->setFixedSize(250, 350);

                QLabel* product_rating = new QLabel("Rating: " + QString::number(category[i].products[j].rating) + "/5" , product_card);


                QWidget* stock_container = new QWidget();
                QHBoxLayout *stock_container_layout = new QHBoxLayout();
                stock_container_layout->setContentsMargins(0, 0, 0, 0); // to remove the margins
                stock_container->setLayout(stock_container_layout);
                QPushButton *restock = new QPushButton("Restock");
                restock->setStyleSheet("font-weight: bold;font-size:32px;color: white;background-color:green;border-radius:3px;border-style:solid;border-color:black;border-width:1px;");
                restock->setFixedWidth(200);
                QSpinBox *muchquantity = new QSpinBox();
                muchquantity->setRange(1,100);
                muchquantity->setMaximumWidth(100);
                muchquantity->setFixedHeight(45);
                stock_container_layout->addWidget(muchquantity);
                stock_container_layout->addWidget(restock);

                connect(restock,&QPushButton::clicked,[=](){
                    category[i].products[j].stock+=muchquantity->value();
                    product_stock->setText("Stock: " + QString::number(category[i].products[j].stock));
                    QSqlQuery query;

                });

                contentproduct_card->addWidget(product_number);
                contentproduct_card->addWidget(product_image);
                contentproduct_card->addWidget(product_code);
                contentproduct_card->addWidget(product_name);
                contentproduct_card->addWidget(product_category);
                contentproduct_card->addWidget(product_price);
                contentproduct_card->addWidget(product_stock);
                if (i == 2 || i == 4)
                    contentproduct_card->addWidget(product_expiration);
                contentproduct_card->addWidget(product_rating);
                contentproduct_card->addWidget(stock_container);

                product_card->setObjectName("product_card");
                product_card->setStyleSheet("QLabel{font-weight:bold;color:#11405C;}");



                layout_ofproductscards->addWidget(product_card,prod_found/2,prod_found%2);
                prod_found++;
                check = true;
            }
        }
    }
    if (check){
        scrollarea_layout->addWidget(container_ofproductscards);
        container_ofproductscards->setObjectName("productContainers");
        container_ofproductscards->setStyleSheet("QWidget#productContainers > * {border: 1px solid black;background-color: white;border-radius:5px;}");
    }
}


void SellerWindow::on_logout_clicked()
{
    //reset all seller data to default
    hide();
    MainWindow *mainw = new MainWindow();
    mainw->show();
}


void SellerWindow::on_addproduct_btn_clicked()
{
    QString product_name = ui->product_name->text();
    QString product_category = ui->comboBox_category->currentText();
    int category_index = ui->comboBox_category->currentIndex(); //lazm ykono index of categories in combo box like in index of category[i]
    QString product_price = ui->product_price->text();
    QString product_stock = ui->product_stock->text();
    QString product_expiration_date = ui->dateEdit->text();
    //qDebug() << product_expiration_date;
    QString product_image_url = image_path;
    QString product_id = QString::fromStdString(Product_RandomID(1000,9000));
    QString product_seller = QString::fromStdString(seller[seller_index].username);

    if (emptyInput(product_name) || emptyInput(product_price) || emptyInput(product_stock)){
        QMessageBox::critical(this,"Empty Input","You must fill all inputs");
        return;
    }

    if (product_image_url.isEmpty()){
        QMessageBox::critical(this,"No Uploaded File","You must upload image of product");
        return;
    }


    int no_ofproducts = noproducts_incategories[category_index];
    for (int i = 0 ; i < no_ofproducts; i++){
        if (product_name.toStdString() == category[category_index].products[i].name && seller[seller_index].username == category[category_index].products[i].seller){
            QMessageBox::critical(this,"","You added this product before");
            return;
        }
    }

    qDebug() << QString::number(category_index);
    qDebug() << QString::number(noproducts_incategories[category_index]);

    category[category_index].products[noproducts_incategories[category_index]].name = product_name.toStdString();
    qDebug() << QString::fromStdString(category[category_index].products[noproducts_incategories[category_index]].name);
    category[category_index].products[noproducts_incategories[category_index]].category = product_category.toStdString();
    category[category_index].products[noproducts_incategories[category_index]].price = product_price.toFloat();
    category[category_index].products[noproducts_incategories[category_index]].stock = product_stock.toInt();
    category[category_index].products[noproducts_incategories[category_index]].seller = product_seller.toStdString();
    category[category_index].products[noproducts_incategories[category_index]].id = product_id.toStdString();
    category[category_index].products[noproducts_incategories[category_index]].expiration_date = product_expiration_date.toStdString();
    category[category_index].products[noproducts_incategories[category_index]].image_url = product_image_url;



    noproducts_incategories[category_index]++; //increse it in struct

    seller[seller_index].no_products++;
    QSqlQuery query;
    query.prepare("INSERT INTO sellers_products (name , category , id ,quantity , price , seller , image_url , expiration_date) VALUES(:name,:category,:id,:quantity,:price,:seller,:image_url,:expiration_date)");
    query.bindValue(":name",product_name);
    query.bindValue(":category",product_category);
    query.bindValue(":id",product_id);
    query.bindValue(":quantity",product_stock);
    query.bindValue(":price",product_price);
    query.bindValue(":seller",product_seller);
    query.bindValue(":image_url",product_image_url);
    query.bindValue(":expiration_date",product_expiration_date);
    //query.bindValue(":no_products",seller[seller_index].no_products); //store data
    if(query.exec()){
        query.prepare("UPDATE sellers_data SET no_products = :no_products WHERE id = :seller_id");
        query.bindValue(":no_products",seller[seller_index].no_products);
        query.bindValue(":seller_id",seller[seller_index].id);
        if (query.exec()){
            ui->product_name->clear();
            ui->product_price->clear();
            ui->product_stock->clear();
            product_image_url = "";

            QMessageBox::information(this,"Success","You added your product successfully");
            return;
        }

    }
}


void SellerWindow::on_upload_image_btn_clicked()
{
    image_path = QFileDialog::getOpenFileName(this,tr("Open File"),"C://","JPG IMAGE (*.jpg);; JPEG IMAGE (*.jpeg);; PNG IMAGE (*.png)");
    //qDebug() << image_path;
}


void SellerWindow::on_profile_stting_btn_clicked()
{
    profile_setting_data();
    ui->profile_stting_btn->setStyleSheet("background-color:#BD1616 ;color: #ffffff;font-weight: bold;font-size:15px;border-radius:5px;");
    ui->add_product->setStyleSheet("color: #000000;font-weight: bold;");
    ui->view_products->setStyleSheet("color: #000000;font-weight: bold;");
    ui->home_btn->setStyleSheet("color: #000000;font-weight: bold;");
    ui->stackedWidget_2->setCurrentIndex(3);
}

void SellerWindow::profile_setting_data(){
    QWidget *profilepage = ui->stackedWidget->findChild<QWidget*>("changeprofile_setting_page"); //Page QWidget Container //dh msh QWidget gded leh ? 3shan ehna m3mlnash call l constructor ehna bnkhzn fy variable dh address of that page only w leh QWidget l2n hoa dh no3h w lakn dh msh by3ml QWidget gded fahm l2n hoa value bta3h hoa address bta3 page
    QWidget *scrollarea_container = ui->scrollAreaWidgetContents_5; //QWidget Container of scroll area
    QWidget *Containerofcards = new QWidget(scrollarea_container); // products container include all the products card
    Containerofcards->setObjectName("cardsContainer");
    //--------------------------------------------------------------------

    if ( Containerofcards->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = Containerofcards->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete Containerofcards->layout();
    }

    if ( scrollarea_container->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = scrollarea_container->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete scrollarea_container->layout();
    }

    if ( profilepage->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = profilepage->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete profilepage->layout();
    }

    //--------------------------------------------------------
    //Creating Layouts
    QVBoxLayout *layout_forpage = new QVBoxLayout(profilepage); //same as profilepage->setLayout(layout_forpage); makes that every widget you add inside layout for page widget will be vertical and anything you will add to this vertical layout will add to page widget
    QVBoxLayout *layout_forscrollareacontainer = new QVBoxLayout(scrollarea_container);
    QGridLayout *layout_forallcardscontainer = new QGridLayout(Containerofcards);
    QString text_labels[5] = {"Profile Photo","Name","Email","Password","Phone Number"};

    for (int i = 0;i<5;i++){
        QWidget *card_container = new QWidget(Containerofcards);
        QVBoxLayout *card_layout = new QVBoxLayout(card_container);
        whatuser_change[i] = new QLabel(text_labels[i],card_container);
        whatuser_change[i]->setStyleSheet("text-align:center;font-size: 30px;font-weight: bold;color: #112f91;");
        whatuser_change[i]->setAlignment(Qt::AlignCenter);
        whatuser_change[i]->setFixedHeight(25);
        btn_change[i] = new QPushButton("Change",card_container);
        btn_change[i]->setStyleSheet("background-color: #BD1616;opacity: 80%;color:white;font-weight:bold;");
        if (i == 0){
            uploadnew_image = new QPushButton("Upload new Photo",card_container);
            uploadnew_image->hide();
        }
        else{
            update_input[i] = new QLineEdit(card_container);
            update_input[i]->clearFocus();
            update_input[i]->hide();
        }
        update_confirm[i] = new QPushButton("Confirm",card_container);
        update_confirm[i]->setStyleSheet("background-color: green;color: white;font-weight: bold;font-size: 30px;");
        update_confirm[i]->hide();
        card_container->setFixedWidth(450);
        card_container->setFixedHeight(250);
        if (i == 3)
            update_input[i]->setEchoMode(QLineEdit::Password);



        connect (btn_change[i],&QPushButton::clicked,[=](){
            if (i == 0){
                uploadnew_image->setFixedHeight(30);
                uploadnew_image->show();
            }
            else{
                update_input[i]->setFixedHeight(30);
                update_input[i]->show();
            }


            update_confirm[i]->setFixedHeight(50);
            update_confirm[i]->show();

            for (int j = 0;j < 5;j++)
                btn_change[j]->setEnabled(false);
            connect(update_confirm[i],&QPushButton::clicked,[=]{
                if (i == 0){
                    if(profilephoto_image_path.isEmpty()){
                        QMessageBox::critical(this,"not uploaded","You didnt upload any photo");
                        return;
                    }
                    update_confirm[i]->setEnabled(false);
                    // store in database
                    // in register you will store it in struct and in database , then in main_.cpp you will load the data , and here you will change it in struct and update the database
                    seller[seller_index].profile_photo = profilephoto_image_path;
                    QSqlQuery query;
                    query.prepare("UPDATE sellers_data SET profile_image = :profile_photo WHERE id = :id");
                    query.bindValue(":id", QString::number(seller[seller_index].id));
                    query.bindValue(":profile_photo", seller[seller_index].profile_photo);

                    if(query.exec())
                        QMessageBox::information(this,"Success","You have changed your name successfully");
                    else
                        qDebug() << "db is not updated with name new value";
                }

                else if (i==1){
                    if (update_input[i]->text().isEmpty() || update_input[i]->text().toStdString()[0] == 32){
                        QMessageBox::critical(this,"Error","You must fill the input");
                        return;
                    }
                    update_confirm[i]->setEnabled(false);
                    seller[seller_index].name = update_input[i]->text().toStdString();
                    QSqlQuery query;
                    query.prepare("UPDATE sellers_data SET full_name = :newName WHERE id = :id");
                    query.bindValue(":id", QString::number(seller[seller_index].id));
                    query.bindValue(":newName", QString::fromStdString(seller[seller_index].name));

                    if(query.exec()){
                        ui->name_of_seller->setText(QString::fromStdString(seller[seller_index].name));
                        QMessageBox::information(this,"Success","You have changed your name successfully");
                    }
                    else
                        qDebug() << "db is not updated with name new value";
                }
                else if (i==2){
                    if (update_input[i]->text().isEmpty() || update_input[i]->text().toStdString()[0] == 32){
                        QMessageBox::critical(this,"Error","You must fill the input");
                        return;
                    }
                    string email = update_input[i]->text().toStdString();
                    bool email_check = email_checking(email);
                    if (email_check){
                        update_confirm[i]->setEnabled(false);
                        seller[seller_index].email = email;
                        QSqlQuery query;
                        query.prepare("UPDATE sellers_data SET email = :email WHERE id = :id");
                        query.bindValue(":id", QString::number(seller[seller_index].id));
                        query.bindValue(":email", QString::fromStdString(seller[seller_index].email));

                        if(query.exec()){
                            QMessageBox::information(this,"Success","You have changed your email successfully");
                            QMessageBox::information(this,"Login","Please Login Again for security");

                            ui->stackedWidget->setCurrentIndex(0);
                        }
                        else
                            qDebug() << "db is not updated with email new value";

                    }
                    else{
                        QMessageBox::critical(this,"Wrong","Wrong Format Email");
                        return; // it is for lambda function not for the slot function of profile setting
                    }
                }
                else if (i==3){

                    if (update_input[i]->text().isEmpty() || update_input[i]->text().toStdString()[0] == 32){
                        QMessageBox::critical(this,"Error","You must fill the input");
                        return;
                    }
                    string password = update_input[i]->text().toStdString();
                    bool password_check  = password_checking(password);
                    if (password_check){
                        update_confirm[i]->setEnabled(false);
                        seller[seller_index].password = password;
                        QSqlQuery query;
                        query.prepare("UPDATE sellers_data SET password = :password WHERE id = :id");
                        query.bindValue(":id", QString::number(seller[seller_index].id));
                        query.bindValue(":password", QString::fromStdString(seller[seller_index].password));

                        if(query.exec()){
                            QMessageBox::information(this,"Success","You have changed your password successfully");
                            QMessageBox::information(this,"Login","Please Login Again for security");

                            ui->stackedWidget->setCurrentIndex(1);
                        }
                        else
                            qDebug() << "db is not updated with password new value";
                    }
                    else {
                        QMessageBox::critical(this,"Wrong","Sorry Password must be 8 or more than 8 characters");
                        return;
                    }
                }
                else if (i==4){
                    if (update_input[i]->text().isEmpty() || update_input[i]->text().toStdString()[0] == 32){
                        QMessageBox::critical(this,"Error","You must fill the input");
                        return;
                    }
                    string phone_number = update_input[i]->text().toStdString();
                    bool phone_number_check = phonenumber_checking(phone_number);
                    if (phone_number_check){
                        update_confirm[i]->setEnabled(false);
                        seller[seller_index].phone_number = phone_number;
                        QSqlQuery query;
                        query.prepare("UPDATE sellers_data SET phone_number = :phone_number WHERE id = :id");
                        query.bindValue(":id", QString::number(seller[seller_index].id));
                        query.bindValue(":phone_number", QString::fromStdString(seller[seller_index].phone_number));

                        if(query.exec())
                            QMessageBox::information(this,"Success","You have changed your phone number successfully");

                        else
                            qDebug() << "db is not updated with phone number new value";

                    }
                    else {
                        QMessageBox::critical(this,"Wrong","Sorry Phone Number must consist of 11 number");
                        return;
                    }


                }
            });
        });
        card_container->setStyleSheet("QWidget#cardsContainer > * {border-width:2px;border-color:#112f91;border-style:solid;background-color: #fcfcfc;border-radius: 10px;}");
        card_layout->addWidget(whatuser_change[i]);
        card_layout->addWidget(btn_change[i]);
        if (i == 0)
            card_layout->addWidget(uploadnew_image);
        else
            card_layout->addWidget(update_input[i]);

        card_layout->addWidget(update_confirm[i]);
        layout_forallcardscontainer->addWidget(card_container, i/2, i%2);

    }
    connect (uploadnew_image,&QPushButton::clicked,[=](){
        profilephoto_image_path = QFileDialog::getOpenFileName(this,tr("Open File"),"C://","JPG IMAGE (*.jpg);; JPEG IMAGE (*.jpeg);; PNG IMAGE (*.png)");
    });
    layout_forscrollareacontainer->addWidget(Containerofcards);
}

void SellerWindow::on_forget_password_btn_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void SellerWindow::on_verifyidentity_clicked()
{
    int id = ui->id_input_forgot->text().toInt();
    string email = ui->email_input_forgot->text().toStdString();
    string username = ui->username_input_forgot->text().toStdString();
    bool verify_identity = false;
    if (QString::number(id).isEmpty()|| id == 32|| QString::fromStdString(email).isEmpty() || email[0] == 32){
        QMessageBox::critical(this,"Error","You must fill the input");
        return;
    }

    for (int i = 0;i< no_sellers;i++){
        if (id == seller[i].id && email == seller[i].email && username == seller[i].username){
            verify_identity = true;
            seller_index = i;
        }
    }
    if (verify_identity){
        ui->email_input_forgot->setReadOnly(true);
        ui->id_input_forgot->setReadOnly(true);
        ui->username_input_forgot->setReadOnly(true);
        ui->verifyidentity->setEnabled(false);
        ui->newpassword_input->show();
        ui->newpassword_input->setEchoMode(QLineEdit::Password);
        ui->eyepassword_view_forget->show();
        ui->confirmnewpassword_btn->show();
    }
    else {
        QMessageBox::critical(this,"Error","Your id and email dont matching together");
        return;
    }
}


void SellerWindow::on_confirmnewpassword_btn_clicked()
{
    string new_password = ui->newpassword_input->text().toStdString();
    if (QString::fromStdString(new_password).isEmpty() || new_password[0] == 32){
        QMessageBox::critical(this,"Error","You must fill the input");
        return;
    }
    bool password_check = password_checking(new_password);
    if (password_check){
        ui->confirmnewpassword_btn->setEnabled(false);
        seller[seller_index].password = new_password;
        QSqlQuery query;
        query.prepare("UPDATE sellers_data SET password = :new_password WHERE id = :id");
        query.bindValue(":id", QString::number(seller[seller_index].id));
        query.bindValue(":new_password", QString::fromStdString(seller[seller_index].password));

        if(query.exec()){
            QMessageBox::information(this,"Success","You have changed your password successfully");
            QMessageBox::information(this,"Login","Please Login Again for security");
            ui->stackedWidget->setCurrentIndex(0);
        }
        else
            qDebug() << "db is not updated with password new value";


    }
    else {
        QMessageBox::critical(this,"Wrong","Sorry Password must be 8 or more than 8 characters");
        return;
    }
}


void SellerWindow::on_eyepassword_view_forget_clicked()
{
    ui->eyepassword_view_forget->hide();
    ui->eyepassword_hide_forget->show();
    ui->newpassword_input->setEchoMode(QLineEdit::Normal);
}


void SellerWindow::on_eyepassword_hide_forget_clicked()
{
    ui->eyepassword_hide_forget->hide();
    ui->eyepassword_view_forget->show();
    ui->newpassword_input->setEchoMode(QLineEdit::Password);
}


void SellerWindow::on_eyepassword_hide_register_clicked()
{
    ui->eyepassword_hide_register->hide();
    ui->eyepassword_view_register->show();
    ui->password_input_register->setEchoMode(QLineEdit::Password);
}


void SellerWindow::on_eyepassword_view_register_clicked()
{
    ui->eyepassword_view_register->hide();
    ui->eyepassword_hide_register->show();
    ui->password_input_register->setEchoMode(QLineEdit::Normal);
}


void SellerWindow::on_eyepassword_hide_login_clicked()
{
    ui->eyepassword_hide_login->hide();
    ui->eyepassword_view_login->show();
    ui->password_input_login->setEchoMode(QLineEdit::Password);
}


void SellerWindow::on_eyepassword_view_login_clicked()
{
    ui->eyepassword_view_login->hide();
    ui->eyepassword_hide_login->show();
    ui->password_input_login->setEchoMode(QLineEdit::Normal);
}


void SellerWindow::on_profile_photo_image_clicked()
{
    profile_photo_image = QFileDialog::getOpenFileName(this,tr("Open File"),"C://","JPG IMAGE (*.jpg);; JPEG IMAGE (*.jpeg);; PNG IMAGE (*.png)");
}


void SellerWindow::on_add_products_now_clicked()
{
    ui->add_product->setStyleSheet("background-color:#BD1616 ;color: #ffffff;font-weight: bold;font-size:15px;border-radius:5px;");
    ui->home_btn->setStyleSheet("color: #000000;font-weight: bold;");
    ui->view_products->setStyleSheet("color: #000000;font-weight: bold;");
    ui->profile_stting_btn->setStyleSheet("color: #000000;font-weight: bold;");
    ui->stackedWidget_2->setCurrentIndex(1);
}


void SellerWindow::on_home_btn_clicked()
{
    ui->home_btn->setStyleSheet("background-color:#BD1616 ;color: #ffffff;font-weight: bold;font-size:15px;border-radius:5px;");
    ui->add_product->setStyleSheet("color: #000000;font-weight: bold;");
    ui->view_products->setStyleSheet("color: #000000;font-weight: bold;");
    ui->profile_stting_btn->setStyleSheet("color: #000000;font-weight: bold;");
    ui->stackedWidget_2->setCurrentIndex(0);
}

float SellerWindow::calc_accbalance(){
    QString seller_username = QString::fromStdString(seller[seller_index].username);
    QSqlQuery query;
    query.prepare("SELECT product_price , product_quantity FROM orders_data WHERE product_seller = :product_seller");
    query.bindValue(":product_seller",seller_username);
    query.exec();
    float acc_balance = 0;
    while(query.next()){
        float product_price = query.value(0).toString().toFloat();
        int product_quantity = query.value(1).toString().toInt();
        acc_balance += (product_price * product_quantity);
    }
    return acc_balance;
}

void SellerWindow::on_agreements_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void SellerWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void SellerWindow::on_comboBox_category_currentIndexChanged(int index)
{
    if (!(index == 2 || index == 4)){
        ui->label_43->hide();
        ui->dateEdit->hide();
    }
    else{
        ui->label_43->show();
        ui->dateEdit->show();
    }
}


void SellerWindow::on_back_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

