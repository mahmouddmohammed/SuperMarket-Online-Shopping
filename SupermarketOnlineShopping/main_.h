#ifndef MAIN__H
#define MAIN__H

#include <string>
#include <iostream>
#include <QString>
#include <fstream>
using namespace std;

const int no_customers = 100;
const int no_categories = 7;
const int no_products = 10;
const int no_coupons = 10;
extern int no_actualusers; //one- Based
extern int user_index;
extern int counter_products;
extern string name_categories[no_categories];
extern string videogames_keys[100];
extern int videogames_counter;

struct users_information {
    int id;
    string name;
    string email;
    string phone_number;
    string password;
    string address;
    int sellers_subscribedto_id[100];
    int no_ofsellerssubscribedto = 0;
};
extern users_information customer[no_customers];

struct product {
    string name;
    string id;
    string category;
    double price;
    QString image_url;
    string production_date;
    string expiration_date;
    string seller;
    float rating = 0;
    int stock = 100;
};
struct Category {
    product products[100];

};

extern Category category[7];

struct order {
    string cartID;
    int CustomerID;
    string products_names[100];
    int products_quantities[100];
    double products_prices[100];
    string products_categories[100];
    string products_codes[100];
    QString product_images[100];
    string product_seller[100];

    bool apply_coupon[100] = {false};
    string coupon_text[100];
    float coupon_discount[100];

    double total_price;
    string shipping_address;
    string order_date;
    string order_status;
    string payment_method;
    bool payment_status; // 0 > failed ; 1> completed
};
extern order order_products;

const int max_products = 100;
struct previous_userorders {
    string product_names[max_products];
    string product_categories[max_products];
    string product_codes[max_products];
    int product_quantities[max_products];
    float product_prices[max_products];
    string product_sellers[max_products];
    QString product_images[max_products];
};

extern previous_userorders previous_orderedproducts;
extern int no_ofpreviousorderedproducts;


const int max_nosellers = 50;
extern int no_sellers; //one based
extern int seller_index;
struct sellers_information{
    int id;
    string name;
    string email;
    string password;
    int no_of_subscribers = 0;
    string email_subscribed_users[1000];
    string phone_number;
    string username;
    int no_products = 0;
    int customer_subscribers_id[100];
    string gender;
    QString profile_photo;

};
extern sellers_information seller[max_nosellers];

extern int noproducts_incategories[7];

struct Coupons{
    string the_coupon;
    int the_coupon_value;
};
extern Coupons coupon[10];

void update_users_date();
void updatedata(fstream& file_object,string file_location,string file_name);
bool connect_db();
void retrieve_data_db(QString name_column);
void products_data();
void ProductionD(Category& nameofcategory, string date);
void ExpirationD(Category& nameofcategory, string date);
string Product_RandomID(int from, int to);
void reorder_information();
double price_after_discount(int products_count, double total_price,int& discount);
bool email_checking(string email);
bool phonenumber_checking (string phone_number);
bool password_checking (string password);
void update_sellers_data();
void update_previousorders();
void updateproducts_seller();
void calcRating();
bool emptyInput(QString input);
void updateseller_subscribers();
void updatecustomer_sellerssubscribedto();
QString TrimLeft(string S1);
QString TrimRight(string S1);
int randomNumber(int from, int to);

void makeCoupons();
string generateCoupon();
int generateCouponValue(int from, int to);
#endif // MAIN__H
