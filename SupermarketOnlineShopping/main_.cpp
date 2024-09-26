#include "main_.h"
#include <fstream>
#include <string>
#include <iostream>
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslConfiguration>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QNetworkAddressEntry>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


int no_actualusers = 2;
users_information customer[no_customers];
string all_products[70];
Category category[7];

void update_users_date(){
    customer[0].name = "user1";
    customer[0].email = "user1@gmail.com";
    customer[0].address = "elzmalek";
    customer[0].phone_number = "01000006524";
    customer[0].password = "111";

    customer[1].name = "user2";
    customer[1].email = "user2@gmail.com";
    customer[1].address = "haram";
    customer[1].phone_number = "01136841269";
    customer[1].password = "222";



    int initial_ID = 100;



    if (connect_db()){
        retrieve_data_db("full_name");
        retrieve_data_db("email");
        retrieve_data_db("password");
        retrieve_data_db("phone_number");
        retrieve_data_db("address");

    }
    else
        qDebug() << "Db is not working";

    for (int k = 0; k < no_actualusers; k++) {
        customer[k].id = initial_ID;
        initial_ID++;
    }

}


bool connect_db(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3000);
    db.setUserName("root");
    db.setPassword(""); //no password
    db.setDatabaseName("supermarketonlineshopping");
    if (!(db.open()))
        return false;
    //db.close();
    return true;
}


void retrieve_data_db(QString name_column){

    QString query = "SELECT " + name_column +" FROM users_data";
    QSqlQuery sql_query;
    sql_query.prepare(query);
    int i = 2;
    if (name_column == "full_name")
        if (sql_query.exec())
            while (sql_query.next()){
                customer[i].name = sql_query.value(0).toString().toStdString();
                i++;
                no_actualusers++;
            }

        else{
            qDebug() << "We cant retrieve data from db";
            qDebug() << sql_query.lastError();
        }
    else if (name_column == "email")
        if (sql_query.exec())
            while (sql_query.next()){
                customer[i].email = sql_query.value(0).toString().toStdString(); //toString > to convert it to QString -- toStdString to convert it from QString to string
                i++;
            }
        else{
            qDebug() << "We cant retrieve data from db";
            qDebug() << sql_query.lastError();
        }
    else if (name_column == "password")
        if (sql_query.exec())
            while (sql_query.next()){
                customer[i].password = sql_query.value(0).toString().toStdString();
                i++;
            }
        else{
            qDebug() << "We cant retrieve data from db";
            qDebug() << sql_query.lastError();
        }
    else if (name_column == "phone_number")
        if (sql_query.exec())
            while (sql_query.next()){
                customer[i].phone_number = sql_query.value(0).toString().toStdString();
                i++;
            }
        else{
            qDebug() << "We cant retrieve data from db";
            qDebug() << sql_query.lastError();
        }
    else if (name_column == "address")
        if (sql_query.exec())
            while (sql_query.next()){
                customer[i].address = sql_query.value(0).toString().toStdString();
                i++;
            }
        else{
            qDebug() << "We cant retrieve data from db";
            qDebug() << sql_query.lastError();
        }
    else
        qDebug() << "Name of column is incorrect";
}


void products_data() {

    category[0].products[0].name = "MSI Katana GF66 Gaming Laptop";
    category[0].products[0].id = "";
    category[0].products[0].category = "Electronics - Laptop";
    category[0].products[0].price = 1700;
    category[0].products[0].image_url = ":/imgs/Electronics/msi.png";
    category[0].products[1] = { "Acer Aspire 5","","Electronics - Laptop",550, ":/imgs/Electronics/acer.png" };
    category[0].products[2] = { "LG 55  Class 4K UHD 2160P","","Electronics",360, ":/imgs/Electronics/lg55.jpg" };
    category[0].products[3] = { "LG 65  Class 4K UHD ","","Electronics",1300, ":/imgs/Electronics/lg65.png" };
    category[0].products[4] = { "SAMSUNG 65 Class 4K Crystal","","Electronics",478, ":/imgs/Electronics/samsung65.jpg" };
    category[0].products[5] = { "Apple Watch Series 8 GPS","","Electronics",360, ":/imgs/Electronics/applewatch.jpg" };
    category[0].products[6] = { "SAMSUNG Galaxy Watch 4","","Electronics",170, ":/imgs/Electronics/samsungwatch.png" };
    category[0].products[7] = { "Gateway Notebook 11.6","","Electronics - Mobile Phones",192, ":/imgs/Electronics/notebook.jpg" };
    category[0].products[8] = { "Straight Talk Apple iPhone 11, 64GB","","Electronics - Mobile Phones",250, ":/imgs/Electronics/iphone11.png" };
    category[0].products[9] = { "Apple iPhone 12, 64GB","","Electronics - Mobile Phones",500, ":/imgs/Electronics/iphone12.jpg"};


    category[1].products[0] = { "Red Dead Redemption 2","","VideoGames - PlayStation 4",20,":/imgs/Videogames/reddeadredemption.jpg" };
    category[1].products[1] = { "FIFA 23","","VideoGames - PlayStation 4",40,":/imgs/Videogames/fifa23.jpg" };
    category[1].products[2] = { "Grand Theft Auto V","","VideoGames - PlayStation 5",20,":/imgs/Videogames/gtv.jpg" };
    category[1].products[3] = { "Pro Evolution Soccer (PES) 23","","VideoGames - PlayStation 4",40,":/imgs/Videogames/pes23.png" };
    category[1].products[4] = { "Call of Duty: Modern Warfare II","","VideoGames - PlayStation 5",70,":/imgs/Videogames/cod.jpg" };
    category[1].products[5] = { "Marvel’s Spider-Man: Miles Morales Ultimate Launch Edition","","VideoGames - PlayStation 5",70,":/imgs/Videogames/spiderman.jpg" };
    category[1].products[6] = { "Crysis Remastered Trilogy","","VideoGames - PlayStation 4",35,":/imgs/Videogames/crysis.png" };
    category[1].products[7] = { "Battlefield V","","VideoGames - PlayStation 4",20,":/imgs/Videogames/battlefield.jpg" };
    category[1].products[8] = { "Resident Evil 4","","VideoGames - PlayStation 4",60,":/imgs/Videogames/residentevil.jpg" };
    category[1].products[9] = { "Hogwarts Legacy Deluxe Edition","","VideoGames - PlayStation 4",70,":/imgs/Videogames/howgarts.jpg" };

    category[2].products[0] = { "Cheddar Smoked Sausage","","Groceries",3.96 , ":/imgs/Groceries/cheddar.png" };
    category[2].products[1] = { "Freshness Guaranteed Boneless Chicken Thighs","","Groceries",11.38, ":/imgs/Groceries/chickenthigh.png" };
    category[2].products[2] = { "Freshness Guaranteed Chicken Breast Tenderloins","","Groceries",8.94, ":/imgs/Groceries/chickenbreast.png" };
    category[2].products[3] = { "HERSHEY'S and REESE'S, Chocolate Assortment Treats","","Groceries",7.48, ":/imgs/Groceries/chocolate.jpg" };
    category[2].products[4] = { "CADBURY, MINI EGGS Milk Chocolate with a Crisp Sugar Shell","","Groceries",3.84, ":/imgs/Groceries/cadruby.png" };
    category[2].products[5] = { "REESE'S, Assorted Milk Chocolate","","Groceries",10.98, ":/imgs/Groceries/chocolate2.png" };
    category[2].products[6] = { "Sadler's Smokehouse Mesquite Smoked Sliced Beef Brisket","","Groceries",23.04, ":/imgs/Groceries/beef.jpeg" };
    category[2].products[7] = { "Fresh Sweet Corn","","Groceries",0.60, ":/imgs/Groceries/corn.png" };
    category[2].products[8] = { "Marketside Organic Spinach","","Groceries",5.13, ":/imgs/Groceries/spinach.png" };
    category[2].products[9] = { "Sweet Potatoes","","Groceries",4.24, ":/imgs/Groceries/sweetpotato.png" };

    category[3].products[0] = { "Vitesse Gaming Desk Computer Desk with Large Desk Mouse Pad","","Office", 110, ":/imgs/Office/gamingdesk.jpg" };
    category[3].products[1] = { "FlexiSpot Home Office Height Adjustable Standing Desk","","Office",250, ":/imgs/Office/homeoffice.jpg" };
    category[3].products[2] = { "SHW Cyrus 38-Inch Desk with Shelves","","Office", 67, ":/imgs/Office/desk.jpg" };
    category[3].products[3] = { "Techvida Rose gold desk organizer","","Office",17, ":/imgs/Office/deskorganizer.jpg" };
    category[3].products[4] = { "Child Drawing Art Set / Kit with 210 Pieces","","Office", 20, ":/imgs/Office/childdrawing.jpg" };
    category[3].products[5] = { "Pentel RSVP Ballpoint Pen","","Office",0.96, ":/imgs/Office/pens.jpg" };
    category[3].products[6] = { "Sheet High-Security Micro-Cut Paper Credit Card Shredder","","Office",41, ":/imgs/Office/shredder.jpg" };
    category[3].products[7] = { "Bostitch Office Heavy Duty Stapler","","Office",11, ":/imgs/Office/stapler.jpg" };
    category[3].products[8] = { "JIELISI 10in White Board","","Office", 12, ":/imgs/Office/whiteboard.png" };
    category[3].products[9] = { "Casio FX-991EX ","","Office", 18, ":/imgs/Office/casio.jpg" };

    category[4].products[0] = { "L'Oreal Paris Glow Paradise Lip Balm","","Beauty", 8, ":/imgs/Beauty/lipbalm.jpg" };
    category[4].products[1] = { "L'Oreal Paris Telescopic Lift Washable Makeup Mascara","","Beauty",12, ":/imgs/Beauty/mascara.jpg" };
    category[4].products[2] = { "Frozen 2 Lip Gloss","","Beauty", 5, ":/imgs/Beauty/lipgloss.png" };
    category[4].products[3] = { "Olay Regenerist Micro-Sculpting Cream Face Moisturizer","","Beauty",30, ":/imgs/Beauty/creamface.jpg" };
    category[4].products[4] = { "CeraVe Foaming Face Wash","","Beauty",14, ":/imgs/Beauty/facewash2.jpg" };
    category[4].products[5] = { "Dyson Supersonic Hair Dryer","","Beauty",270, ":/imgs/Beauty/hairdryer.jpg" };
    category[4].products[6] = { "Head & Shoulders 2 in 1 Dandruff Shampoo and Conditioner","","Beauty",12, ":/imgs/Beauty/shampoo.jpg" };
    category[4].products[7] = { "Lottie London Cheeky Kiss Lip & Cheek Stick","","Beauty",7, ":/imgs/Beauty/kisslip.jpg" };
    category[4].products[8] = { "Kenneth Cole Black Body Spray for Men","","Beauty",9, ":/imgs/Beauty/spray.jpg" };
    category[4].products[9] = { "Brickell Men's Purifying Charcoal Face Wash for Men","","Beauty",25, ":/imgs/Beauty/facewash.jpg" };

    category[5].products[0] = { "Platform Bed Frame with 4 Storage Drawers","","HomeFurniture",255, ":/imgs/Homefurniture/beddrawers.jpg" };
    category[5].products[1] = { "Allewie Brown Queen Size Bed Frame","","HomeFurniture",189, ":/imgs/Homefurniture/queenbed.jpg" };
    category[5].products[2] = { "Lily's Home Hanging Wall Clock","","HomeFurniture", 30, ":/imgs/Homefurniture/clock.jpg" };
    category[5].products[3] = { "Zimtown 5 Tier Heavy Duty Steel Shelving","","HomeFurniture",50 ,":/imgs/Homefurniture/steelshelving.jpg" };
    category[5].products[4] = { "Hoover PowerDash Cleaner","","HomeFurniture", 81, ":/imgs/Homefurniture/cleaner.jpg" };
    category[5].products[5] = { "Shower Curtain Christmas ","","HomeFurniture",30, ":/imgs/Homefurniture/curtain.jpg" };
    category[5].products[6] = { "Costway 1700W Portable Clothes Dryer","","HomeFurniture",330, ":/imgs/Homefurniture/clothdryer.jpg" };
    category[5].products[7] = { "BestMassage Heavy Duty Shelf ","","HomeFurniture",43, ":/imgs/Homefurniture/massageshelving.jpg" };
    category[5].products[8] = { "Sterilite Wide 4 Drawer","","HomeFurniture",44.78, ":/imgs/Homefurniture/widedrawer.png" };
    category[5].products[9] = { "Beautiful 6 Quart Touchscreen Air Fryer","","HomeFurniture",69, ":/imgs/Homefurniture/fryer.png" };

    category[6].products[0] = { "Franklin Sports Youth Baseball Backpack","","SportSupplies", 19.83, ":/imgs/Sportsupplies/baseballbackpack.png" };
    category[6].products[1] = { "Rawlings R400 Baseball Youth Backpack","","SportSupplies",43, ":/imgs/Sportsupplies/youthbakcpack.jpg" };
    category[6].products[2] = { "Rawlings Storm Girls Softball Bag","","SportSupplies",28, ":/imgs/Sportsupplies/softballbag.jpg" };
    category[6].products[3] = { "Easton Game Ready Baseball Backpack","","SportSupplies", 55, ":/imgs/Sportsupplies/eastonbackpack.jpg" };
    category[6].products[4] = { "Bounce Pro 7-Foot  Trampoline","","SportSupplies", 123, ":/imgs/Sportsupplies/trampoline.jpg" };
    category[6].products[5] = { "Nike Phantom VSN 2 Elite","","SportSupplies", 272, ":/imgs/Sportsupplies/nike.jpg" };
    category[6].products[6] = { "Nike Junior Mercurialx Proximo II","","SportSupplies",90, ":/imgs/Sportsupplies/nikejunior.png" };
    category[6].products[7] = { "Muck Kid's Rugged II Boot ","","SportSupplies",54, ":/imgs/Sportsupplies/boot.jpg" };
    category[6].products[8] = { "Duo Tennis Racquet set","","SportSupplies",35, ":/imgs/Sportsupplies/tennisracquet.jpg" };
    category[6].products[9] = { "Huffy 20 Boy Kids Bike","","SportSupplies", 78, ":/imgs/Sportsupplies/bike.jpg" };



    ProductionD(category[0], "6/5/2022");
    ProductionD(category[1], "12/2/2022");
    ProductionD(category[2], "1/1/2022");
    ProductionD(category[3], "3/9/2022");
    ProductionD(category[4], "4/5/2022");
    ProductionD(category[5], "2/9/2022");
    ProductionD(category[6], "3/10/2022");

    ExpirationD(category[0], "5/2/2023");
    ExpirationD(category[1], "12/9/2023");
    ExpirationD(category[2], "5/6/2023");
    ExpirationD(category[3], "21/7/2023");
    ExpirationD(category[4], "22/6/2023");
    ExpirationD(category[5], "1/10/2023");
    ExpirationD(category[6], "1/5/2023");

    for (int i = 0;i < 7;i++){
        for (int j = 0;j<10;j++){
            category[i].products[j].seller = "supermarket_owner";

        }
    }

    for (int id_p = 0; id_p < 10; id_p++) {
        category[0].products[id_p].id = Product_RandomID(1000, 9000);
        category[1].products[id_p].id = Product_RandomID(1000, 9000);
        category[2].products[id_p].id = Product_RandomID(1000, 9000);
        category[3].products[id_p].id = Product_RandomID(1000, 9000);
        category[4].products[id_p].id = Product_RandomID(1000, 9000);
        category[5].products[id_p].id = Product_RandomID(1000, 9000);
        category[6].products[id_p].id = Product_RandomID(1000, 9000);
    }
    updateproducts_seller();
    calcRating();
    makeCoupons();

}

void ProductionD(Category& nameofcategory, string date) {
    for (int i = 0; i < 10; i++) {
        nameofcategory.products[i].production_date = date;
    }
}

void ExpirationD(Category& nameofcategory, string date) {
    for (int i = 0; i < 10; i++) {
        nameofcategory.products[i].expiration_date = date;
    }
}

string Product_RandomID(int from, int to) {
    int RandomNumber = rand() % (to - from + 1) + from;
    return  "#" + to_string(RandomNumber);
}

void reorder_information() {
    for (int i = 0; i < counter_products; i++) {
        order_products.products_names[i] = "";
        order_products.products_categories[i] = "";
        order_products.products_codes[i] = "";
        order_products.product_images[i] = "";
        order_products.product_seller[i] = "";
        order_products.products_prices[i] = 0;
        order_products.products_quantities[i] = 0;

    }
    order_products.cartID="";
    for (int j = 0; j < videogames_counter; j++) {
        videogames_keys[j] = "";
    }
    counter_products = 0;
    videogames_counter = 0;
}


double price_after_discount(int products_count, double total_price,int& discount)
{
    if (products_count == 1) {
        discount = 0;
    }
    else if (products_count == 2) {
        total_price = total_price - (total_price * 0.05);
        discount = 5;
    }
    else if (products_count == 3) {
        total_price = total_price - (total_price * 0.1);
        discount = 10;
    }
    else if (products_count == 4) {
        total_price = total_price - (total_price * 0.15);
        discount = 15;
    }
    else if (products_count >= 5) {
        total_price = total_price - (total_price * 0.2);
        discount = 20;
    }
    return total_price;
}





bool email_checking(string email){
    int j = 0;
    bool email_check1 = false; //to check @
    bool email_check2 = false; // to check .
    while (email[j] != '\0') {
        if (email[j] == '@') {
            email_check1 = true;
        }
        if (email[j] == '.') {
            email_check2 = true;
        }
        j++;
    }
    if (email_check1&&email_check2)
        return true;
    else
        return false;
}

bool phonenumber_checking (string phone_number){
    int len_phone = phone_number.length();
    if (len_phone != 11) {
        return false;

    }
    return true;
}

bool password_checking (string password){
    int password_size = password.length();
    if (password_size>=8){
        return true;
    }
    return false;
}


int no_sellers;
sellers_information seller[max_nosellers];
void update_sellers_data(){
    QSqlQuery query;
    QString sql_query = "SELECT id , full_name ,username , email , password , phone_number ,no_subscribers , no_products, gender, profile_image FROM sellers_data";
    query.prepare(sql_query);
    query.exec();
    no_sellers = 0;
    int i = 0;
    while(query.next()){ //to be executed the condition must be true , so to execute inside the while loop , query.next() method must return true.
        seller[i].id = query.value(0).toString().toInt();
        seller[i].name = query.value(1).toString().toStdString();
        seller[i].username = query.value(2).toString().toStdString();
        seller[i].email = query.value(3).toString().toStdString();
        seller[i].password = query.value(4).toString().toStdString();
        seller[i].phone_number = query.value(5).toString().toStdString();
        seller[i].no_of_subscribers = query.value(6).toString().toInt();
        seller[i].no_products = query.value(7).toString().toInt(); //load data
        seller[i].gender = query.value(8).toString().toStdString();
        seller[i].profile_photo = query.value(9).toString();
        i++;
        no_sellers++;
    }

    int initial_ID = 900;

    for (int k = 0; k < no_sellers; k++) {
        seller[k].id = initial_ID;
        initial_ID++;
    }

    updateseller_subscribers();
    updatecustomer_sellerssubscribedto();
}


previous_userorders previous_orderedproducts;
int no_ofpreviousorderedproducts;
void update_previousorders(){

    QString user_id = QString::number(customer[user_index].id);
    QSqlQuery query;
    query.prepare("SELECT product_name , product_category, product_code, product_quantity, product_price, product_seller, product_image FROM orders_data WHERE user_id = :user_id");
    query.bindValue(":user_id", user_id);
    query.exec();

    // Loop through the results and print the product names
    no_ofpreviousorderedproducts = 0;
    while (query.next()) {
        previous_orderedproducts.product_names[no_ofpreviousorderedproducts] = query.value(0).toString().toStdString();
        previous_orderedproducts.product_categories[no_ofpreviousorderedproducts] = query.value(1).toString().toStdString();
        previous_orderedproducts.product_codes[no_ofpreviousorderedproducts] = query.value(2).toString().toStdString();
        previous_orderedproducts.product_quantities[no_ofpreviousorderedproducts] = query.value(3).toString().toInt();
        previous_orderedproducts.product_prices[no_ofpreviousorderedproducts] = query.value(4).toString().toFloat();
        previous_orderedproducts.product_sellers[no_ofpreviousorderedproducts] = query.value(5).toString().toStdString();
        previous_orderedproducts.product_images[no_ofpreviousorderedproducts] = query.value(6).toString();
        no_ofpreviousorderedproducts++;

    }
}




int noproducts_incategories[7] = {10,10,10,10,10,10,10};
string name_categories[no_categories] = {"Electronics","VideoGames","Groceries","Office","Beauty","HomeFurniture","SportsSupplies"};
void updateproducts_seller(){
    QSqlQuery query;
    for (int i = 0 ; i < no_categories;i++){
        query.prepare("SELECT name , id, price, quantity, seller, image_url , expiration_date FROM sellers_products WHERE category = :product_category");
        query.bindValue(":product_category", QString::fromStdString(name_categories[i]));
        query.exec();
        while(query.next()){
            category[i].products[noproducts_incategories[i]].name = query.value(0).toString().toStdString();
            //qDebug() << QString::fromStdString(category[i].products[noproducts_incategories[i]].name);
            category[i].products[noproducts_incategories[i]].id = query.value(1).toString().toStdString();
            category[i].products[noproducts_incategories[i]].price = query.value(2).toString().toFloat();
            category[i].products[noproducts_incategories[i]].stock = query.value(3).toString().toInt();
            category[i].products[noproducts_incategories[i]].seller = query.value(4).toString().toStdString();
            category[i].products[noproducts_incategories[i]].image_url = query.value(5).toString();
            category[i].products[noproducts_incategories[i]].expiration_date = query.value(6).toString().toStdString();
            category[i].products[noproducts_incategories[i]].category = name_categories[i];
            noproducts_incategories[i]++;
        }
    }
}

void calcRating(){
    QSqlQuery query;
    int sum_users; //counter
    int sum_rating;
    float product_rating;
    for (int i = 0; i < 7;i++){
        int no_products = noproducts_incategories[i];
        for (int j = 0;j < no_products;j++){
            query.prepare("SELECT rating from rating_products WHERE product_id = :product_id");
            sum_users = 0;
            sum_rating = 0;
            product_rating = 0;
            query.bindValue(":product_id",QString::fromStdString(category[i].products[j].id));
            query.exec();
            while (query.next()) {
                sum_rating += query.value(0).toString().toInt();
                sum_users++;
            }

            if (sum_users > 0) {
                product_rating = static_cast<float>(sum_rating) / sum_users;
                category[i].products[j].rating = product_rating;
            }
        }
    }
}

bool emptyInput(QString input){
    if (input.isEmpty())
        return true;
    return false;
}


void updateseller_subscribers(){
    QSqlQuery query;
    for(int i = 0; i < no_sellers;i++){
        query.prepare("SELECT id_subscribed_customer FROM sellers_customers WHERE id_seller = :seller_id");
        query.bindValue(":seller_id",seller[i].id);
        query.exec();

        int j = 0;
        while(query.next()){
            seller[i].customer_subscribers_id[j] = query.value(0).toString().toInt();
            seller[i].no_of_subscribers++;
            j++;
        }

    }
}

void updatecustomer_sellerssubscribedto(){
    QSqlQuery query;
    for (int i = 0 ;i < no_actualusers;i++){
        query.prepare("SELECT id_seller FROM sellers_customers WHERE id_subscribed_customer = :customer_id");
        query.bindValue(":customer_id",customer[i].id);
        query.exec();



        int j = 0;
        while (query.next()){
            customer[i].sellers_subscribedto_id[j] = query.value(0).toString().toInt();
            customer[i].no_ofsellerssubscribedto++;
            j++;

        }
    }
}

Coupons coupon[10];
void makeCoupons(){
    coupon[0].the_coupon = "A9BMPOVSK56C";
    coupon[0].the_coupon_value = 10;

    coupon[1].the_coupon = "O9PKJ5D12AQE";
    coupon[1].the_coupon_value = 20;

    for (int i = 2 ; i < 10 ; i++){
        coupon[i].the_coupon = generateCoupon();
        coupon[i].the_coupon_value = generateCouponValue(5, 101);
    }

}
string generateCoupon() {
    string Coupon = "\0";

    string Ch = "ABCDEFGHIJKLMN123456789OPQRSTUVWHYZ";

    for (int i = 0; i <12; i++) {
        Coupon += Ch[rand() % Ch.length()];
    }
    return Coupon;
}

int generateCouponValue(int from, int to) {
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}

QString TrimLeft(string S1) {

    for (short i = 0; i < S1.length(); i++) {

        if (S1[i] != ' ') {
            return QString::fromStdString(S1.substr(i, S1.length() - i));
        }
    }
    return "";
}

QString TrimRight(string S1) {

    for (short i = S1.length() - 1; i >= 0; i--) {

        if (S1[i] != ' ') {


            return  QString::fromStdString(S1.substr(0, i + 1));
        }

    }

    return "";
}



int randomNumber(int from, int to) {
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}
