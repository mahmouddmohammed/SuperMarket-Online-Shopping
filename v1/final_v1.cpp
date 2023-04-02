#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;




const int no_customers = 100;
const int no_categories = 7;
const int no_products = 10;
int videogames_counter = 0;
int no_actualusers = 2; //one- Based
int user_index;
int counter_products = 0;
string category_name;
string categories[no_categories] = { "Electronics", "VideoGames", "Groceries", "Office", "Beauty", "SportSupplies", "Home_Appliances & Furniture" };
string all_products[70];
bool make_order;
string videogames_keys[100];

struct users_information {
	int id;
	string name;
	string email;
	string phone_number;
	string password;
	string location;
};
users_information customer[no_customers]; //global

struct product {
	string name;
	string id;
	string category;
	double price;
	string production_date;
	string expiration_date;
};
struct Category {
	product products[10];
};
Category Electronics, VideoGames, Groceries, Office, Beauty, SportSupplies, HomeFurniture; // to be global

struct order {
	int CustomerID;
	double products_prices[100];
	string products_names[100];
	string products_categories[100];
	string products_codes[100];
};
order order_products;


void update_data();
int login_register_menu();
void login_();
void register_();
bool update_information(int index_no);
void view_menu();
void searchByName(string name_product);
void view_categories();
bool view_products(int);
void products_data();
void ProductionD(Category& nameofcategory, string date);
void ExpirationD(Category& nameofcategory, string date);
string Product_RandomID(int from, int to);
void product_information(Category nameOFcategory, int noOfProduct);
void Cart(Category cat, int number);
double review_order();
double price_after_discount(int products_count, double total_price);
char RandomCharchters(char from, char to);
string Generatekey();
double modify_order();
void backto_categories(int no);
void logout();
void exit_program();
void after_checkout();

int main() {
	update_data();
	int x = login_register_menu();
	if (x == 1) {
		return 1;
	}
	products_data();
	view_menu();
	return 0;
}
// HERE
int login_register_menu() {
	int no;
	cout << "*****************************************************" << endl;
	cout << "\t   SuperMarket Online Shopping \t \t" << endl;
	cout << "\t \t • Main Menu • \t \t" << endl;
	cout << "*****************************************************" << endl;
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter Your Choice: ";
	cin >> no;
	cin.ignore();
	switch (no)
	{
	case 1:
		register_();
		break;
	case 2:
		login_();
		break;
	case 3:
		return 1;
	default:
		cout << "Invalid Input" << endl;
		system("pause");
		login_register_menu();
		break;
	}
	return 0;
}

void update_data() {

	customer[0].name = "user1";
	customer[0].email = "user1@gmail.com";
	customer[0].location = "elzmalek";
	customer[0].phone_number = "01000006524";
	customer[0].password = "111";

	customer[1].name = "user2";
	customer[1].email = "user2@gmail.com";
	customer[1].location = "haram";
	customer[1].phone_number = "01136841269";
	customer[1].password = "222";




	int i = 2;
	fstream names, emails, locations, phones, passwords;
	names.open("names.txt", ios::in);
	if (names.is_open()) {
		while (getline(names, customer[i].name)) {
			i++;
			no_actualusers++;
		}
		names.close();
	}

	i = 2;
	emails.open("emails.txt", ios::in);
	if (emails.is_open()) {
		while (getline(emails, customer[i].email)) {
			i++;
		}
		emails.close();
	}

	i = 2;
	locations.open("locations.txt", ios::in);
	if (locations.is_open()) {
		while (getline(locations, customer[i].location)) {
			i++;
		}
		locations.close();
	}

	i = 2;
	phones.open("phone_numbers.txt", ios::in);
	if (phones.is_open()) {
		while (getline(phones, customer[i].phone_number)) {
			i++;
		}
		phones.close();
	}

	i = 2;
	passwords.open("passwords.txt", ios::in);
	if (passwords.is_open()) {
		while (getline(passwords, customer[i].password)) {
			i++;
		}
		passwords.close();
	}

	int initial_ID = 100;
	for (int k = 0; k <= no_actualusers; k++) {
		customer[k].id = initial_ID;
		initial_ID++;
	}


}


void register_() {
	system("CLS");
	cout << " \t SuperMarket Online Shopping" << endl;
	cout << "*****************************************************" << endl;
	cout << "\n";
	cout << " \t Welcome to register page" << endl;
	cout << "\n";
	cout << "****************Please write carefully****************" << endl;
	int last_index = no_actualusers;

	cout << "Type your name: ";

	getline(cin, customer[last_index].name);

	cout << "Type your email: ";
	cin >> customer[last_index].email;
	cin.ignore();
	int j = 0;
	bool email_check1 = false; //to check @
	bool email_check2 = false; // to check .
	while (customer[last_index].email[j] != '\0') {
		if (customer[last_index].email[j] == '@') {
			email_check1 = true;
		}
		if (customer[last_index].email[j] == '.') {
			email_check2 = true;
		}
		j++;
	}
	if (email_check1 && email_check2) {
		cout << "Correct Email , Please continue" << endl;
	}
	else {
		cout << "Wrong email" << endl;
		cout << "Sorry try again..." << endl;
		system("pause");
		register_();
	}


	cout << "Type your password: ";
	cin >> customer[last_index].password;

	cout << "Type your phone number: ";
	cin >> customer[last_index].phone_number;
	cin.ignore();
	int len_phone = customer[last_index].phone_number.length();
	if (len_phone != 11) {
		cout << "Wrong phone number" << endl;
		cout << "Sorry try again..." << endl;
		system("pause");
		register_();
	}

	cout << "Type your location: ";
	getline(cin, customer[last_index].location);

	cout << "You Successfully registered" << endl;
	cout << "Congratulations , You officially have account" << endl;
	cout << "Your ID: " << customer[last_index].id << endl;

	fstream names, emails, locations, phones, passwords;

	names.open("names.txt", ios::app);
	if (names.is_open()) {
		names << customer[last_index].name << endl;
		names.close();
	}

	emails.open("emails.txt", ios::app);
	if (emails.is_open()) {
		emails << customer[last_index].email << endl;
		emails.close();
	}

	locations.open("locations.txt", ios::app);
	if (locations.is_open()) {
		locations << customer[last_index].location << endl;
		locations.close();
	}

	phones.open("phone_numbers.txt", ios::app);
	if (phones.is_open()) {
		phones << customer[last_index].phone_number << endl;
		phones.close();
	}


	passwords.open("passwords.txt", ios::app);
	if (passwords.is_open()) {
		passwords << customer[last_index].password << endl;
		passwords.close();
	}
	no_actualusers++;
	system("pause");
	login_();
}


void login_() {
	system("CLS");
	cout << " \t SuperMarket Online Shopping" << endl;
	cout << "*****************************************************" << endl;
	cout << "\n";
	cout << " \t Welcome to Login page" << endl;
	cout << " \t No of actual users: " << no_actualusers << endl;
	cout << "\n";
	cout << "****************Please write carefully****************" << endl;
	string email_login;
	string password_login;
	char modify;
	cout << "Type your email: ";
	cin >> email_login;
	cout << "Write Your password: ";
	cin >> password_login;
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
		cout << "Your ID: " << customer[no_index].id << endl;
		cout << "Login Success" << endl;
		cout << "Do you wanna modify your information? y/n: ";
		cin >> modify;
		if (modify == 'y' || modify == 'Y') {
			update_information(no_index);
		}
	}
	else {
		cout << "Invalid email or password" << endl;
		cout << "if you dont register , you have to register first" << endl;
		login_register_menu();

	}

}

bool update_information(int index_no) {
	system("CLS");
	bool email_check1;
	bool email_check2;
	int len_phone;
	int j;
	cout << " \t SuperMarket Online Shopping" << endl;
	cout << "*****************************************************" << endl;
	cout << "\n";
	cout << " \t Welcome to Update-Information page" << endl;
	cout << " \t No of actual users: " << no_actualusers << endl;
	cout << "\n";
	cout << "****************Please write carefully****************" << endl;
	if (customer[index_no].name == "user1" || customer[index_no].name == "user2") {
		cout << "Sorry , Data of user1 & user2 cant be changed" << endl;
		return false;
	}
	cout << "what do you wanna change in your profile information" << endl;
	cout << "Sorry, ID CAN'T BE CHANGED ^3" << endl;
	cout << "1. Name" << endl;
	cout << "2. Password" << endl;
	cout << "3. Phone Number" << endl;
	cout << "4. Location" << endl;
	cout << "5. Email" << endl;
	int no;
	const int no_lines = no_actualusers;
	cout << "Enter Number: ";
	cin >> no;
	cin.ignore();
	fstream update_data;
	string backup[no_customers];
	int i = 0;

	switch (no) {
	case 1:
		cout << "Enter Your new name: ";
		getline(cin, customer[index_no].name);
		cout << "You changed your name" << endl;

		update_data.open("names.txt", ios::out); // that's output will make overwrite 
		if (update_data.is_open()) {
			for (int k = 2; k < no_actualusers; k++) {
				if (k == (index_no)) {
					update_data << customer[index_no].name << endl;
				}
				else {
					update_data << customer[k].name << endl;
				}
			}
			update_data.close();
		}
		system("pause");
		break;
	case 2:
		cout << "Enter Your new password: ";
		cin >> customer[index_no].password;
		cin.ignore();
		cout << "You changed your password" << endl;
		update_data.open("passwords.txt", ios::out); // that's output will make overwrite 
		if (update_data.is_open()) {
			for (int k = 2; k < no_actualusers; k++) {
				if (k == (index_no)) {
					update_data << customer[index_no].password << endl;
				}
				else {
					update_data << customer[k].password << endl;
				}
			}
			update_data.close();
		}
		system("pause");
		login_();
		break;
	case 3:
		cout << "Enter Your new phone number: ";
		cin >> customer[index_no].phone_number;
		cin.ignore();
		len_phone = customer[user_index].phone_number.length();
		if (len_phone != 11) {
			cout << "Wrong phone number" << endl;
			cout << "Sorry try again..." << endl;
			system("pause");
			update_information(user_index);
		}
		cout << "You changed your phone number" << endl;
		update_data.open("phone_numbers.txt", ios::out); // that's output will make overwrite 
		if (update_data.is_open()) {
			for (int k = 2; k < no_actualusers; k++) {
				if (k == (index_no)) {
					update_data << customer[index_no].phone_number << endl;
				}
				else {
					update_data << customer[k].phone_number << endl;
				}
			}
			update_data.close();
		}
		system("pause");
		break;
	case 4:
		cout << "Enter Your new location: ";
		cin.ignore();
		getline(cin, customer[index_no].location);
		cout << "You changed your location" << endl;
		update_data.open("locations.txt", ios::out); // that's output will make overwrite 
		if (update_data.is_open()) {
			for (int k = 2; k < no_actualusers; k++) {
				if (k == (index_no)) {
					update_data << customer[index_no].location << endl;
				}
				else {
					update_data << customer[k].location << endl;
				}
			}
			update_data.close();
		}
		system("pause");
		break;
	case 5:
		cout << "Enter Your new email: ";
		cin >> customer[index_no].email;
		cin.ignore();
		j = 0;
		email_check1 = false; //to check @
		email_check2 = false; // to check .
		while (customer[user_index].email[j] != '\0') {
			if (customer[user_index].email[j] == '@') {
				email_check1 = true;
			}
			if (customer[user_index].email[j] == '.') {
				email_check2 = true;
			}
			j++;
		}
		if (email_check1 && email_check2) {
			cout << "Valid email" << endl;
		}
		else {
			cout << "Wrong email" << endl;
			cout << "Sorry try again..." << endl;
			system("pause");
			update_information(user_index);
		}
		cout << "You successfully changed your email" << endl;
		update_data.open("emails.txt", ios::out); // that's output will make overwrite 
		if (update_data.is_open()) {
			for (int k = 2; k < no_actualusers; k++) {
				if (k == (index_no)) {
					update_data << customer[index_no].email << endl;
				}
				else {
					update_data << customer[k].email << endl;
				}
			}
			update_data.close();
		}
		system("pause");
		login_();
		break;
	default:
		cout << "Invalid Input" << endl;
		update_information(user_index);
		break;

	}
}

//---------------------------------------------------------------
void products_data() {
	Electronics.products[0].name = "MSI Katana GF66 Gaming Laptop";
	Electronics.products[0].id = "";
	Electronics.products[0].category = "Electronics - Laptop";
	Electronics.products[0].price = 1700;
	Electronics.products[1] = { "Acer Aspire 5","","Electronics - Laptop",550 };
	Electronics.products[2] = { "LG 55  Class 4K UHD 2160P","","Electronics",360 };
	Electronics.products[3] = { "LG 65  Class 4K UHD ","","Electronics",1300 };
	Electronics.products[4] = { "SAMSUNG 65 Class 4K Crystal","","Electronics",478 };
	Electronics.products[5] = { "Apple Watch Series 8 GPS","","Electronics",360 };
	Electronics.products[6] = { "SAMSUNG Galaxy Watch 4","","Electronics",170 };
	Electronics.products[7] = { "Gateway Notebook 11.6","","Electronics - Mobile Phones",192 };
	Electronics.products[8] = { "Straight Talk Apple iPhone 11, 64GB","","Electronics - Mobile Phones",250 };
	Electronics.products[9] = { "Apple iPhone 12, 64GB","","Electronics - Mobile Phones",500 };


	VideoGames.products[0] = { "Red Dead Redemption 2","","VideoGames - PlayStation 4",20 };
	VideoGames.products[1] = { "FIFA 23","","VideoGames - PlayStation 4",40 };
	VideoGames.products[2] = { "Grand Theft Auto V","","VideoGames - PlayStation 5",20 };
	VideoGames.products[3] = { "Pro Evolution Soccer (PES)","","VideoGames - PlayStation 4",40 };
	VideoGames.products[4] = { "Call of Duty: Modern Warfare II","","VideoGames - PlayStation 5",70 };
	VideoGames.products[5] = { "Marvel’s Spider-Man: Miles Morales Ultimate Launch Edition","","VideoGames - PlayStation 5",70 };
	VideoGames.products[6] = { "Crysis Remastered Trilogy","","VideoGames - PlayStation 4",35 };
	VideoGames.products[7] = { "Battlefield V","","VideoGames - PlayStation 4",20 };
	VideoGames.products[8] = { "Resident Evil 4","","VideoGames - PlayStation 4",60 };
	VideoGames.products[9] = { "Hogwarts Legacy Deluxe Edition","","VideoGames - PlayStation 4",70 };

	Groceries.products[0] = { "Cheddar Smoked Sausage","","Groceries",3.96 };
	Groceries.products[1] = { "Freshness Guaranteed Boneless Chicken Thighs","","Groceries",11.38 };
	Groceries.products[2] = { "Freshness Guaranteed Chicken Breast Tenderloins","","Groceries",8.94 };
	Groceries.products[3] = { "HERSHEY'S and REESE'S, Chocolate Assortment Treats","","Groceries",7.48 };
	Groceries.products[4] = { "CADBURY, MINI EGGS Milk Chocolate with a Crisp Sugar Shell","","Groceries",3.84 };
	Groceries.products[5] = { "REESE'S, Assorted Milk Chocolate","","Groceries",10.98 };
	Groceries.products[6] = { "Sadler's Smokehouse Mesquite Smoked Sliced Beef Brisket","","Groceries",23.04 };
	Groceries.products[7] = { "Fresh Sweet Corn","","Groceries",0.60 };
	Groceries.products[8] = { "Marketside Organic Spinach","","Groceries",5.13 };
	Groceries.products[9] = { "Sweet Potatoes","","Groceries",4.24 };

	Office.products[0] = { "Vitesse Gaming Desk Computer Desk with Large Desk Mouse Pad","","Office", 110 };
	Office.products[1] = { "FlexiSpot Home Office Height Adjustable Standing Desk","","Office",250 };
	Office.products[2] = { "SHW Cyrus 38-Inch Desk with Shelves","","Office", 67 };
	Office.products[3] = { "Techvida Rose gold desk organizer","","Office",17 };
	Office.products[4] = { "Child Drawing Art Set / Kit with 210 Pieces","","Office", 20 };
	Office.products[5] = { "Pentel RSVP Ballpoint Pen","","Office",0.96 };
	Office.products[6] = { "Sheet High-Security Micro-Cut Paper Credit Card Shredder","","Office",41 };
	Office.products[7] = { "Bostitch Office Heavy Duty Stapler","","Office",11 };
	Office.products[8] = { "JIELISI 10in White Board","","Office", 12 };
	Office.products[9] = { "Casio FX-991EX ","","Office", 18 };

	Beauty.products[0] = { "L'Oreal Paris Glow Paradise Lip Balm","","Beauty", 8 };
	Beauty.products[1] = { "L'Oreal Paris Telescopic Lift Washable Makeup Mascara","","Beauty",12 };
	Beauty.products[2] = { "Frozen 2 Lip Gloss","","Beauty", 5 };
	Beauty.products[3] = { "Olay Regenerist Micro-Sculpting Cream Face Moisturizer","","Beauty",30 };
	Beauty.products[4] = { "CeraVe Foaming Face Wash","","Beauty",14 };
	Beauty.products[5] = { "Dyson Supersonic Hair Dryer","","Beauty",270 };
	Beauty.products[6] = { "Head & Shoulders 2 in 1 Dandruff Shampoo and Conditioner","","Beauty",12 };
	Beauty.products[7] = { "Lottie London Cheeky Kiss Lip & Cheek Stick","","Beauty",7 };
	Beauty.products[8] = { "Kenneth Cole Black Body Spray for Men","","Beauty",9 };
	Beauty.products[9] = { "Brickell Men's Purifying Charcoal Face Wash for Men","","Beauty",25 };

	SportSupplies.products[0] = { "Franklin Sports Youth Baseball Backpack","","SportSupplies", 19.83 };
	SportSupplies.products[1] = { "Rawlings R400 Baseball Youth Backpack","","SportSupplies",43 };
	SportSupplies.products[2] = { "Rawlings Storm Girls Softball Bag","","SportSupplies",28 };
	SportSupplies.products[3] = { "Easton Game Ready Baseball Backpack","","SportSupplies", 55 };
	SportSupplies.products[4] = { "Bounce Pro 7-Foot  Trampoline","","SportSupplies", 123 };
	SportSupplies.products[5] = { "Nike Phantom VSN 2 Elite","","SportSupplies", 272 };
	SportSupplies.products[6] = { "Nike Junior Mercurialx Proximo II","","SportSupplies",90 };
	SportSupplies.products[7] = { "Muck Kid's Rugged II Boot ","","SportSupplies",54 };
	SportSupplies.products[8] = { "Duo Tennis Racquet set","","SportSupplies",35 };
	SportSupplies.products[9] = { "Huffy 20 Boy Kids Bike","","SportSupplies", 78 };

	HomeFurniture.products[0] = { "Platform Bed Frame with 4 Storage Drawers","","HomeFurniture",255 };
	HomeFurniture.products[1] = { "Allewie Brown Queen Size Bed Frame","","HomeFurniture",189 };
	HomeFurniture.products[2] = { "Lily's Home Hanging Wall Clock","","HomeFurniture", 30 };
	HomeFurniture.products[3] = { "Zimtown 5 Tier Heavy Duty Steel Shelving","","HomeFurniture", 50 };
	HomeFurniture.products[4] = { "Hoover PowerDash Cleaner","","HomeFurniture", 81 };
	HomeFurniture.products[5] = { "Shower Curtain Christmas ","","HomeFurniture",30 };
	HomeFurniture.products[6] = { "Costway 1700W Portable Clothes Dryer","","HomeFurniture",330 };
	HomeFurniture.products[7] = { "BestMassage Heavy Duty Shelf ","","HomeFurniture",43 };
	HomeFurniture.products[8] = { "Sterilite Wide 4 Drawer","","HomeFurniture",44.78 };
	HomeFurniture.products[9] = { "Beautiful 6 Quart Touchscreen Air Fryer","","HomeFurniture",69 };

	ProductionD(Electronics, "6/5/2022");
	ProductionD(VideoGames, "12/2/2022");
	ProductionD(Groceries, "1/1/2022");
	ProductionD(Office, "3/9/2022");
	ProductionD(Beauty, "4/5/2022");
	ProductionD(SportSupplies, "3/10/2022");
	ProductionD(HomeFurniture, "2/9/2022");

	ExpirationD(Electronics, "5/2/2023");
	ExpirationD(VideoGames, "12/9/2023");
	ExpirationD(Groceries, "5/6/2023");
	ExpirationD(Office, "21/7/2023");
	ExpirationD(Beauty, "22/6/2023");
	ExpirationD(SportSupplies, "1/5/2023");
	ExpirationD(HomeFurniture, "1/10/2023");

	for (int id_p = 0; id_p < 10; id_p++) {
		Electronics.products[id_p].id = Product_RandomID(1000, 9000);
		VideoGames.products[id_p].id = Product_RandomID(1000, 9000);
		Groceries.products[id_p].id = Product_RandomID(1000, 9000);
		Office.products[id_p].id = Product_RandomID(1000, 9000);
		Beauty.products[id_p].id = Product_RandomID(1000, 9000);
		SportSupplies.products[id_p].id = Product_RandomID(1000, 9000);
		HomeFurniture.products[id_p].id = Product_RandomID(1000, 9000);
	}

	for (int i = 0; i < 10; i++) {
		all_products[i] = Electronics.products[i].name;
	}
	for (int a = 10, b = 0; a < 20; a++, b++) {
		all_products[a] = VideoGames.products[b].name;
	}
	for (int c = 20, d = 0; c < 30; c++, d++) {
		all_products[c] = Groceries.products[d].name;
	}
	for (int e = 30, f = 0; e < 40; e++, f++) {
		all_products[e] = Office.products[f].name;
	}
	for (int g = 40, h = 0; g < 50; g++, h++) {
		all_products[g] = Beauty.products[h].name;
	}
	for (int j = 50, k = 0; j < 60; j++, k++) {
		all_products[j] = SportSupplies.products[k].name;
	}
	for (int l = 60, m = 0; l < 70; l++, m++) {
		all_products[l] = HomeFurniture.products[m].name;
	}
}

void view_menu() {
	system("CLS");
	int no;
	string product_name;
	cout << "*****************************************************" << endl;
	cout << "\t   SuperMarket Online Shopping \t \t" << endl;
	cout << "\t \t • Home Menu • \t \t" << endl;
	cout << "*****************************************************" << endl;
	cout << "1. View Categories" << endl;
	cout << "2. Search by name of the product" << endl;
	cout << "Enter Your Choice: ";
	cin >> no;
	cin.ignore();
	switch (no)
	{
	case 1:
		view_categories();
		break;
	case 2:
		cout << "Enter the name of product if you want to search by name: ";
		getline(cin, product_name);
		searchByName(product_name);
		system("pause");
		break;
	default:
		cout << "Invalid Input" << endl;
		view_menu();
		break;
	}
}

void view_categories() {
	system("CLS");
	for (int i = 0; i < no_categories; i++) {
		cout << i + 1 << ". " << categories[i] << endl;
	}
	int no;
	cout << "Choose a number: ";
	cin >> no;
	view_products(no);

}

// hna b2a lazm nstkhdm enum 3shan nrbot elrkm mn fok b esm cateogary 3shan n3rfh mn w nstkhd,h fy struct aw mmkn ydwy 3ady 
bool view_products(int number) {
	system("CLS");
	int num;
	char do_buy;
	char buy_again;
	bool make_order;
	string key;
	char modify_cart;
	double total_price_beforemodify;
	double total_price_aftermodify;
	switch (number) {
	case 1:
		category_name = "Electronics";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << Electronics.products[i].name << endl;
		}
		cout << "0. Back to categories" << endl;
		cout << "Enter number of product :";
		cin >> num;
		backto_categories(num);
		product_information(Electronics, num - 1);

		cout << "Do you want to buy this product?y/n: ";
		cin >> do_buy;
		if (do_buy == 'y' || do_buy == 'Y') {
			Cart(Electronics, num - 1);
			counter_products++;
			make_order = true;

		}
		else {
			system("CLS");
			view_categories();
			return false;
		}
		break;
	case 2:
		category_name = "VideoGames";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << VideoGames.products[i].name << endl;
		}
		cout << "0. Back to categories" << endl;
		cout << "Enter number of product :";
		cin >> num;
		backto_categories(num);
		product_information(VideoGames, num - 1);

		cout << "Do you want to buy this product?y/n: ";
		cin >> do_buy;
		if (do_buy == 'y' || do_buy == 'Y') {
			Cart(VideoGames, num - 1);
			counter_products++;
			key = Generatekey();
			cout << "Serial key to play online: " << key << endl;
			videogames_keys[videogames_counter] = key;
			videogames_counter++;
			make_order = true;

		}
		else {
			system("CLS");
			view_categories();
			return false;
		}
		break;
	case 3:
		category_name = "Groceries";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << Groceries.products[i].name << endl;
		}
		cout << "0. Back to categories" << endl;
		cout << "Enter number of product :";
		cin >> num;
		backto_categories(num);
		product_information(Groceries, num - 1);

		cout << "Do you want to buy this product?y/n: ";
		cin >> do_buy;
		if (do_buy == 'y' || do_buy == 'Y') {
			Cart(Groceries, num - 1);
			counter_products++;
			make_order = true;
		}
		else {
			system("CLS");
			view_categories();
			return false;
		}
		break;
	case 4:
		category_name = "Office";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << Office.products[i].name << endl;
		}
		cout << "0. Back to categories" << endl;
		cout << "Enter number of product :";
		cin >> num;
		backto_categories(num);
		product_information(Office, num - 1);

		cout << "Do you want to buy this product?y/n: ";
		cin >> do_buy;
		if (do_buy == 'y' || do_buy == 'Y') {
			Cart(Office, num - 1);
			counter_products++;
			make_order = true;
		}
		else {
			system("CLS");
			view_categories();
			return false;
		}
		break;
	case 5:
		category_name = "Beauty";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << Beauty.products[i].name << endl;
		}
		cout << "0. Back to categories" << endl;
		cout << "Enter number of product :";
		cin >> num;
		backto_categories(num);
		product_information(Beauty, num - 1);

		cout << "Do you want to buy this product?y/n: ";
		cin >> do_buy;
		if (do_buy == 'y' || do_buy == 'Y') {
			Cart(Beauty, num - 1);
			counter_products++;
			make_order = true;

		}
		else {
			system("CLS");
			view_categories();
			return false;
		}
		break;
	case 6:
		category_name = "SportSupplies";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << SportSupplies.products[i].name << endl;
		}
		cout << "0. Back to categories" << endl;
		cout << "Enter number of product :";
		cin >> num;
		backto_categories(num);
		product_information(SportSupplies, num - 1);

		cout << "Do you want to buy this product?y/n: ";
		cin >> do_buy;
		if (do_buy == 'y' || do_buy == 'Y') {
			Cart(SportSupplies, num - 1);
			counter_products++;
			make_order = true;
		}
		else {
			system("CLS");
			view_categories();
			return false;
		}
		break;
	case 7:
		category_name = "HomeFurniture";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << HomeFurniture.products[i].name << endl;
		}
		cout << "0. Back to categories" << endl;
		cout << "Enter number of product :";
		cin >> num;
		backto_categories(num);
		product_information(HomeFurniture, num - 1);

		cout << "Do you want to buy this product?y/n: ";
		cin >> do_buy;
		if (do_buy == 'y' || do_buy == 'Y') {
			Cart(HomeFurniture, num - 1);
			counter_products++;
			make_order = true;
		}
		else {
			system("CLS");
			view_categories();
			return false;
		}
		break;

	default:
		cout << "Invalid Input" << endl;
		system("pause");
		view_categories();
	}

	cout << "Do You want to checkout? y/n: ";
	cin >> buy_again;
	if (buy_again == 'n' || buy_again == 'N') {
		view_categories();
	}
	else if (buy_again == 'y' || buy_again == 'Y') {
		if (counter_products > 0) { // that means that customer buys at least one product
			total_price_beforemodify = review_order();
			cout << "Do you wanna modify the order? y/n: ";
			cin >> modify_cart;
			if (modify_cart == 'y' || modify_cart == 'Y') {
				// function of modify order
				total_price_aftermodify = modify_order();
				// calculate the total price and discount
				price_after_discount(counter_products, total_price_aftermodify);
				system("pause");
			}
			else {
				// calculate the total price and discount
				price_after_discount(counter_products, total_price_beforemodify);
				system("pause");
				//exit_program();

			}
			after_checkout();

		}
	}
	else {
		cout << "Invalid Input ";
		system("pause");
		view_categories();
	}




}




void searchByName(string name_product) {
	bool product_found = false;
	int product_no;
	int index_no;
	char buy;
	char buy_again;
	//cout << name_product << endl;
	for (int i = 0; i < 70; i++) {
		//cout << all_products[i] << endl;
		if (name_product == all_products[i]) {
			product_found = true;
			product_no = i;
			break;
		}
		else {
			product_found = false;
		}
	}
	//cout << product_found;
	if (product_found) {
		if (product_no >= 0 && product_no < 10) { //hoa bycheck elawl 3la kol wahda bltrteb lw lka wahda true bytl3 mn kolh
			index_no = product_no;
			//cout << "TEST";
			product_information(Electronics, index_no);

			cout << "Do you wanna buy it? y/n: ";
			cin >> buy;
			if (buy == 'y' || buy == 'Y') {
				Cart(Electronics, index_no);
				counter_products++;
				make_order = true;
				cout << "Do You want to checkout? y/n: ";
				cin >> buy_again;
				if (buy_again == 'n' || buy_again == 'N') {
					view_categories();

				}
			}
			else {
				view_categories();
			}
		}
		else if (product_no >= 10 && product_no < 20) {
			index_no = product_no - 10;
			//cout << "TEST";
			product_information(VideoGames, index_no);

			cout << "Do you wanna buy it? y/n: ";
			cin >> buy;
			if (buy == 'y' || buy == 'Y') {
				Cart(VideoGames, index_no);
				counter_products++;
				make_order = true;
				cout << "Do You want to checkout? y/n: ";
				cin >> buy_again;
				if (buy_again == 'n' || buy_again == 'N') {
					view_categories();
				}
			}
			else {
				view_categories();
			}
		}
		else if (product_no >= 20 && product_no < 30) {
			index_no = product_no - 20;
			//cout << "TEST";
			product_information(Groceries, index_no);

			cout << "Do you wanna buy it? y/n: ";
			cin >> buy;
			if (buy == 'y' || buy == 'Y') {
				Cart(Groceries, index_no);
				counter_products++;
				make_order = true;
				cout << "Do You want to checkout? y/n: ";
				cin >> buy_again;
				if (buy_again == 'n' || buy_again == 'N') {
					view_categories();
				}
			}
			else {
				view_categories();
			}
		}
		else if (product_no >= 30 && product_no < 40) {
			index_no = product_no - 30;
			product_information(Office, index_no);

			cout << "Do you wanna buy it? y/n: ";
			cin >> buy;
			if (buy == 'y' || buy == 'Y') {
				Cart(Office, index_no);
				counter_products++;
				make_order = true;
				cout << "Do You want to checkout? y/n: ";
				cin >> buy_again;
				if (buy_again == 'n' || buy_again == 'N') {
					view_categories();
				}
			}
			else {
				view_categories();
			}
		}
		else if (product_no >= 40 && product_no < 50) {
			index_no = product_no - 40;
			product_information(Beauty, index_no);

			cout << "Do you wanna buy it? y/n: ";
			cin >> buy;
			if (buy == 'y' || buy == 'Y') {
				Cart(Beauty, index_no);
				counter_products++;
				make_order = true;
				cout << "Do You want to checkout? y/n: ";
				cin >> buy_again;
				if (buy_again == 'n' || buy_again == 'N') {
					view_categories();
				}
			}
			else {
				view_categories();
			}
		}
		else if (product_no >= 50 && product_no < 60) {
			index_no = product_no - 50;
			product_information(SportSupplies, index_no);

			cout << "Do you wanna buy it? y/n: ";
			cin >> buy;
			if (buy == 'y' || buy == 'Y') {
				Cart(SportSupplies, index_no);
				counter_products++;
				make_order = true;
				cout << "Do You want to checkout? y/n: ";
				cin >> buy_again;
				if (buy_again == 'n' || buy_again == 'N') {
					view_categories();
				}
			}
			else {
				view_categories();
			}
		}
		else if (product_no >= 60 && product_no < 70) {
			index_no = product_no - 60;
			product_information(HomeFurniture, index_no);

			cout << "Do you wanna buy it? y/n: ";
			cin >> buy;
			if (buy == 'y' || buy == 'Y') {
				Cart(HomeFurniture, index_no);
				counter_products++;
				make_order = true;
				cout << "Do You want to checkout? y/n: ";
				cin >> buy_again;
				if (buy_again == 'n' || buy_again == 'N') {
					view_categories();
				}
			}
			else {
				view_categories();
			}
		}
		// lw yes b if cond khaly function trg3 index_no l total price fa mn khlalh n3rf ngeb kol elbyanat
		// mmkn t3ml m3a kol switch case fok ,wdo3 char buy , w t3ml variable esmh category tkhtb feh esm category fy kol case
		// w variable tstore feh esm product
	}
	else {
		cout << "Sorry we couldnt find this product...!";
	}
	//system("pause");
}

void product_information(Category nameOFcategory, int noOfProduct) {
	system("CLS");
	cout << "Name: " << nameOFcategory.products[noOfProduct].name << endl;
	cout << "ID: " << nameOFcategory.products[noOfProduct].id << endl;
	cout << "Category: " << nameOFcategory.products[noOfProduct].category << endl;
	cout << "Production Date: " << nameOFcategory.products[noOfProduct].production_date << endl;
	cout << "Expired Date:  " << nameOFcategory.products[noOfProduct].expiration_date << endl;
	cout << "Price: " << nameOFcategory.products[noOfProduct].price << "$" << endl;
}


void Cart(Category category_name, int number) {
	order_products.CustomerID = customer[user_index].id;
	order_products.products_prices[counter_products] = category_name.products[number].price;
	order_products.products_names[counter_products] = category_name.products[number].name;
	order_products.products_categories[counter_products] = category_name.products[number].category;
	order_products.products_codes[counter_products] = category_name.products[number].id;
	//return order_products;
	// order_products is the variable that has the data type of struct so you can use any member in it
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

double review_order() {
	int i, j;
	double total_price = 0;
	int counter_key = 0;
	system("CLS");
	cout << "-THE CART-" << endl;
	cout << "Customer ID: " << order_products.CustomerID << endl;
	cout << "No of products you bought: " << counter_products << endl;
	cout << "--------------------------------------------------------" << endl;

	for (i = 0, j = 0; i < counter_products; i++, j++) {
		if (order_products.products_names[i] == "") {
			if (i != 0) {
				j = i - 1;
			}

			continue;
		}
		if (order_products.products_categories[i] == "VideoGames - PlayStation 4" || order_products.products_categories[i] == "VideoGames - PlayStation 5") {
			cout << "Product " << j + 1 << endl;
			cout << "Product Name: " << order_products.products_names[i] << endl;
			cout << "Category of the product: " << order_products.products_categories[i] << endl;
			cout << "Product Code: " << order_products.products_codes[i] << endl;
			cout << "Serial Key to play online: " << videogames_keys[counter_key] << endl;
			cout << "Product Price: " << order_products.products_prices[i] << "$" << endl;
			cout << "--------------------------------------------------------" << endl;
			counter_key++;
			//j++;
			continue;
		}
		cout << "Product " << j + 1 << endl;
		cout << "Product Name: " << order_products.products_names[i] << endl;
		cout << "Category of the product: " << order_products.products_categories[i] << endl;
		cout << "Product Code: " << order_products.products_codes[i] << endl;
		cout << "Product Price: " << order_products.products_prices[i] << "$" << endl;
		cout << "--------------------------------------------------------" << endl;
		//j++;
	}
	for (int q = 0; q < counter_products; q++) {
		total_price += order_products.products_prices[q];
	}

	return total_price;
}

double price_after_discount(int products_count, double total_price)
{
	if (products_count == 1) {
		cout << "There is no discount\n";
		cout << "Total price is : " << total_price << endl;
	}
	else if (products_count == 2) {
		total_price = total_price - (total_price * 0.05);
		cout << "There is 5% discount\n";
		cout << "Total price is : " << total_price << endl;
	}
	else if (products_count == 3) {
		total_price = total_price - (total_price * 0.1);
		cout << "There is 10% discount\n";
		cout << "Total price is : " << total_price << endl;
	}
	else if (products_count == 4) {
		total_price = total_price - (total_price * 0.15);
		cout << "There is 15% discount\n";
		cout << "Total price is : " << total_price << endl;
	}
	else if (products_count >= 5) {
		total_price = total_price - (total_price * 0.2);
		cout << "There is 20% discount\n";
		cout << "Total price is : " << total_price << endl;
	}
	return total_price;
}

char RandomCharchters(char from, char to) {
	return rand() % (to - from + 1) + from;
}
string Generatekey() {
	srand(time(NULL));
	string Key = "";
	for (int j = 1; j <= 16; j++) {
		Key += RandomCharchters('A', 'Z');
		if (j % 4 == 0 && j != 16) {
			Key += '-';
		}
	}
	return Key;
}

double modify_order() {
	int num, numX;
	double total_price;
	cout << "1.add Product" << endl;
	cout << "2.remove product \n";
	cout << "3.Cancel modify" << endl;
	cout << "Enter your choice: ";
	cin >> num;

	switch (num) {

	case 1:
		view_categories();
		break;

	case 2:
		cout << "Enter the number of product you want to remove :";
		cin >> numX;
		order_products.products_names[numX - 1] = "";
		order_products.products_categories[numX - 1] = "";
		order_products.products_codes[numX - 1] = "";
		order_products.products_prices[numX - 1] = 0;
		total_price = review_order();
		return total_price;
		break;
	case 3:
		review_order();
		break;
	}
}

void backto_categories(int no) {
	if (no == 0) {
		view_categories();
	}
}

void logout() {
	for (int i = 0; i < counter_products; i++) {
		order_products.products_names[i] = "";
		order_products.products_categories[i] = "";
		order_products.products_codes[i] = "";
		order_products.products_prices[i] = 0;
	}
	for (int j = 0; j < videogames_counter; j++) {
		videogames_keys[j] = "";
	}
	view_menu();
}
void exit_program() {
	exit(0);
}

void after_checkout() {
	int no;
	system("CLS");
	cout << " \t SuperMarket Online Shopping" << endl;
	cout << "*****************************************************" << endl;
	cout << "\n";
	cout << " \t Welcome to After Checkout Menu" << endl;
	cout << " \t No of actual users: " << no_actualusers << endl;
	cout << "\n";
	cout << "****************Please write carefully****************" << endl;
	cout << "1. Back to Home menu (View Categories & Search by name) " << endl;
	cout << "2. Logout" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter No: ";
	cin >> no;
	switch (no) {
	case 1:
		system("CLS");
		logout();
		break;
	case 2:
		system("CLS");
		login_register_menu();
		break;
	case 3:
		exit_program();
		break;
	default:
		cout << "Invalid Input..." << endl;
		system("pause");
		after_checkout();
		break;
	}

}
