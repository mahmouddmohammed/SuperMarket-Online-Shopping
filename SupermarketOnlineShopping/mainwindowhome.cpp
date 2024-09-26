#include "mainwindowhome.h"
#include "ui_mainwindowhome.h"
#include "mainwindowlogin.h"
#include "mainwindow.h"
#include <QStackedWidget>
#include <QWidget>
#include <QVBoxLayout>
#include "main_.h"
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

bool layout_check = false;
order order_products;
int counter_products = 0;
int videogames_counter = 0;
string videogames_keys[100];
bool coupon_once = false;

MainWindowHome::MainWindowHome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowHome)
{
    ui->setupUi(this);
    setWindowTitle("Home");
    setWindowIcon(QIcon(":/imgs/login_page/iconofshopping.svg"));
    ui->welcome->setText("Welcome, " + QString::fromStdString(customer[user_index].name));
    completer_forinput();
    order order_products;
    int counter_products = 0;
    QString name_page[7] = {"Electronics","VideoGames","Groceries","Beauty","Home_Furniture","Office","SportsSupplies"};
    QString scroll_area_containers[7] = {"ui->scrollContentContainer",};
    show_products(name_page);
    ui->dashboard_btn->setStyleSheet("background-color: #F6EF98; color: #112f91");
    view_dashboard();
}

MainWindowHome::~MainWindowHome()
{
    delete ui;

}

void MainWindowHome::show_products(QString nameofpages[]){
    QWidget* scroll_area_containers[7] = {ui->scrollContentContainer,ui->scrollContentContainer_7,ui->scrollContentContainer_3,ui->scrollContentContainer_5,ui->scrollContentContainer_2,ui->scrollContentContainer_4,ui->scrollContentContainer_6};
    QWidget *category_productpage;
    QWidget *scrollarea_container;
    QWidget *productContainers;
    QVBoxLayout *layout_forpage;
    QVBoxLayout *layout_forscrollareacontainer;
    QGridLayout *layout_forallproductscardscontainer;

    for (int i = 0 ; i < 7;i++){
        category_productpage = ui->pages->findChild<QWidget*>(nameofpages[i]);
        scrollarea_container = scroll_area_containers[i];
        productContainers = new QWidget(scrollarea_container);
        layout_forpage = new QVBoxLayout(category_productpage);
        layout_forscrollareacontainer = new QVBoxLayout(scrollarea_container);
        layout_forallproductscardscontainer = new QGridLayout(productContainers);
        QString product_rating;
        int no_products = noproducts_incategories[i];
        for (int j = 0;j<no_products;j++){
            // Create product widget
            QWidget* productWidget = new QWidget();
            QVBoxLayout* productLayout = new QVBoxLayout();
            productWidget->setLayout(productLayout);

            QLabel* nameLabel = new QLabel("Product # " + QString::number(j+1),productWidget);
            QLabel* imageLabel = new QLabel();
            imageLabel->setPixmap(QPixmap(category[i].products[j].image_url));
            imageLabel->setScaledContents(true);
            imageLabel->setFixedSize(250, 350);
            QLabel *product_id = new QLabel("ID: " + QString::fromStdString(category[i].products[j].id),productWidget);
            QLabel *name_product = new QLabel("Name: " + QString::fromStdString(category[i].products[j].name),productWidget);
            QLabel* priceLabel = new QLabel("Price: " + QString::number(category[i].products[j].price) + "$",productWidget);
            QLabel* productiondate;
            QLabel* expirationdate;
            if (i == 2 || i==4){
                productiondate = new QLabel("Production Date: " + QString::fromStdString(category[i].products[j].production_date),productWidget);
                expirationdate = new QLabel("Expiration Date: " + QString::fromStdString(category[i].products[j].expiration_date),productWidget);
            }
            QLabel* product_seller = new QLabel("Seller: " + QString::fromStdString(category[i].products[j].seller),productWidget);

            QLabel* rating_product = new QLabel("Rating: " + QString::number(category[i].products[j].rating) + "/5" , productWidget);

            QWidget* quantity_container = new QWidget();
            QGridLayout *quantity_container_layout = new QGridLayout();
            quantity_container_layout->setContentsMargins(0, 0, 0, 0); // to remove the margins
            quantity_container->setLayout(quantity_container_layout);
            QLabel* quantity = new QLabel("Quantity You want to buy: ");
            QSpinBox *muchquantity = new QSpinBox();
            muchquantity->setRange(1,category[i].products[j].stock);
            muchquantity->setFixedWidth(250);
            quantity_container_layout->addWidget(quantity,0,0);
            quantity_container_layout->addWidget(muchquantity,0,1);

            QPushButton* addButton = new QPushButton("Add to Cart",productWidget);
            addButton->setFixedHeight(45);
            addButton->setStyleSheet("background-color: green;font-weight:bold;color:white;");
            productWidget ->setStyleSheet("QLabel{font-weight: bold;}");
            productLayout->addWidget(nameLabel);
            productLayout->addWidget(imageLabel);
            productLayout->addWidget(product_id);
            productLayout->addWidget(name_product);
            productLayout->addWidget(product_seller);
            if (i == 2 || i==4){
                productLayout->addWidget(productiondate);
                productLayout->addWidget(expirationdate);
            }
            productLayout->addWidget(priceLabel);
            productLayout->addWidget(rating_product);
            productLayout->addWidget(quantity_container);
            productLayout->addWidget(addButton);

            layout_forallproductscardscontainer->addWidget(productWidget, j/2, j%2);
            connect(addButton, &QPushButton::clicked, [=]() {
                // Handle button click event
                // to not add same product two times
                for (int k = 0 ; k < counter_products;k++){
                    if (order_products.products_names[k] == category[i].products[j].name){
                        order_products.products_quantities[k] += muchquantity->value();
                        return;
                    }
                }
                order_products.CustomerID = customer[user_index].id;
                order_products.products_codes[counter_products] = category[i].products[j].id;
                order_products.products_names[counter_products] = category[i].products[j].name;
                order_products.product_images[counter_products] = category[i].products[j].image_url;
                order_products.products_prices[counter_products] =category[i].products[j].price;
                order_products.products_quantities[counter_products] = muchquantity->value();
                order_products.products_categories[counter_products] = category[i].products[j].category;
                order_products.product_seller[counter_products] = category[i].products[j].seller;
                counter_products++;

            });

        }
        productContainers->setObjectName("productContainers");
        productContainers->setStyleSheet("QWidget#productContainers > * {border: 1px solid black;background-color: white;border-radius:5px;}");
        layout_forscrollareacontainer->addWidget(productContainers);
    }
}


void MainWindowHome::show_cart(){
    order_products.cartID = Product_RandomID(1000,9000);
    QWidget *category_productpage , *scrollarea_container ,*productContainers;


    category_productpage = ui->pages->findChild<QWidget*>("cart");

    scrollarea_container = ui->scrollContentContainer_8;
    productContainers = new QWidget(scrollarea_container);

    QLayout *existingLayoutforscroll = scrollarea_container->layout();
    if (existingLayoutforscroll != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayoutforscroll->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        delete existingLayoutforscroll;
    }
    QVBoxLayout *layout_forscrollareacontainer = new QVBoxLayout(scrollarea_container);
    QGridLayout *layout_forallproductscardscontainer = new QGridLayout(productContainers);

    productContainers->setObjectName("productContainers");
    // -----------------------------------------------------------------------
    // to check if the user didn't buy any product , show there is no products to show yet
    if (counter_products == 0){
        QLabel *none_product = new QLabel("You havent bought any product yet");
        layout_forscrollareacontainer->addWidget(none_product);
        return;
    }
    bool product_check = false;
    for (int m = 0; m < counter_products ; m++){
        if (order_products.products_names[m]!="")
            product_check = true;
    }

    if (!product_check){

        QLabel *none_product = new QLabel("You havent bought any product yet");
        layout_forscrollareacontainer->addWidget(none_product);
        return;
    }
    // -----------------------------------------------------------------------
    int productIndex = 0;
    for (int i = 0,j = 0; i < counter_products ; i++,j++){
        if (order_products.products_names[i] == "") {
            if (i != 0) {
                j = i - 1;
            }

            continue;
        }

        QWidget* productWidget = new QWidget();
        QVBoxLayout* productLayout = new QVBoxLayout();
        productWidget->setLayout(productLayout);

        QLabel* nameLabel = new QLabel("Product # " + QString::number(productIndex+1),productWidget);
        QLabel* imageLabel = new QLabel();
        imageLabel->setPixmap(QPixmap(order_products.product_images[i]));
        imageLabel->setScaledContents(true); // Scales the pixmap to fit the size of the QLabel
        imageLabel->setFixedSize(200, 300);
        imageLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QLabel *product_id = new QLabel(QString::fromStdString("Product ID: " + order_products.products_codes[i]),productWidget);
        product_id->setAlignment(Qt::AlignCenter);
        QLabel *name_product = new QLabel(QString::fromStdString("Product Name: " + order_products.products_names[i]),productWidget);
        name_product->setAlignment(Qt::AlignCenter);
        QLabel *name_category = new QLabel(QString::fromStdString("Category: " + order_products.products_categories[i]),productWidget);
        name_category->setAlignment(Qt::AlignCenter);
        QLabel* priceLabel = new QLabel("Price for each: " + QString::number(order_products.products_prices[i]) + "$",productWidget);
        priceLabel->setAlignment(Qt::AlignCenter);
        QLabel *no_of_quantities = new QLabel("No of quantities: " + QString::number(order_products.products_quantities[i]),productWidget);
        no_of_quantities->setAlignment(Qt::AlignCenter);
        QLabel* product_seller = new QLabel("Seller: " + QString::fromStdString(order_products.product_seller[i]),productWidget);
        product_seller->setAlignment(Qt::AlignCenter);
        // ----------------------------
        QWidget* quantity_container = new QWidget(productWidget);
        QGridLayout *quantity_container_layout = new QGridLayout();
        quantity_container->setLayout(quantity_container_layout);
        QLabel* new_quantity = new QLabel("Quantity You want: ");
        new_quantity->setMaximumWidth(100);
        QSpinBox *muchnew_quantity = new QSpinBox();
        muchnew_quantity->setRange(1,100);
        muchnew_quantity->setValue(order_products.products_quantities[i]);
        muchnew_quantity->setMaximumWidth(200);
        muchnew_quantity->setFixedHeight(30);
        muchnew_quantity->clearFocus();
        muchnew_quantity->clearMask();
        QPushButton *remove_product = new QPushButton("X");
        remove_product->setStyleSheet("color: white;background-color: #F10000;font-size:20px;font-weight:bold;");
        remove_product->setFixedHeight(20);
        remove_product->setFixedWidth(20);
        quantity_container_layout->addWidget(new_quantity,0,0);
        quantity_container_layout->addWidget(muchnew_quantity,0,1);
        quantity_container_layout->addWidget(remove_product,0,2);


        //-----------------------------
        // apply coupon
        QWidget* coupon_container = new QWidget(productWidget);
        QGridLayout *coupon_container_layout = new QGridLayout();
        coupon_container->setLayout(coupon_container_layout);

        QLineEdit *write_coupon = new QLineEdit(coupon_container);
        write_coupon->setPlaceholderText("Write the coupon");
        write_coupon->setFixedHeight(50);

        QPushButton *addcoupon = new QPushButton("Add Coupon",coupon_container);
        addcoupon->setStyleSheet("font-weight: bold; color:white; background-color: green;font-size:20px;");
        addcoupon->setMaximumWidth(135);
        addcoupon->setFixedHeight(50);



        coupon_container_layout->addWidget(write_coupon,0,0);
        coupon_container_layout->addWidget(addcoupon,0,1);

        //-------------------------------
        // make label without text and set text with red color if the coupon is right and tell them hykhsm kam
        QLabel *coupon_discount = new QLabel(productWidget);
        //----------------------
        connect(muchnew_quantity,&QSpinBox::valueChanged,[=]()mutable{
            no_of_quantities->setText("No of quantities: " + QString::number(muchnew_quantity->value()));
            order_products.products_quantities[i] = muchnew_quantity->value();
        });

        connect (remove_product,&QPushButton::clicked,[=](){
            order_products.products_names[i] = "";
            order_products.products_categories[i] = "";
            order_products.products_codes[i] = "";
            order_products.products_prices[i] = 0;
            delete productWidget;
            show_cart();
        });

        connect (addcoupon,&QPushButton::clicked,[=](){
            if (coupon_once){
                QMessageBox::critical(this,"Sorry","You only can add one coupon per checkout");
                return;
            }
            QString couponn_text = write_coupon->text();
            if (couponn_text.isEmpty()){
                QMessageBox::critical(this,"Sorry","You dont enter any coupon");
                return;
            }

            for (int m = 0; m < no_coupons; m++){
                if (couponn_text.toStdString() == coupon[m].the_coupon){
                    order_products.apply_coupon[i] = true;
                    order_products.coupon_text[i] = coupon[m].the_coupon;
                    order_products.coupon_discount[i] = coupon[m].the_coupon_value;
                    break;
                }
            }

            if (order_products.apply_coupon[i]){
                coupon_discount->setText("Congratulations,Coupon discount: " + QString::number(order_products.coupon_discount[i]));
                coupon_discount->setStyleSheet("font-weight:bold;color: green;font-size:15px;");
                coupon_once = true;

            }
            else{
                coupon_discount->setText("Coupon is wrong");
                coupon_discount->setStyleSheet("font-weight:bold;color: red;font-size:15px;");
                write_coupon->clear();
                write_coupon->clearFocus();
            }

        });
        productLayout->addWidget(nameLabel);
        productLayout->addWidget(imageLabel);
        productLayout->addWidget(product_id);
        productLayout->addWidget(name_product);
        productLayout->addWidget(name_category);
        productLayout->addWidget(priceLabel);
        productLayout->addWidget(product_seller);
        productLayout->addWidget(no_of_quantities);
        productLayout->addWidget(quantity_container);
        productLayout->addWidget(coupon_container);
        productLayout->addWidget(coupon_discount);

        productContainers->setStyleSheet("QWidget#productContainers > * {border: 1px solid black;}");
        layout_forallproductscardscontainer->addWidget(productWidget, productIndex/3, productIndex%3);
        productIndex++;

    }
    float row = counter_products*0.333;
    row = ceil(row) ;

    QPushButton *CheckOut = new QPushButton("Checkout");
    CheckOut->setFixedHeight(60);
    CheckOut->setStyleSheet("background-color: green;border-radius: 5px;");
    layout_forallproductscardscontainer->addWidget(CheckOut,row,0,1,3);
    connect(CheckOut, &QPushButton::clicked, [=](){
        ui->pages->setCurrentIndex(10);
        ui->visa_pay_container->hide();
        int fake_counter_products = 0;
        float total_price = 0; //before discount
        for (int i = 0;i< counter_products;i++){
            if (order_products.products_names[i] == ""){
                fake_counter_products++;
                continue;
            }

            if (order_products.apply_coupon[i]){
                if ((order_products.products_quantities[i]* order_products.products_prices[i]) > order_products.coupon_discount[i]){
                    total_price += (order_products.products_quantities[i]* order_products.products_prices[i]) - order_products.coupon_discount[i];
                }
                else{
                    continue;
                }

            }
            else{
                total_price += (order_products.products_quantities[i]* order_products.products_prices[i]);
            }

        }
        int real_counter_products = counter_products - fake_counter_products;

        int much_discount ;
        float total_price_after_discount = price_after_discount(real_counter_products,total_price,much_discount);
        ui->name_label->setText(QString::fromStdString(customer[user_index].name));
        ui->phone_label->setText(QString::fromStdString(customer[user_index].phone_number));
        ui->Location->setText(QString::fromStdString(customer[user_index].address));
        ui->cart_id->setText(QString::fromStdString(order_products.cartID));
        ui->discount->setText(QString::number(much_discount)+"%");
        ui->price_before->setText(QString::number(total_price)+"$");
        ui->price_after->setText(QString::number(total_price_after_discount)+"$");

        ui->visa_pay_btn->setText("Pay "+QString::number(total_price_after_discount)+"$");

        QString user_id = QString::number(customer[user_index].id);
        QString productName;
        QString productCategory;
        QString productQuantity;
        QString productPrice;
        QString productCode;
        QString productSeller;
        QString productImage;

        QSqlQuery query;
        for (int i = 0;i < counter_products;i++){
            for (int j = 0; j < no_ofpreviousorderedproducts;j++){
                if (order_products.products_names[i] == previous_orderedproducts.product_names[j]){
                    previous_orderedproducts.product_quantities[j]+=order_products.products_quantities[i];
                    query.prepare("UPDATE orders_data SET product_quantity = :product_quantity WHERE user_id = :user_id AND product_code = :product_id");
                    query.bindValue(":user_id",customer[user_index].id);
                    query.bindValue(":product_id",QString::fromStdString(previous_orderedproducts.product_codes[j]));
                    query.bindValue(":product_quantity",previous_orderedproducts.product_quantities[j]);
                    query.exec();
                    order_products.products_names[i] = "";

                }
            }
            if (order_products.products_names[i] == ""){
                fake_counter_products++;
                continue;
            }


            //Previous orders
            productName = QString::fromStdString(order_products.products_names[i]);
            productCategory = QString::fromStdString(order_products.products_categories[i]);
            productPrice = QString::number(order_products.products_prices[i]);
            productQuantity = QString::number(order_products.products_quantities[i]);
            productCode = QString::fromStdString(order_products.products_codes[i]);
            productSeller = QString::fromStdString(order_products.product_seller[i]);
            productImage = order_products.product_images[i];

            previous_orderedproducts.product_names[no_ofpreviousorderedproducts] = productName.toStdString();
            previous_orderedproducts.product_categories[no_ofpreviousorderedproducts] = productCategory.toStdString();
            previous_orderedproducts.product_codes[no_ofpreviousorderedproducts] = productCode.toStdString();
            previous_orderedproducts.product_prices[no_ofpreviousorderedproducts] = productPrice.toFloat();
            previous_orderedproducts.product_quantities[no_ofpreviousorderedproducts] = productQuantity.toInt();
            previous_orderedproducts.product_sellers[no_ofpreviousorderedproducts] = productSeller.toStdString();
            previous_orderedproducts.product_images[no_ofpreviousorderedproducts] = productImage;
            no_ofpreviousorderedproducts++;

            query.prepare("INSERT INTO orders_data (user_id, product_name, product_category , product_code , product_price , product_quantity , product_seller , product_image) VALUES (:user_id, :product_names, :product_categories , :product_codes, :product_prices, :product_quantities, :product_sellers, :product_images)");
            query.bindValue(":user_id", user_id);
            query.bindValue(":product_names", productName);
            query.bindValue(":product_categories", productCategory);
            query.bindValue(":product_codes", productCode);
            query.bindValue(":product_quantities", productQuantity);
            query.bindValue(":product_prices", productPrice);
            query.bindValue(":product_sellers", productSeller);
            query.bindValue(":product_images", productImage);
            if(!query.exec()){
                qDebug() << query.lastError().text();
            }

        }
        order_products.cartID="";
        for (int j = 0;j<counter_products;j++){
            order_products.products_names[j] = "";
            order_products.products_categories[j] = "";
            order_products.products_codes[j] = "";
            order_products.products_prices[j] = 0;
        }
    });
    layout_forscrollareacontainer->addWidget(productContainers);
}

void MainWindowHome::on_category_btn_clicked()
{

    ui->category_btn->setStyleSheet("background-color: #F6EF98; color: #112f91");
    ui->dashboard_btn->setStyleSheet("");
    ui->profile_btn->setStyleSheet("");
    ui->cart_btn->setStyleSheet("");
    ui->previous_orders_btn->setStyleSheet("");
    ui->sellers_btn->setStyleSheet("");
    ui->coupons_btn->setStyleSheet("");
    ui->pages->setCurrentIndex(1);

}

void MainWindowHome::on_Electronics_btn_clicked()
{
    ui->pages->setCurrentIndex(2);
}


void MainWindowHome::on_VideoGamesbtn_clicked()
{
    ui->pages->setCurrentIndex(3);
}


void MainWindowHome::on_Groceries_btn_clicked()
{
    ui->pages->setCurrentIndex(4);
}


void MainWindowHome::on_Beautybtn_clicked()
{
    ui->pages->setCurrentIndex(5);
}


void MainWindowHome::on_Officebtn_clicked()
{
    ui->pages->setCurrentIndex(6);
}


void MainWindowHome::on_HomeFurniturebtn_clicked()
{
    ui->pages->setCurrentIndex(7);
}


void MainWindowHome::on_SportsSupplies_clicked()
{
    ui->pages->setCurrentIndex(8);
}




void MainWindowHome::on_cart_btn_clicked()
{
    ui->cart_btn->setStyleSheet("background-color: #F6EF98; color: #112f91");
    ui->dashboard_btn->setStyleSheet("");
    ui->category_btn->setStyleSheet("");
    ui->profile_btn->setStyleSheet("");
    ui->previous_orders_btn->setStyleSheet("");
    ui->sellers_btn->setStyleSheet("");
    ui->coupons_btn->setStyleSheet("");
    ui->pages->setCurrentIndex(9);
    show_cart();

}


void MainWindowHome::on_logout_btn_clicked()
{
    reorder_information();
    MainWindow *logout = new MainWindow();
    hide();
    logout->show();
}





void MainWindowHome::on_profile_btn_clicked()
{
    ui->profile_btn->setStyleSheet("background-color: #F6EF98; color: #112f91");

    ui->dashboard_btn->setStyleSheet("");
    ui->category_btn->setStyleSheet("");
    ui->cart_btn->setStyleSheet("");
    ui->previous_orders_btn->setStyleSheet("");
    ui->sellers_btn->setStyleSheet("");
    ui->coupons_btn->setStyleSheet("");


    ui->pages->setCurrentIndex(12);
    QWidget *profilepage = ui->pages->findChild<QWidget*>("profile_setting");
    QWidget *scrollarea_container = ui->scrollContentContainer_11;
    QWidget *Containerofcards = new QWidget(scrollarea_container);
    Containerofcards->setObjectName("cardsContainer");
    //--------------------------------------------------------------------
    QLayout *existingLayout = profilepage->layout();
    if (existingLayout != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        delete existingLayout;
    }


    QLayout *existingLayoutforscroll = scrollarea_container->layout();
    if (existingLayoutforscroll != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayoutforscroll->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        delete existingLayoutforscroll;
    }

    QLayout *existingLayoutforcardscontainer = Containerofcards->layout();
    if (existingLayoutforcardscontainer != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayoutforcardscontainer->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        delete existingLayoutforcardscontainer;
    }
    //--------------------------------------------------------
    //Creating Layouts
    QVBoxLayout *layout_forpage = new QVBoxLayout(profilepage);
    QVBoxLayout *layout_forscrollareacontainer = new QVBoxLayout(scrollarea_container);
    QGridLayout *layout_forallcardscontainer = new QGridLayout(Containerofcards);
    QString labels[5] = {"Name","Email","Password","Phone Number","Location"};

    for (int i = 0;i<5;i++){
        QWidget *card_container = new QWidget(Containerofcards);
        QVBoxLayout *card_layout = new QVBoxLayout(card_container);
        whatuser_change[i] = new QLabel(labels[i],card_container);
        whatuser_change[i]->setStyleSheet("text-align:center;font-size: 30px;font-weight: bold;color: #112f91;");
        whatuser_change[i]->setAlignment(Qt::AlignCenter);
        whatuser_change[i]->setFixedHeight(25);
        btn_change[i] = new QPushButton("Change",card_container);
        btn_change[i]->setStyleSheet("background-color: #1B7FBD;opacity: 80%;color:white;font-weight:bold;");
        update_input[i] = new QLineEdit(card_container);
        update_input[i]->hide();
        update_confirm[i] = new QPushButton("Confirm",card_container);
        update_confirm[i]->setStyleSheet("background-color: green;color: white;font-weight: bold;font-size: 30px;");
        update_confirm[i]->hide();
        card_container->setFixedWidth(450);
        card_container->setFixedHeight(250);
        if (i == 2)
            update_input[i]->setEchoMode(QLineEdit::Password);
        connect (btn_change[i],&QPushButton::clicked,[=](){
            update_input[i]->setFixedHeight(30);
            update_confirm[i]->setFixedHeight(50);
            update_input[i]->show();
            update_confirm[i]->show();
            for (int j = 0;j < 5;j++)
                btn_change[j]->setEnabled(false);
            connect(update_confirm[i],&QPushButton::clicked,[=]{
                if (i == 0){
                    if (update_input[i]->text().isEmpty() || update_input[i]->text().toStdString()[0] == 32){
                        QMessageBox::critical(this,"Error","You must fill the input");
                        return;
                    }
                    update_confirm[i]->setEnabled(false);
                    customer[user_index].name = update_input[i]->text().toStdString();
                    QSqlQuery query;
                    query.prepare("UPDATE users_data SET full_name = :newName WHERE id = :id");
                    query.bindValue(":id", QString::number(customer[user_index].id));
                    query.bindValue(":newName", QString::fromStdString(customer[user_index].name));

                    if(query.exec()){
                        ui->welcome->setText("Welcome, " + QString::fromStdString(customer[user_index].name));
                        QMessageBox::information(this,"Success","You have changed your name successfully");
                    }
                    else
                        qDebug() << "db is not updated with name new value";

                }
                else if (i==1){
                    if (update_input[i]->text().isEmpty() || update_input[i]->text().toStdString()[0] == 32){
                        QMessageBox::critical(this,"Error","You must fill the input");
                        return;
                    }
                    string email = update_input[i]->text().toStdString();
                    bool email_check = email_checking(email);
                    if (email_check){
                        update_confirm[i]->setEnabled(false);
                        customer[user_index].email = email;
                        QSqlQuery query;
                        query.prepare("UPDATE users_data SET email = :email WHERE id = :id");
                        query.bindValue(":id", QString::number(customer[user_index].id));
                        query.bindValue(":email", QString::fromStdString(customer[user_index].email));

                        if(query.exec()){
                            QMessageBox::information(this,"Success","You have changed your email successfully");
                            QMessageBox::information(this,"Login","Please Login Again for security");
                            hide();
                            MainWindowLogin *login_page = new MainWindowLogin(); // we call the constructor to build shakl page ely katbenh feha lw blcode
                            login_page->show();
                        }
                        else
                            qDebug() << "db is not updated with email new value";

                    }
                    else{
                        QMessageBox::critical(this,"Wrong","Wrong Format Email");
                        return; // it is for lambda function not for the slot function of profile setting
                    }

                }
                else if (i==2){

                    if (update_input[i]->text().isEmpty() || update_input[i]->text().toStdString()[0] == 32){
                        QMessageBox::critical(this,"Error","You must fill the input");
                        return;
                    }
                    string password = update_input[i]->text().toStdString();
                    bool password_check  = password_checking(password);
                    if (password_check){
                        update_confirm[i]->setEnabled(false);
                        customer[user_index].password = password;
                        QSqlQuery query;
                        query.prepare("UPDATE users_data SET password = :password WHERE id = :id");
                        query.bindValue(":id", QString::number(customer[user_index].id));
                        query.bindValue(":password", QString::fromStdString(customer[user_index].password));

                        if(query.exec()){
                            QMessageBox::information(this,"Success","You have changed your password successfully");
                            QMessageBox::information(this,"Login","Please Login Again for security");
                            hide();
                            MainWindowLogin *login_page = new MainWindowLogin(); // we call the constructor to build shakl page ely katbenh feha lw blcode
                            login_page->show();
                        }
                        else
                            qDebug() << "db is not updated with password new value";


                    }
                    else {
                        QMessageBox::critical(this,"Wrong","Sorry Password must be 8 or more than 8 characters");
                        return;
                    }
                }
                else if (i==3){
                    if (update_input[i]->text().isEmpty() || update_input[i]->text().toStdString()[0] == 32){
                        QMessageBox::critical(this,"Error","You must fill the input");
                        return;
                    }
                    string phone_number = update_input[i]->text().toStdString();
                    bool phone_number_check = phonenumber_checking(phone_number);
                    if (phone_number_check){
                        update_confirm[i]->setEnabled(false);
                        customer[user_index].phone_number = phone_number;
                        QSqlQuery query;
                        query.prepare("UPDATE users_data SET phone_number = :phone_number WHERE id = :id");
                        query.bindValue(":id", QString::number(customer[user_index].id));
                        query.bindValue(":phone_number", QString::fromStdString(customer[user_index].phone_number));

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
                else if (i==4){

                    if (update_input[i]->text().isEmpty() || update_input[i]->text().toStdString()[0] == 32){
                        QMessageBox::critical(this,"Error","You must fill the input");
                        return;
                    }
                    update_confirm[i]->setEnabled(false);
                    customer[user_index].address = update_input[i]->text().toStdString();
                    QSqlQuery query;
                    query.prepare("UPDATE users_data SET address = :location WHERE id = :id");
                    query.bindValue(":id", QString::number(customer[user_index].id));
                    query.bindValue(":location", QString::fromStdString(customer[user_index].address));

                    if(query.exec())
                        QMessageBox::information(this,"Success","You have changed your address successfully");
                    else
                        qDebug() << "db is not updated with address new value";
                }
            });


        });
        card_container->setStyleSheet("QWidget#cardsContainer > * {border-width:2px;border-color:#112f91;border-style:solid;background-color: #fcfcfc;border-radius: 10px;}");
        card_layout->addWidget(whatuser_change[i]);
        card_layout->addWidget(btn_change[i]);
        card_layout->addWidget(update_input[i]);
        card_layout->addWidget(update_confirm[i]);
        layout_forallcardscontainer->addWidget(card_container, i/2, i%2);

    }
    layout_forscrollareacontainer->addWidget(Containerofcards);
}

void MainWindowHome::on_dashboard_btn_clicked()
{
    view_dashboard();
    ui->dashboard_btn->setStyleSheet("background-color: #F6EF98; color: #112f91");
    ui->profile_btn->setStyleSheet("");
    ui->category_btn->setStyleSheet("");
    ui->cart_btn->setStyleSheet("");
    ui->previous_orders_btn->setStyleSheet("");
    ui->sellers_btn->setStyleSheet("");
    ui->coupons_btn->setStyleSheet("");
    ui->pages->setCurrentIndex(0);

}

void MainWindowHome::completer_forinput(){
    QStringList products;
    for (int i = 0 ; i < 7;i++){
        for (int j = 0;j < 10;j++){
            products << QString::fromStdString(category[i].products[j].name);
        }
    }
    QCompleter *completer = new QCompleter(products);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    ui->searchproductname_input->setCompleter(completer);
}


void MainWindowHome::on_previous_orders_btn_clicked()
{
    ui->previous_orders_btn->setStyleSheet("background-color: #F6EF98; color: #112f91");
    ui->dashboard_btn->setStyleSheet("");
    ui->category_btn->setStyleSheet("");
    ui->cart_btn->setStyleSheet("");
    ui->profile_btn->setStyleSheet("");
    ui->sellers_btn->setStyleSheet("");
    ui->coupons_btn->setStyleSheet("");
    ui->pages->setCurrentIndex(11);
    viewpreviousorders();
}



void MainWindowHome::on_sellers_btn_clicked()
{
    ui->sellers_btn->setStyleSheet("background-color: #F6EF98; color: #112f91");
    ui->previous_orders_btn->setStyleSheet("");
    ui->dashboard_btn->setStyleSheet("");
    ui->category_btn->setStyleSheet("");
    ui->cart_btn->setStyleSheet("");
    ui->profile_btn->setStyleSheet("");
    ui->coupons_btn->setStyleSheet("");

    ui->pages->setCurrentIndex(13);
    //Show the products in the cards
    QWidget *seller_page , *scrollarea_container ,*sellersContainers;


    seller_page = ui->pages->findChild<QWidget*>("sellers_page");

    scrollarea_container = ui->scrollAreaWidgetContents_2;
    sellersContainers = new QWidget(scrollarea_container);

    QLayout *existingLayout = seller_page->layout();
    if (existingLayout != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        delete existingLayout;
    }


    QLayout *existingLayoutforscroll = scrollarea_container->layout();
    if (existingLayoutforscroll != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayoutforscroll->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        delete existingLayoutforscroll;
    }

    QLayout *existingLayoutforproductcontainer = sellersContainers->layout();
    if (existingLayoutforproductcontainer != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayoutforproductcontainer->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        delete existingLayoutforproductcontainer;
    }

    QVBoxLayout *layout_forsellerpage = new QVBoxLayout(seller_page);
    QVBoxLayout *layout_forscrollareacontainer = new QVBoxLayout(scrollarea_container);
    QGridLayout *layout_forsellerscontainer = new QGridLayout(sellersContainers);

    if (no_sellers == 0){
        QLabel *zero_seller = new QLabel("We dont have any sellers yet");
        layout_forscrollareacontainer->addWidget(zero_seller);
        return;
    }

    for (int i = 0; i < no_sellers;i++){
        QWidget *seller_container = new QWidget();
        QVBoxLayout* sellerLayout = new QVBoxLayout(); // details inside each card (product)
        seller_container->setLayout(sellerLayout);

        QLabel* seller_number = new QLabel("Seller #" +  QString::number(i+1) ,seller_container);
        QLabel* profile_image = new QLabel();
        profile_image->setPixmap(QPixmap(seller[i].profile_photo));
        profile_image->setScaledContents(true); // Scales the pixmap to fit the size of the QLabel
        profile_image->setFixedSize(150, 150);
        QLabel *seller_id = new QLabel("Seller ID:# " + QString::number(seller[i].id),seller_container);
        QLabel *seller_name = new QLabel(QString::fromStdString("Name: : " + seller[i].name),seller_container);
        QLabel *seller_username = new QLabel(QString::fromStdString("Username: " + seller[i].username),seller_container);
        QLabel* no_of_products = new QLabel("No of products: " + QString::number(seller[i].no_products),seller_container);

        QLabel *no_of_subsribers = new QLabel("No of subsribers: " + QString::number(seller[i].no_of_subscribers),seller_container);


        QPushButton *subscribe_btn_off = new QPushButton("Subscribe",seller_container);
        subscribe_btn_off->setStyleSheet("background-color: red; color:white; font-weight: bold; font-size: 25px;border-radius: 15px;");

        QPushButton *subscribe_btn_on = new QPushButton("Subscribed",seller_container);
        subscribe_btn_on->setStyleSheet("background-color: #454545; color:white; font-weight: bold; font-size: 30px;border-radius: 5px;border-color:#FF6000;border-width:2px; border-style: solid;");
        subscribe_btn_on->setFixedHeight(45);
        subscribe_btn_on->hide();
        seller_container->setObjectName("product_card");

        seller_container->setStyleSheet("QLabel{font-weight:bold;color:#11405C;}");

        //To check if this user subscribed to seller before
        bool subscribe_check = false;
        QSqlQuery query;
        query.prepare("SELECT id_seller FROM sellers_customers WHERE id_subscribed_customer = :customer_id");
        query.bindValue(":customer_id",customer[user_index].id);
        query.exec();
        while (query.next()){ //byshof id of sellers ely customer ely 3amel login 3amlha subscribe
            if (seller[i].id == query.value(0).toString().toInt())
                subscribe_check = true;
        }
        if(subscribe_check){
            subscribe_btn_off->hide();
            subscribe_btn_on->show();
        }


        connect (subscribe_btn_off,&QPushButton::clicked,[=](){
            subscribe_btn_off->hide();
            subscribe_btn_on->show();
            seller[i].no_of_subscribers++;
            // increment no of subscribers and store it in db w change it in struct of seller
            // store subscribed user id and the seller in data base , then fetch it in main_ to store subscribers in array of struct user by id
            QSqlQuery query;
            query.prepare("INSERT INTO sellers_customers (id_seller,id_subscribed_customer) VALUES (:seller_id , :customer_id)");
            query.bindValue(":seller_id",seller[i].id);
            query.bindValue(":customer_id",customer[user_index].id);
            if (query.exec()){
                    query.prepare("UPDATE sellers_data SET no_subscribers = :no_subscribers WHERE id = :seller_id");
                    query.bindValue(":no_subscribers",seller[i].no_of_subscribers);
                    query.bindValue(":seller_id",seller[i].id);
                    query.exec();
                    //updateseller_subscribers();
                    //updatecustomer_sellerssubscribedto();
                    no_of_subsribers->setText("No of subsribers: " + QString::number(seller[i].no_of_subscribers));

            }

        });



        connect (subscribe_btn_on,&QPushButton::clicked,[=](){
            subscribe_btn_on->hide();
            subscribe_btn_off->show();
            seller[i].no_of_subscribers--;
            QSqlQuery query;
            query.prepare("DELETE FROM sellers_customers WHERE id_seller = :seller_id AND id_subscribed_customer = :customer_id");
            query.bindValue(":seller_id",seller[i].id);
            query.bindValue(":customer_id",customer[user_index].id);
            if (query.exec()){
                query.prepare("UPDATE sellers_data SET no_subscribers = :no_subscribers WHERE id = :seller_id");
                query.bindValue(":no_subscribers",seller[i].no_of_subscribers);
                query.bindValue(":seller_id",seller[i].id);
                query.exec();
                //updateseller_subscribers();
                //updatecustomer_sellerssubscribedto();
                no_of_subsribers->setText("No of subsribers: " + QString::number(seller[i].no_of_subscribers));

            }

        });

        QPushButton *viewproducts_seller_btn = new QPushButton("View All Products",seller_container);
        //connect(viewproducts_seller_btn,&QPushButton::clicked,&MainWindowHome::viewproducts_seller); //it is a function I wrote it below , it will be executed when the user presses the btn



        connect(viewproducts_seller_btn,&QPushButton::clicked,[=](){
            ui->pages->setCurrentIndex(14);
            // widgets (containers)
            QWidget *sellersproducts_page , *scrollarea_containerr ,*container_ofproductscards;
            sellersproducts_page = ui->pages->findChild<QWidget*>("sellersproducts_page");;
            scrollarea_containerr = ui->scrollAreaWidgetContents_3;
            container_ofproductscards = new QWidget(scrollarea_containerr); //that container I do by code

            //To remove if there is existing Layout


            if ( container_ofproductscards->layout() != NULL )
            {
                QLayoutItem* item;
                while ( ( item = container_ofproductscards->layout()->takeAt( 0 ) ) != NULL )
                {
                    delete item->widget();
                    delete item;
                }
                delete container_ofproductscards->layout();
            }

            if ( scrollarea_containerr->layout() != NULL )
            {
                QLayoutItem* item;
                while ( ( item = scrollarea_containerr->layout()->takeAt( 0 ) ) != NULL )
                {
                    delete item->widget();
                    delete item;
                }
                delete scrollarea_containerr->layout();
            }

            if ( sellersproducts_page->layout() != NULL )
            {
                QLayoutItem* item;
                while ( ( item = sellersproducts_page->layout()->takeAt( 0 ) ) != NULL )
                {
                    delete item->widget();
                    delete item;
                }
                delete sellersproducts_page->layout();
            }

            // layouts
            QVBoxLayout *sellersproducts_layout , *scrollarea_layout;
            sellersproducts_layout = new QVBoxLayout(sellersproducts_page);
            scrollarea_layout = new QVBoxLayout(scrollarea_containerr);

            QGridLayout *layout_ofproductscards = new QGridLayout(container_ofproductscards);


            bool check = false;
            for (int m = 0 ,prod_found = 0; m < 7 ;m++){
                int no_products = noproducts_incategories[m];
                for (int j = 10 ; j < no_products;j++){
                    QLabel *product_expiration;
                    if (seller[i].username == category[m].products[j].seller){
                        //qDebug() << QString::fromStdString(category[m].products[j].name);
                        QWidget *product_card = new QWidget();
                        QVBoxLayout *contentproduct_card = new QVBoxLayout(product_card);
                        QLabel *product_number = new QLabel("#" + QString::number(prod_found+1),product_card);
                        QLabel *product_name = new QLabel("Name: " + QString::fromStdString(category[m].products[j].name) ,product_card);
                        QLabel *product_code = new QLabel("ID: " + QString::fromStdString(category[m].products[j].id),product_card);
                        QLabel *product_category = new QLabel("Category: " +QString::fromStdString(category[m].products[j].category),product_card);
                        QLabel *product_price = new QLabel("Price: " + QString::number(category[m].products[j].price) + "$",product_card);
                        QLabel *product_stock = new QLabel("Stock: " + QString::number(category[m].products[j].stock),product_card);
                        if (m == 2 || m ==4)
                            product_expiration = new QLabel("Expiration Date: " + QString::fromStdString(category[m].products[j].expiration_date),product_card);
                        QLabel* product_image = new QLabel(product_card);
                        product_image->setPixmap(QPixmap(category[m].products[j].image_url));
                        product_image->setScaledContents(true); // Scales the pixmap to fit the size of the QLabel
                        product_image->setFixedSize(250, 350);

                        QLabel* product_rating = new QLabel("Rating: " + QString::number(category[m].products[j].rating) + "/5" , product_card);


                        QWidget* quantity_container = new QWidget();
                        QGridLayout *quantity_container_layout = new QGridLayout();
                        quantity_container_layout->setContentsMargins(0, 0, 0, 0); // to remove the margins
                        quantity_container->setLayout(quantity_container_layout);
                        QLabel* quantity = new QLabel("Quantity You want to buy: ");
                        QSpinBox *muchquantity = new QSpinBox();
                        muchquantity->setRange(1,category[m].products[j].stock);
                        muchquantity->setFixedWidth(250);
                        quantity_container_layout->addWidget(quantity,0,0);
                        quantity_container_layout->addWidget(muchquantity,0,1);



                        QPushButton* addButton = new QPushButton("Add to Cart",product_card);
                        addButton->setFixedHeight(45);
                        addButton->setStyleSheet("background-color: green;font-weight:bold;color:white;");

                        if (category[m].products[j].stock == 0){
                            addButton->setEnabled(false);
                        }

                        contentproduct_card->addWidget(product_number);
                        contentproduct_card->addWidget(product_image);
                        contentproduct_card->addWidget(product_code);
                        contentproduct_card->addWidget(product_name);
                        contentproduct_card->addWidget(product_category);
                        contentproduct_card->addWidget(product_price);
                        contentproduct_card->addWidget(product_stock);
                        if (m == 2 || m == 4)
                            contentproduct_card->addWidget(product_expiration);
                        contentproduct_card->addWidget(product_rating);
                        contentproduct_card->addWidget(quantity_container);
                        contentproduct_card->addWidget(addButton);


                        layout_ofproductscards->addWidget(product_card,prod_found/2,prod_found%2);
                        prod_found++;
                        check = true;
                        product_card->setObjectName("product_card");

                        product_card->setStyleSheet("QLabel{font-weight:bold;color:#11405C;}");

                        connect (addButton,&QPushButton::clicked,[=](){
                            // to not add same product two times
                            for (int k = 0 ; k < counter_products;k++){
                                if (order_products.products_names[k] == category[m].products[j].name){
                                    order_products.products_quantities[k] += muchquantity->value();
                                    return;
                                }
                            }
                            order_products.CustomerID = customer[user_index].id;
                            order_products.products_codes[counter_products] = category[m].products[j].id;
                            order_products.products_names[counter_products] = category[m].products[j].name;
                            order_products.product_images[counter_products] = category[m].products[j].image_url;
                            order_products.products_prices[counter_products] =category[m].products[j].price;
                            order_products.products_quantities[counter_products] = muchquantity->value();
                            order_products.products_categories[counter_products] = category[m].products[j].category;
                            order_products.product_seller[counter_products] = category[m].products[j].seller;
                            counter_products++;
                        });
                    }
                }
            }

            if (check){ // atleast there is one product
                container_ofproductscards->setObjectName("productContainers");

                container_ofproductscards->setStyleSheet("QWidget#productContainers > * {border: 2px solid #F6EF98;background-color: white;border-radius:5px;}");
                scrollarea_layout->addWidget(container_ofproductscards);

            }

        });
        sellerLayout->addWidget(seller_number);
        sellerLayout->addWidget(profile_image);
        sellerLayout->addWidget(seller_id);
        sellerLayout->addWidget(seller_name);
        sellerLayout->addWidget(seller_username);
        sellerLayout->addWidget(no_of_products);
        sellerLayout->addWidget(no_of_subsribers);
        sellerLayout->addWidget(viewproducts_seller_btn);
        sellerLayout->addWidget(subscribe_btn_off);
        sellerLayout->addWidget(subscribe_btn_on);
        layout_forsellerscontainer->addWidget(seller_container, i/2, i%2);
    }

    sellersContainers->setObjectName("productContainers");

    sellersContainers->setStyleSheet("QWidget#productContainers > * {border: 1px solid black;background-color: white;border-radius:5px;}");
    layout_forscrollareacontainer->addWidget(sellersContainers);
}


void MainWindowHome::on_searchproductname_btn_clicked()
{


    ui->pages->setCurrentIndex(15);
    // widgets (containers)
    QWidget *products_page , *scrollarea_containerr ,*container_ofproductscards;
    products_page = ui->pages->findChild<QWidget*>("sellersproducts_page");
    scrollarea_containerr = ui->scrollAreaWidgetContents_4;
    container_ofproductscards = new QWidget(scrollarea_containerr); //that container I do by code

    //To remove if there is existing Layout
    QLayout *existingLayoutt = products_page->layout();
    if (existingLayoutt != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayoutt->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        delete existingLayoutt;
    }


    QLayout *existingLayoutforscrolll = scrollarea_containerr->layout();
    if (existingLayoutforscrolll != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayoutforscrolll->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        delete existingLayoutforscrolll;
    }

    QLayout *existingLayoutforproductcontainerr = container_ofproductscards->layout();
    if (existingLayoutforproductcontainerr != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayoutforproductcontainerr->takeAt(0)) != nullptr) {
            delete child->widget(); //--> that causes the program craches
            delete child;
        }
        delete existingLayoutforproductcontainerr;
    }

    // layouts
    QVBoxLayout *sellersproducts_layout , *scrollarea_layout;
    sellersproducts_layout = new QVBoxLayout(products_page);
    scrollarea_layout = new QVBoxLayout(scrollarea_containerr);

    QGridLayout *layout_ofproductscards = new QGridLayout(container_ofproductscards);

    bool product_found = false; //flag
    int product_category_index , product_index;
    QString product_namee = ui->searchproductname_input->text();
    product_namee = TrimLeft(product_namee.toStdString());
    product_namee = TrimRight(product_namee.toStdString());
    for (int i = 0 ; i < 7 ; i++){ //represent category index number
        int no_ofproducts = noproducts_incategories[i];

        for (int j = 0 ; j < no_ofproducts; j++){
            if (product_namee.toStdString() == category[i].products[j].name){
                product_found = true;
                product_category_index = i ;
                product_index = j;
                break;
            }
        }
    }

    if (product_found){
        QWidget *product_card = new QWidget();
        QVBoxLayout *contentproduct_card = new QVBoxLayout(product_card);
        QLabel *product_name = new QLabel("Name: " + QString::fromStdString(category[product_category_index].products[product_index].name) ,product_card);
        QLabel *product_code = new QLabel("ID: " + QString::fromStdString(category[product_category_index].products[product_index].id),product_card);
        QLabel *product_category = new QLabel("Category: " +QString::fromStdString(category[product_category_index].products[product_index].category),product_card);
        QLabel *product_price = new QLabel("Price: " + QString::number(category[product_category_index].products[product_index].price) + "$",product_card);
        QLabel *product_stock = new QLabel("Stock: " + QString::number(category[product_category_index].products[product_index].stock),product_card);
        QLabel *product_expiration;
        if (product_category_index == 2 || product_category_index ==4)
            product_expiration = new QLabel("Expiration Date: " + QString::fromStdString(category[product_category_index].products[product_index].expiration_date),product_card);
        QLabel* product_image = new QLabel(product_card);
        product_image->setPixmap(QPixmap(category[product_category_index].products[product_index].image_url));
        product_image->setScaledContents(true); // Scales the pixmap to fit the size of the QLabel
        product_image->setFixedSize(250, 350);

        QLabel* product_rating = new QLabel("Rating: " + QString::number(category[product_category_index].products[product_index].rating) + "/5" , product_card);

        QWidget* quantity_container = new QWidget();
        QGridLayout *quantity_container_layout = new QGridLayout();
        quantity_container_layout->setContentsMargins(0, 0, 0, 0); // to remove the margins
        quantity_container->setLayout(quantity_container_layout);
        QLabel* quantity = new QLabel("Quantity You want to buy: ");
        QSpinBox *muchquantity = new QSpinBox();
        muchquantity->setRange(1,category[product_category_index].products[product_index].stock);
        muchquantity->setFixedWidth(250);
        quantity_container_layout->addWidget(quantity,0,0);
        quantity_container_layout->addWidget(muchquantity,0,1);

        QPushButton* addButton = new QPushButton("Add to Cart",product_card);
        addButton->setFixedHeight(45);
        addButton->setStyleSheet("background-color: green;font-weight:bold;color:white;");


        contentproduct_card->addWidget(product_image);
        contentproduct_card->addWidget(product_code);
        contentproduct_card->addWidget(product_name);
        contentproduct_card->addWidget(product_category);
        contentproduct_card->addWidget(product_price);
        contentproduct_card->addWidget(product_stock);
        if (product_category_index == 2 || product_category_index == 4)
            contentproduct_card->addWidget(product_expiration);
        contentproduct_card->addWidget(product_rating);
        contentproduct_card->addWidget(quantity_container);
        contentproduct_card->addWidget(addButton);


        layout_ofproductscards->addWidget(product_card,0,0);
        scrollarea_layout->addWidget(container_ofproductscards);

        connect (addButton,&QPushButton::clicked,[=](){
            // to not add same product two times
            for (int k = 0 ; k < counter_products;k++){
                if (order_products.products_names[k] == category[product_category_index].products[product_index].name){
                    order_products.products_quantities[k] += muchquantity->value();
                    return;
                }
            }
            order_products.CustomerID = customer[user_index].id;
            order_products.products_codes[counter_products] = category[product_category_index].products[product_index].id;
            order_products.products_names[counter_products] = category[product_category_index].products[product_index].name;
            order_products.product_images[counter_products] = category[product_category_index].products[product_index].image_url;
            order_products.products_prices[counter_products] =category[product_category_index].products[product_index].price;
            order_products.products_quantities[counter_products] = muchquantity->value();
            order_products.products_categories[counter_products] = category[product_category_index].products[product_index].category;
            order_products.product_seller[counter_products] = category[product_category_index].products[product_index].seller;
            counter_products++;
        });
    }
    else{
        QWidget *product_card = new QWidget();
        QVBoxLayout *contentproduct_card = new QVBoxLayout(product_card);
        QLabel* productnotfound = new QLabel("Product not found!",product_card);
        contentproduct_card->addWidget(productnotfound);
        layout_ofproductscards->addWidget(product_card,0,0);
        scrollarea_layout->addWidget(container_ofproductscards);

    }
}

struct max_rating{
    int category_index;
    int product_index;
    float rating;
};
max_rating maximum[3];



void MainWindowHome::view_dashboard(){
    //show top 3 rating products then random products from subscribed users
    QWidget *scroll_area_container = ui->scrollAreaWidgetContents_5;

    QLayout *existingLayoutforscroll = scroll_area_container->layout();
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


    QWidget* mainContainer = new QWidget(scroll_area_container);

    QVBoxLayout *layout_forscrollareacontainer = new QVBoxLayout(scroll_area_container);
    scroll_area_container->setLayout(layout_forscrollareacontainer);
    QVBoxLayout* mainLayout = new QVBoxLayout(mainContainer);
    mainContainer->setLayout(mainLayout);




    QLabel* top_products = new QLabel("Top Rating Products");
    top_products->setAlignment(Qt::AlignCenter);
    top_products->setStyleSheet("font-weight: bold; font-size:35px;");
    mainLayout->addWidget(top_products);

    maximum[0].rating = maximum[1].rating = maximum[2].rating = 0;
    for (int i = 0; i < 7; i++) {
        int no_ofproducts = noproducts_incategories[i];
        for (int j = 0; j < no_ofproducts; j++) {
            float rating = category[i].products[j].rating;
            if (rating > maximum[0].rating) {
                maximum[2] = maximum[1];
                maximum[1] = maximum[0];
                maximum[0].rating = rating;
                maximum[0].category_index = i;
                maximum[0].product_index = j;
            } else if (rating > maximum[1].rating) {
                maximum[2] = maximum[1];
                maximum[1].rating = rating;
                maximum[1].category_index = i;
                maximum[1].product_index = j;
            } else if (rating > maximum[2].rating) {
                maximum[2].rating = rating;
                maximum[2].category_index = i;
                maximum[2].product_index = j;
            }
        }
    }

    QWidget* topRatedContainer = new QWidget(mainContainer);
    QHBoxLayout *topRatedLayout = new QHBoxLayout(topRatedContainer);
    topRatedContainer->setLayout(topRatedLayout);

    for (int i = 0; i < 3 ; i++){
        QWidget *product_card = new QWidget(topRatedContainer);
        QVBoxLayout *layoutproduct_card = new QVBoxLayout();
        product_card->setLayout(layoutproduct_card);
        QLabel *product_number = new QLabel("#" + QString::number(i+1));
        QLabel *product_name = new QLabel("Name: " + QString::fromStdString(category[maximum[i].category_index].products[maximum[i].product_index].name));
        QLabel *product_code = new QLabel("ID: " + QString::fromStdString(category[maximum[i].category_index].products[maximum[i].product_index].id));
        QLabel *product_category = new QLabel("Category: " +QString::fromStdString(category[maximum[i].category_index].products[maximum[i].product_index].category));
        QLabel *product_price = new QLabel("Price: " + QString::number(category[maximum[i].category_index].products[maximum[i].product_index].price) + "$");
        QLabel *product_stock = new QLabel("Stock: " + QString::number(category[maximum[i].category_index].products[maximum[i].product_index].stock));
        QLabel* product_image = new QLabel();
        product_image->setPixmap(QPixmap(category[maximum[i].category_index].products[maximum[i].product_index].image_url));
        product_image->setScaledContents(true); // Scales the pixmap to fit the size of the QLabel
        product_image->setFixedSize(250, 350);

        QLabel* product_rating = new QLabel("Rating: " + QString::number(category[maximum[i].category_index].products[maximum[i].product_index].rating) + "/5");

        QWidget* quantity_container = new QWidget();
        QGridLayout *quantity_container_layout = new QGridLayout();
        quantity_container_layout->setContentsMargins(0, 0, 0, 0); // to remove the margins
        quantity_container->setLayout(quantity_container_layout);
        QLabel* quantity = new QLabel("Quantity You want to buy: ");
        QSpinBox *muchquantity = new QSpinBox();
        muchquantity->setRange(1,category[maximum[i].category_index].products[maximum[i].product_index].stock);
        muchquantity->setFixedWidth(250);
        quantity_container_layout->addWidget(quantity,0,0);
        quantity_container_layout->addWidget(muchquantity,0,1);

        QPushButton* addButton = new QPushButton("Add to Cart");
        addButton->setFixedHeight(45);
        addButton->setStyleSheet("background-color: green;font-weight:bold;color:white;");

        product_card->setObjectName("product_card");

        product_card->setStyleSheet("QLabel{font-weight:bold;color:#11405C}");

        layoutproduct_card->addWidget(product_number);
        layoutproduct_card->addWidget(product_image);
        layoutproduct_card->addWidget(product_code);
        layoutproduct_card->addWidget(product_name);
        layoutproduct_card->addWidget(product_category);
        layoutproduct_card->addWidget(product_price);
        layoutproduct_card->addWidget(product_stock);

        layoutproduct_card->addWidget(product_rating);
        layoutproduct_card->addWidget(quantity_container);
        layoutproduct_card->addWidget(addButton);



        topRatedLayout->addWidget(product_card); //HBOX Layout


        connect (addButton,&QPushButton::clicked,[=](){
            // to not add same product two times
            for (int k = 0 ; k < counter_products;k++){
                if (order_products.products_names[k] == category[maximum[i].category_index].products[maximum[i].product_index].name){
                    order_products.products_quantities[k] += muchquantity->value();
                    return;
                }
            }
            order_products.CustomerID = customer[user_index].id;
            order_products.products_codes[counter_products] = category[maximum[i].category_index].products[maximum[i].product_index].id;
            order_products.products_names[counter_products] = category[maximum[i].category_index].products[maximum[i].product_index].name;
            order_products.product_images[counter_products] = category[maximum[i].category_index].products[maximum[i].product_index].image_url;
            order_products.products_prices[counter_products] =category[maximum[i].category_index].products[maximum[i].product_index].price;
            order_products.products_quantities[counter_products] = muchquantity->value();
            order_products.products_categories[counter_products] = category[maximum[i].category_index].products[maximum[i].product_index].category;
            order_products.product_seller[counter_products] = category[maximum[i].category_index].products[maximum[i].product_index].seller;
            counter_products++;
        });
    }

    QLabel* productsfromseller = new QLabel("Random Sellers Products");
    productsfromseller->setStyleSheet("font-weight: bold; font-size:35px;");
    productsfromseller->setAlignment(Qt::AlignCenter);

    QWidget* randomProductsContainer = new QWidget(mainContainer);
    QGridLayout* randomProductsLayout = new QGridLayout(randomProductsContainer);
    randomProductsContainer->setLayout(randomProductsLayout);

    for(int m = 0 ; m < 6;m++){
        int random_category_index = rand() % 7; // 0 to 6
        int random_product_index;
        if (noproducts_incategories[random_category_index] > 10){ // there are seller products
            random_product_index = 10 + (rand()% (noproducts_incategories[random_category_index] - 10));
        }
        else{ // there is no seller product in that category so max products = 9
            random_product_index = rand() % noproducts_incategories[random_category_index];
        }

        QWidget *product_widget = new QWidget();
        QVBoxLayout *layoutproduct_widget = new QVBoxLayout();
        product_widget->setLayout(layoutproduct_widget);

        QLabel *product_numberr = new QLabel("#" + QString::number(m+1));
        //qDebug()<< product_numberr; //that will print a pointer
        QLabel *product_namee = new QLabel("Name: " + QString::fromStdString(category[random_category_index].products[random_product_index].name));
        QLabel *product_codee = new QLabel("ID: " + QString::fromStdString(category[random_category_index].products[random_product_index].id));
        QLabel *product_categoryy = new QLabel("Category: " +QString::fromStdString(category[random_category_index].products[random_product_index].category));
        QLabel *product_pricee = new QLabel("Price: " + QString::number(category[random_category_index].products[random_product_index].price) + "$");
        QLabel *product_stockk = new QLabel("Stock: " + QString::number(category[random_category_index].products[random_product_index].stock));
        QLabel* product_imagee = new QLabel();
        product_imagee->setPixmap(QPixmap(category[random_category_index].products[random_product_index].image_url));
        product_imagee->setScaledContents(true); // Scales the pixmap to fit the size of the QLabel
        product_imagee->setFixedSize(100, 250);

        QLabel* product_ratingg = new QLabel("Rating: " + QString::number(category[random_category_index].products[random_product_index].rating) + "/5" );

        QWidget* quantity_containerr = new QWidget();
        QGridLayout *quantity_container_layoutt = new QGridLayout();
        quantity_container_layoutt->setContentsMargins(0, 0, 0, 0); // to remove the margins
        quantity_containerr->setLayout(quantity_container_layoutt);
        QLabel* quantity_ = new QLabel("Quantity You want to buy: ");
        QSpinBox *muchquantity_ = new QSpinBox();
        muchquantity_->setRange(1,category[random_category_index].products[random_product_index].stock);
        muchquantity_->setFixedWidth(250);
        quantity_container_layoutt->addWidget(quantity_,0,0);
        quantity_container_layoutt->addWidget(muchquantity_,0,1);

        QPushButton* addButtonn = new QPushButton("Add to Cart");
        addButtonn->setFixedHeight(45);
        addButtonn->setStyleSheet("background-color: green;font-weight:bold;color:white;");

        layoutproduct_widget->addWidget(product_numberr);
        layoutproduct_widget->addWidget(product_imagee);
        layoutproduct_widget->addWidget(product_codee);
        layoutproduct_widget->addWidget(product_namee);
        layoutproduct_widget->addWidget(product_categoryy);
        layoutproduct_widget->addWidget(product_pricee);
        layoutproduct_widget->addWidget(product_stockk);

        layoutproduct_widget->addWidget(product_ratingg);
        layoutproduct_widget->addWidget(quantity_containerr);
        layoutproduct_widget->addWidget(addButtonn);


        randomProductsLayout->addWidget(product_widget,m/3,m%3);

        product_widget->setObjectName("product_widget");

        product_widget->setStyleSheet("QLabel{font-weight:bold;color:#11405C}");


        connect (addButtonn,&QPushButton::clicked,[=](){
            // to not add same product two times
            for (int k = 0 ; k < counter_products;k++){
                if (order_products.products_names[k] == category[random_category_index].products[random_product_index].name){
                    order_products.products_quantities[k] += muchquantity_->value();
                    return;
                }
            }
            order_products.CustomerID = customer[user_index].id;
            order_products.products_codes[counter_products] = category[random_category_index].products[random_product_index].id;
            order_products.products_names[counter_products] = category[random_category_index].products[random_product_index].name;
            order_products.product_images[counter_products] = category[random_category_index].products[random_product_index].image_url;
            order_products.products_prices[counter_products] =category[random_category_index].products[random_product_index].price;
            order_products.products_quantities[counter_products] = muchquantity_->value();
            order_products.products_categories[counter_products] = category[random_category_index].products[random_product_index].category;
            order_products.product_seller[counter_products] = category[random_category_index].products[random_product_index].seller;
            counter_products++;
        });
    }

    topRatedContainer->setObjectName("productContainers");
    topRatedContainer->setStyleSheet("QWidget#productContainers > * {border: 1px solid black;background-color: white;border-radius:5px;}");

    randomProductsContainer->setObjectName("productContainersRandom");
    randomProductsContainer->setStyleSheet("QWidget#productContainersRandom > * {border: 1px solid black;background-color: white;border-radius:5px;}");

    mainLayout->addWidget(topRatedContainer);

    mainLayout->addWidget(productsfromseller);
    mainLayout->addWidget(randomProductsContainer);
    layout_forscrollareacontainer->addWidget(mainContainer);

}

struct productRating{
    bool arr_rating[5] = {false};
};




void MainWindowHome::viewpreviousorders(){
    //Show the products in the cards
    productRating *rating_products = new productRating[no_ofpreviousorderedproducts];
    QWidget *scrollarea_container ,*productContainers;
    scrollarea_container = ui->scrollContentContainer_10; //QWidget Container of scroll area

    QLayout *existingLayout = scrollarea_container->layout();
    if (existingLayout != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayout->takeAt(0)) != nullptr) {
            if (child->widget()){

                child->widget()->deleteLater();
            }

            delete child;
        }
        delete existingLayout;
    }

    productContainers = new QWidget(scrollarea_container);

    QVBoxLayout *layout_forscrollareacontainer = new QVBoxLayout();
    scrollarea_container->setLayout(layout_forscrollareacontainer);

    QGridLayout *layout_forallproductscardscontainer = new QGridLayout();
    productContainers->setLayout(layout_forallproductscardscontainer);

    for (int i = 0; i < no_ofpreviousorderedproducts ;i++){
        QWidget* productWidget = new QWidget(); //thecontainer of each product
        QVBoxLayout* productLayout = new QVBoxLayout(); // details inside each card (product)
        productWidget->setLayout(productLayout);

        QLabel* nameLabel = new QLabel("Product # " +  QString::number(i+1) ,productWidget);
        QLabel* imageLabel = new QLabel(productWidget);
        imageLabel->setPixmap(QPixmap(previous_orderedproducts.product_images[i]));
        imageLabel->setScaledContents(true); // Scales the pixmap to fit the size of the QLabel
        imageLabel->setFixedSize(200, 300);

        QLabel *product_id = new QLabel(QString::fromStdString("Product ID: " + previous_orderedproducts.product_codes[i]),productWidget);
        QLabel *name_product = new QLabel(QString::fromStdString("Product Name: " + previous_orderedproducts.product_names[i]),productWidget);
        QLabel *name_category = new QLabel(QString::fromStdString("Category: " + previous_orderedproducts.product_categories[i]),productWidget);
        QLabel* priceLabel = new QLabel("Price for each: " + QString::number(previous_orderedproducts.product_prices[i]) + "$",productWidget);
        QLabel *no_of_quantities = new QLabel("No of quantities: " + QString::number(previous_orderedproducts.product_quantities[i]),productWidget);
        QLabel* product_seller = new QLabel("Seller: " + QString::fromStdString(previous_orderedproducts.product_sellers[i]),productWidget);


        QWidget *ratingcontainer = new QWidget(productWidget);
        QGridLayout *ratingbuttonslayout = new QGridLayout();
        ratingcontainer->setLayout(ratingbuttonslayout);

        QPushButton *rating_btns_off[5];
        QPushButton *rating_btns_on[5];
        for (int m = 0; m < 5 ; m++){

            rating_btns_off[m] = new QPushButton(ratingcontainer);
            rating_btns_on[m] = new QPushButton(ratingcontainer);

            // add the photos
            rating_btns_off[m]->setIcon(QIcon(":/imgs/rating/star_off.png"));
            rating_btns_off[m]->setFlat(true);
            rating_btns_off[m]->setIconSize(QSize(32, 32));

            rating_btns_on[m]->setIcon(QIcon(":/imgs/rating/star_on.png"));
            rating_btns_on[m]->setFlat(true); // to remove the frame of the button
            rating_btns_on[m]->setIconSize(QSize(32, 32));
            rating_btns_on[m]->hide();
            ratingbuttonslayout->addWidget(rating_btns_on[m],0,m);
            ratingbuttonslayout->addWidget(rating_btns_off[m],0,m);

            connect(rating_btns_off[m],&QPushButton::clicked,[=]()mutable{
                qDebug() << m;
                if (m == 0){
                    rating_btns_off[m]->hide();
                    rating_btns_on[m]->show();
                    rating_products[i].arr_rating[m] = true;
                }
                for (int k = 0 ; k <= m;k++){
                    rating_btns_off[k]->hide();
                    rating_btns_on[k]->show();
                    rating_products[i].arr_rating[k] = true;
                }
            });

            connect(rating_btns_on[m],&QPushButton::clicked,[=]()mutable{
                rating_btns_on[m]->hide();
                rating_btns_off[m]->show();
                rating_products[i].arr_rating[m] = false;
            });
        }
        QPushButton *submit_review = new QPushButton("Submit Review",productWidget);
        submit_review->setStyleSheet("font-weight: bold;color:white;border-radius:5px; background-color: #112f91");
        submit_review->setFixedHeight(45);
        connect(submit_review,&QPushButton::clicked,[=](){
            int user_id = customer[user_index].id;
            QString product_id = QString::fromStdString(previous_orderedproducts.product_codes[i]);
            bool check_votingbefore = false;
            int rating= 0;

            bool rating_check = false;
            for (int z = 0 ; z < 5 ;z++){
                if (rating_products[i].arr_rating[z] == true){
                    rating++;
                    rating_check = true;
                }

            }
            if (!rating_check){
                QMessageBox::critical(this,"Please rate","You dont rate");
                return;
            }

            QSqlQuery query;
            query.prepare("SELECT rating FROM rating_products WHERE user_id = :user_id AND product_id = :product_id");
            query.bindValue(":user_id",user_id);
            query.bindValue(":product_id",product_id);
            query.exec();
            if (query.next())
                check_votingbefore = true;

            if (check_votingbefore){
                QMessageBox::information(this,"You rated before","Sorry,You cant rate this product cuz you already have rated it..");
                return;
            }

            query.prepare("INSERT INTO rating_products (user_id, product_id,rating) VALUES (:user_id, :product_id,:rating)");
            query.bindValue(":user_id",user_id);
            query.bindValue(":product_id",product_id);
            query.bindValue(":rating",rating);
            if(query.exec()){
                QMessageBox::information(this,"Rated successfully","You rated the product successfully");
            }


            int sum_users = 0;
            float sum_rating = 0;
            query.prepare("SELECT rating from rating_products WHERE product_id = :product_id");
            query.bindValue(":product_id",product_id);
            query.exec();
            while (query.next()){
                sum_rating += query.value(0).toString().toFloat();
                sum_users++;
            }

            qDebug() << QString::number(sum_users);
            qDebug() << QString::number(sum_rating);

            float new_rating = sum_rating / sum_users;

            for (int category_index = 0; category_index < 7;category_index++){
                int no_ofproducts = noproducts_incategories[category_index];
                for (int j = 0 ; j < no_ofproducts;j++){
                    if (category[category_index].products[j].id == product_id.toStdString()){
                        category[category_index].products[j].rating = new_rating;

                    }
                }
            }
        });
        productWidget->setObjectName("product_card");

        productWidget->setStyleSheet("QLabel{font-weight:bold;color:#11405C;}");

        productLayout->addWidget(nameLabel);
        productLayout->addWidget(imageLabel);
        productLayout->addWidget(product_id);
        productLayout->addWidget(name_product);
        productLayout->addWidget(name_category);
        productLayout->addWidget(priceLabel);
        productLayout->addWidget(product_seller);
        productLayout->addWidget(no_of_quantities);
        productLayout ->addWidget(ratingcontainer);
        productLayout->addWidget(submit_review);
        layout_forallproductscardscontainer->addWidget(productWidget, i/2, i%2);
    }
    productContainers->setObjectName("productContainers");
    productContainers->setStyleSheet("QWidget#productContainers > * {border: 1px solid #F6EF98;background-color: white;border-radius:5px;}");
    layout_forscrollareacontainer->addWidget(productContainers);
}




void MainWindowHome::on_coupons_btn_clicked()
{
    ui->coupons_btn->setStyleSheet("background-color: #F6EF98; color: #112f91");
    ui->previous_orders_btn->setStyleSheet("");
    ui->dashboard_btn->setStyleSheet("");
    ui->category_btn->setStyleSheet("");
    ui->cart_btn->setStyleSheet("");
    ui->profile_btn->setStyleSheet("");
    ui->sellers_btn->setStyleSheet("");

    ui->pages->setCurrentIndex(16);
    couponsgift();
}

void MainWindowHome::couponsgift(){
    QWidget *mainCouponContainer = ui->coupons_widget;
    mainCouponContainer->setObjectName("mainContainer");
    mainCouponContainer->setStyleSheet("QWidget#mainContainer{background-image:url(:/imgs/box_coupons/background-coupons.jpg);background-repeat: no-repeat;background-position: center;}");
    srand(time(NULL)); //to get different random numbers when you close the program and open it , so even us , we dont know which box has the coupon or what coupon text will appear cuz box index and coupon index changes everytime I close the program

    int box_coupon_index = rand() % 4; // from 0 to 3

    //delete exsiting layout and to clear the layouts

    QLayout *existingLayout = mainCouponContainer->layout();
    if (existingLayout != nullptr) {
        QLayoutItem *child;
        while ((child = existingLayout->takeAt(0)) != nullptr) {
            if (child->widget()){

                child->widget()->deleteLater();
            }

            delete child;
        }
        delete existingLayout;
    }

    QWidget *coupons_container = new QWidget(mainCouponContainer); //the container we will add everything to it

    QVBoxLayout *layout_formainCouponContainer = new QVBoxLayout();
    mainCouponContainer->setLayout(layout_formainCouponContainer);

    QVBoxLayout *layout_forcoupons_container = new QVBoxLayout();
    coupons_container->setLayout(layout_forcoupons_container);


    QLabel *openone = new QLabel("You can only Open One box",coupons_container);
    openone->setAlignment(Qt::AlignCenter);
    QLabel *wishluck = new QLabel("Wish You Best Of Luck",coupons_container);
    wishluck->setAlignment(Qt::AlignCenter);

    //--------------------
    QWidget *boxescontainer = new QWidget();
    QGridLayout *layout_boxescontainer = new QGridLayout();
    boxescontainer->setLayout(layout_boxescontainer);

    bool win_coupon = false;
    QLabel *winmsg , *coupondata,*coupo_n,*coupon_discount,*losemsg,*lucknext;
    for (int i = 0 ; i < 4 ; i++){
        boxes_btn_closed[i] = new QPushButton(boxescontainer);
        QIcon icon_boxes_closed;
        icon_boxes_closed.addPixmap(QPixmap(":/imgs/box_coupons/box_closed.png"),QIcon::Normal);
        icon_boxes_closed.addPixmap(QPixmap(":/imgs/box_coupons/box_closed.png"),QIcon::Disabled);
        boxes_btn_closed[i]->setIcon(icon_boxes_closed);
        boxes_btn_closed[i]->setFlat(true);
        boxes_btn_closed[i]->setIconSize(QSize(250, 250));

        boxes_btn_open[i] = new QPushButton(boxescontainer);
        boxes_btn_open[i]->setFlat(true);
        boxes_btn_open[i]->hide();

        connect(boxes_btn_closed[i],&QPushButton::clicked,[=]()mutable{ // mutable to be able to assign new value to a variable in the function from lambda
            boxes_btn_closed[i]->hide();
            boxes_btn_open[i]->show();

            if (box_coupon_index == i){
                QIcon icon_boxes_opencoupon;
                icon_boxes_opencoupon.addPixmap(QPixmap(":/imgs/box_coupons/box_open_coupon.png"),QIcon::Normal);
                icon_boxes_opencoupon.addPixmap(QPixmap(":/imgs/box_coupons/box_open_coupon.png"),QIcon::Disabled);
                boxes_btn_open[i]->setIcon(icon_boxes_opencoupon);
                boxes_btn_open[i]->setIconSize(QSize(250, 250));

                boxes_btn_closed[i]->hide();
                boxes_btn_open[i]->show();

                int coupon_index = rand() % 10;
                QString couponn = QString::fromStdString(coupon[box_coupon_index].the_coupon);
                QString couponn_value = QString::number(coupon[box_coupon_index].the_coupon_value);
                QMessageBox::information(this,"Congratulations","Congratulations , You have earned coupon code");
                win_coupon = true;

                winmsg = new QLabel("Congratulations ,You Won",coupons_container);
                winmsg->setStyleSheet("text-align:center;font-weight:bold;font-size:32px;color: red;");

                coupondata = new QLabel("Coupons Data",coupons_container);

                coupo_n = new QLabel("Coupon: " + couponn , coupons_container);
                coupo_n->setTextInteractionFlags(Qt::TextSelectableByMouse); //method so user can select the text and copy it
                coupo_n->setStyleSheet("color:#BD1616;background-color:white;font-weight:bold;font-size:30px;");
                coupon_discount = new QLabel("Value: " + couponn_value + "$" , coupons_container);
                coupon_discount->setStyleSheet("color:blue;background-color:white;font-weight:bold;font-size:22px;");



                layout_forcoupons_container->addWidget(winmsg);
                layout_forcoupons_container->addWidget(coupondata);
                layout_forcoupons_container->addWidget(coupo_n);
                layout_forcoupons_container->addWidget(coupon_discount);



            }else{
                boxes_btn_closed[i]->hide();
                boxes_btn_open[i]->show();

                QIcon icon_boxes_nocoupon;
                icon_boxes_nocoupon.addPixmap(QPixmap(":/imgs/box_coupons/boxopen_empty.png"),QIcon::Normal);
                icon_boxes_nocoupon.addPixmap(QPixmap(":/imgs/box_coupons/boxopen_empty.png"),QIcon::Disabled);
                boxes_btn_open[i]->setIcon(icon_boxes_nocoupon);
                boxes_btn_open[i]->setIconSize(QSize(250, 250));

                QMessageBox::information(this,"Sorry","It is not the box that has the coupon");
                losemsg = new QLabel("Unfortunately,You havent won the coupon",coupons_container);
                losemsg->setStyleSheet("font-weight:bold;font-size:25px;color:black;background-color:white");
                lucknext = new QLabel("Wish You best next time",coupons_container);
                lucknext->setStyleSheet("font-weight:bold;font-size:25px;color:black;background-color:white");

                layout_forcoupons_container->addWidget(losemsg);
                layout_forcoupons_container->addWidget(lucknext);
            }
            for (int j = 0 ; j < 4 ; j++){
                boxes_btn_closed[j]->setEnabled(false);
                boxes_btn_open[j]->setEnabled(false);
            }

        });

        layout_boxescontainer->addWidget(boxes_btn_closed[i],0,i);
        layout_boxescontainer->addWidget(boxes_btn_open[i],0,i);




    }
    layout_forcoupons_container->addWidget(openone);
    layout_forcoupons_container->addWidget(wishluck);
    layout_forcoupons_container->addWidget(boxescontainer);

    layout_formainCouponContainer->addWidget(coupons_container);
}

void MainWindowHome::on_paywith_visa_clicked()
{
    ui->visa_pay_container->show();
}


void MainWindowHome::on_visa_pay_btn_clicked()
{
    if (ui->credit_id->text().toStdString().length() != 16){
        QMessageBox::critical(this,"sorry","Credit number is wrong");
        return;
    }

    if (ui->cvv->text().toStdString().length() != 3){
        QMessageBox::critical(this,"sorry","CVV is wrong");
        return;
    }

    if (ui->year->text().toInt() < 2023 ){
        QMessageBox::critical(this,"sorry","Expiration Date is wrong");
        return;
    }

    QMessageBox::information(this,"Thank you","I hope you will like the products");
    ui->visa_pay_btn->setEnabled(false);
    ui->paywith_visa->setEnabled(false);
    ui->paywith_paypal->setEnabled(false);
    ui->cashon_delivery->setEnabled(false);


}


void MainWindowHome::on_cashon_delivery_clicked()
{
    QMessageBox::information(this,"Thank Youu","I hope you like our product");
}

