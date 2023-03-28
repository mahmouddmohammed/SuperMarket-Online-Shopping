#include <iostream>
#include <string>
using namespace std;
void searchByName(string name_product);
void view_categories();
void view_products(int);
void products_data();

string category_name;
//enum categories;
const int no_categories = 7;
const int no_products = 10;
string categories[no_categories] = { "Electronics", "VideoGames", "Groceries", "Office", "Beauty", "SportSupplies", "Home_Appliances & Furniture" };
string all_products[70];
struct product {
	string name;
	string id;
	string category;
	double price;
};
struct Category {
	product products[10];
};
Category Electronics, VideoGames, Groceries, Office, Beauty, SportSupplies, HomeFurniture; // to be global
void product_information(Category nameOFcategory, int noOfProduct);
int main() {
	products_data();
	view_categories();
	string product_namee;
	/*
	cout << "Search by the name of the product: ";
	cin >> product_namee;
	searchByName(product_namee);
	*/
	return 0;
}

void products_data() {
	Electronics.products[0].name = "MSI Katana GF66 Gaming Laptop";
	Electronics.products[0].id = "";
	Electronics.products[0].category = "Electronics - Laptop";
	Electronics.products[0].price = 1700;
	Electronics.products[1] = { "Acer Aspire 5","dasdas","Electronics - Laptop",550 };
	Electronics.products[2] = { "LG 55  Class 4K UHD 2160P","dasdas","Electronics - Laptop",360 };
	Electronics.products[3] = { "LG 65  Class 4K UHD ","dasdas","Electronics - Laptop",1300 };
	Electronics.products[4] = { "SAMSUNG 65 Class 4K Crystal","dasdas","Electronics - Laptop",478 };
	Electronics.products[5] = { "Apple Watch Series 8 GPS","dasdas","Electronics - Laptop",360 };
	Electronics.products[6] = { "SAMSUNG Galaxy Watch 4","dasdas","Electronics - Laptop",170 };
	Electronics.products[7] = { "Gateway Notebook 11.6","dasdas","Electronics - Laptop",192 };
	Electronics.products[8] = { "Straight Talk Apple iPhone 11, 64GB","dasdas","Electronics - Laptop",250 };
	Electronics.products[9] = { "Apple iPhone 12, 64GB","dasdas","Electronics - Laptop",500 };
	//cout << Electronics.products[1].name;

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

	Groceries.products[0] = { "Cheddar Smoked Sausage","","",3.96 };
	Groceries.products[1] = { "Freshness Guaranteed Boneless Chicken Thighs","","",11.38 };
	Groceries.products[2] = { "Freshness Guaranteed Chicken Breast Tenderloins","","",8.94 };
	Groceries.products[3] = { "HERSHEY'S and REESE'S, Chocolate Assortment Treats","","",7.48 };
	Groceries.products[4] = { "CADBURY, MINI EGGS Milk Chocolate with a Crisp Sugar Shell","","",3.84 };
	Groceries.products[5] = { "REESE'S, Assorted Milk Chocolate","","",10.98 };
	Groceries.products[6] = { "Sadler's Smokehouse Mesquite Smoked Sliced Beef Brisket","","",23.04 };
	Groceries.products[7] = { "Fresh Sweet Corn","","",0.60 };
	Groceries.products[8] = { "Marketside Organic Spinach","","",5.13 };
	Groceries.products[9] = { "Sweet Potatoes","","",4.24 };

	Office.products[0] = { "Vitesse Gaming Desk Computer Desk with Large Desk Mouse Pad","","", 110 };
	Office.products[1] = { "FlexiSpot Home Office Height Adjustable Standing Desk","","",250 };
	Office.products[2] = { "SHW Cyrus 38-Inch Desk with Shelves","","", 67 };
	Office.products[3] = { "Techvida Rose gold desk organizer","","",17 };
	Office.products[4] = { "Child Drawing Art Set / Kit with 210 Pieces","","", 20 };
	Office.products[5] = { "Pentel RSVP Ballpoint Pen","","",0.96 };
	Office.products[6] = { "Sheet High-Security Micro-Cut Paper Credit Card Shredder","","",41 };
	Office.products[7] = { "Bostitch Office Heavy Duty Stapler","","",11 };
	Office.products[8] = { "JIELISI 10in White Board","","", 12 };
	Office.products[9] = { "Casio FX-991EX ","","", 18 };

	Beauty.products[0] = { "L'Oreal Paris Glow Paradise Lip Balm","","", 8 };
	Beauty.products[1] = { "L'Oreal Paris Telescopic Lift Washable Makeup Mascara","","",12 };
	Beauty.products[2] = { "Frozen 2 Lip Gloss","","", 5 };
	Beauty.products[3] = { "Olay Regenerist Micro-Sculpting Cream Face Moisturizer","","",30 };
	Beauty.products[4] = { "CeraVe Foaming Face Wash","","",14 };
	Beauty.products[5] = { "Dyson Supersonic Hair Dryer","","",270 };
	Beauty.products[6] = { "Head & Shoulders 2 in 1 Dandruff Shampoo and Conditioner","","",12 };
	Beauty.products[7] = { "Lottie London Cheeky Kiss Lip & Cheek Stick","","",7 };
	Beauty.products[8] = { "Kenneth Cole Black Body Spray for Men","","",9 };
	Beauty.products[9] = { "Brickell Men's Purifying Charcoal Face Wash for Men","","",25 };

	SportSupplies.products[0] = { "Franklin Sports Youth Baseball Backpack","","", 19.83 };
	SportSupplies.products[1] = { "Rawlings R400 Baseball Youth Backpack","","",43 };
	SportSupplies.products[2] = { "Rawlings Storm Girls Softball Bag","","",28 };
	SportSupplies.products[3] = { "Easton Game Ready Baseball Backpack","","", 55 };
	SportSupplies.products[4] = { "Bounce Pro 7-Foot  Trampoline","","", 123 };
	SportSupplies.products[5] = { "Nike Phantom VSN 2 Elite","","", 272 };
	SportSupplies.products[6] = { "Nike Junior Mercurialx Proximo II","","",90 };
	SportSupplies.products[7] = { "Muck Kid's Rugged II Boot ","","",54 };
	SportSupplies.products[8] = { "Duo Tennis Racquet set","","",35 };
	SportSupplies.products[9] = { "Huffy 20 Boy Kids Bike","","", 78 };

	HomeFurniture.products[0] = { "Platform Bed Frame with 4 Storage Drawers","","",255 };
	HomeFurniture.products[1] = { "Allewie Brown Queen Size Bed Frame","","",189 };
	HomeFurniture.products[2] = { "Lily's Home Hanging Wall Clock","","", 30 };
	HomeFurniture.products[3] = { "Zimtown 5 Tier Heavy Duty Steel Shelving","","", 50 };
	HomeFurniture.products[4] = { "Hoover PowerDash Cleaner","","", 81 };
	HomeFurniture.products[5] = { "Shower Curtain Christmas ","","",30 };
	HomeFurniture.products[6] = { "Costway 1700W Portable Clothes Dryer","","",330 };
	HomeFurniture.products[7] = { "BestMassage Heavy Duty Shelf ","","",43 };
	HomeFurniture.products[8] = { "Sterilite Wide 4 Drawer","","",44.78 };
	HomeFurniture.products[9] = { "Beautiful 6 Quart Touchscreen Air Fryer","","",69 };

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

void view_categories() {
	for (int i = 0; i < no_categories; i++) {
		cout << i + 1 << ". " << categories[i] << endl;
	}
	int no;
	cout << "Choose a number: ";
	cin >> no;
	view_products(no);

}

// hna b2a lazm nstkhdm enum 3shan nrbot elrkm mn fok b esm cateogary 3shan n3rfh mn w nstkhd,h fy struct aw mmkn ydwy 3ady 
void view_products(int number) {
	system("CLS");
	int num;
	switch (number) {
	case 1:
		category_name = "Electronics";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << Electronics.products[i].name << endl;
		}
		cout << "Enter number of product :";
		cin >> num;
		product_information(Electronics, num - 1);
		break;
	case 2:
		category_name = "VideoGames";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << VideoGames.products[i].name << endl;
		}
		cout << "Enter number of product :";
		cin >> num;
		product_information(VideoGames, num - 1);
		break;
	case 3:
		category_name = "Groceries";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << Groceries.products[i].name << endl;
		}
		cout << "Enter number of product :";
		cin >> num;
		product_information(Groceries, num - 1);
		break;
	case 4:
		category_name = "Office";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << Office.products[i].name << endl;
		}
		cout << "Enter number of product :";
		cin >> num;
		product_information(Office, num - 1);
		break;
	case 5:
		category_name = "Beauty";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << Beauty.products[i].name << endl;
		}
		cout << "Enter number of product :";
		cin >> num;
		product_information(Beauty, num - 1);
		break;
	case 6:
		category_name = "SportSupplies";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << SportSupplies.products[i].name << endl;
		}
		cout << "Enter number of product :";
		cin >> num;
		product_information(SportSupplies, num - 1);
		break;
	case 7:
		category_name = "HomeFurniture";
		for (int i = 0; i < no_products; i++) {
			cout << i + 1 << ". " << HomeFurniture.products[i].name << endl;
		}
		cout << "Enter number of product :";
		cin >> num;
		product_information(HomeFurniture, num - 1);
		break;
	}
	char do_buy;
	cout << "Do you want to buy this product?y/n: ";
	cin >> do_buy;
	if (do_buy == 'y') {

	}
	else {
		system("CLS");
		view_categories();
	}


}




void searchByName(string name_product) {
	bool product_found = false;
	int product_no;
	int index_no;
	for (int i = 0; i < 70; i++) {
		if (all_products[i] == name_product) {
			product_found = true;
			product_no = i;
			break;
		}
		else {
			product_found = false;
		}
	}

	if (product_found) {
		if (product_no >= 0 && product_no < 10) { //hoa bycheck elawl 3la kol wahda bltrteb lw lka wahda true bytl3 mn kolh
			index_no = product_no;
			cout << Electronics.products[product_no].name << endl;
			cout << Electronics.products[product_no].id << endl;
			cout << Electronics.products[product_no].category << endl;
			cout << Electronics.products[product_no].price << endl;
		}
		else if (product_no >= 10 && product_no < 20) {
			index_no = product_no - 10;
			cout << VideoGames.products[index_no].name << endl;
			cout << VideoGames.products[index_no].id << endl;
			cout << VideoGames.products[index_no].category << endl;
			cout << VideoGames.products[index_no].price << endl;
		}
		else if (product_no >= 20 && product_no < 30) {
			index_no = product_no - 20;
			cout << Groceries.products[index_no].name << endl;
			cout << Groceries.products[index_no].id << endl;
			cout << Groceries.products[index_no].category << endl;
			cout << Groceries.products[index_no].price << endl;
		}
		else if (product_no >= 30 && product_no < 40) {
			index_no = product_no - 30;
			cout << Office.products[index_no].name << endl;
			cout << Office.products[index_no].id << endl;
			cout << Office.products[index_no].category << endl;
			cout << Office.products[index_no].price << endl;
		}
		else if (product_no >= 40 && product_no < 50) {
			index_no = product_no - 40;
			cout << Beauty.products[index_no].name << endl;
			cout << Beauty.products[index_no].id << endl;
			cout << Beauty.products[index_no].category << endl;
			cout << Beauty.products[index_no].price << endl;
		}
		else if (product_no >= 50 && product_no < 60) {
			index_no = product_no - 50;
			cout << SportSupplies.products[index_no].name << endl;
			cout << SportSupplies.products[index_no].id << endl;
			cout << SportSupplies.products[index_no].category << endl;
			cout << SportSupplies.products[index_no].price << endl;
		}
		else if (product_no >= 60 && product_no < 70) {
			index_no = product_no - 60;
			cout << HomeFurniture.products[index_no].name << endl;
			cout << HomeFurniture.products[index_no].id << endl;
			cout << HomeFurniture.products[index_no].category << endl;
			cout << HomeFurniture.products[index_no].price << endl;
		}



		char buy;
		cout << "Do you wanna buy it? y/n: ";
		cin >> buy;
		// lw yes b if cond khaly function trg3 index_no l total price fa mn khlalh n3rf ngeb kol elbyanat
	}
	else {
		cout << "Sorry we couldnt find this product...!";
	}

}

void product_information(Category nameOFcategory, int noOfProduct) {
	system("CLS");
	cout << "Name: " << nameOFcategory.products[noOfProduct].name << endl;
	cout << "ID: " << nameOFcategory.products[noOfProduct].id << endl;
	cout << "Category: " << nameOFcategory.products[noOfProduct].category << endl;
	cout << "Price: " << nameOFcategory.products[noOfProduct].price << "$" << endl;
	


}
