#include <iostream>
#include <string>
using namespace std;
void searchByName(string name_product);
void view_categories();
void view_products(int);
void products_data();
//enum categories;
const int no_categories = 7;
const int no_products = 10;
string categories[no_categories] = {"Electronics", "VideoGames", "Groceries", "Office", "Beauty", "SportSupplies", "Home_Appliances & Furniture"};
string all_products[70];
struct product {
	string name;
	string id;
	string category;
	string price;
};
struct Category {
	product products[10];
};
Category Electronics, VideoGames, Groceries, Office, Beauty, SportSupplies ,HomeFurniture; // to be global

int main() {
	
	return 0;
}

void products_data() {
	Electronics.products[0].name = "MSI Katana GF66 Gaming Laptop";
	Electronics.products[0].id = "";
	Electronics.products[0].category = "Electronics - Laptop";
	Electronics.products[0].price = "1700$";
	Electronics.products[1] = { "Acer Aspire 5","dasdas","Electronics - Laptop","550$" };
	Electronics.products[2] = { "LG 55  Class 4K UHD 2160P","dasdas","Electronics - Laptop","360$" };
	Electronics.products[3] = { "LG 65  Class 4K UHD ","dasdas","Electronics - Laptop","1300$" };
	Electronics.products[4] = { "SAMSUNG 65 Class 4K Crystal","dasdas","Electronics - Laptop","478$" };
	Electronics.products[5] = { "Apple Watch Series 8 GPS","dasdas","Electronics - Laptop","360$" };
	Electronics.products[6] = { "SAMSUNG Galaxy Watch 4","dasdas","Electronics - Laptop","170$" };
	Electronics.products[7] = { "Gateway Notebook 11.6","dasdas","Electronics - Laptop","192$" };
	Electronics.products[8] = { "Straight Talk Apple iPhone 11, 64GB","dasdas","Electronics - Laptop","250$" };
	Electronics.products[9] = { "Apple iPhone 12, 64GB","dasdas","Electronics - Laptop","500$" };
	//cout << Electronics.products[1].name;

	VideoGames.products[0] = { "Red Dead Redemption 2","","VideoGames - PlayStation 4","20$" };
	VideoGames.products[1] = { "FIFA 23","","VideoGames - PlayStation 4","40$" };
	VideoGames.products[2] = { "Grand Theft Auto V","","VideoGames - PlayStation 5","20$" };
	VideoGames.products[3] = { "Pro Evolution Soccer (PES)","","VideoGames - PlayStation 4","40$" };
	VideoGames.products[4] = { "Call of Duty: Modern Warfare II","","VideoGames - PlayStation 5","70$" };
	VideoGames.products[5] = { "Marvel’s Spider-Man: Miles Morales Ultimate Launch Edition","","VideoGames - PlayStation 5","70$" };
	VideoGames.products[6] = { "Crysis Remastered Trilogy","","VideoGames - PlayStation 4","35$" };
	VideoGames.products[7] = { "Battlefield V","","VideoGames - PlayStation 4","20$" };
	VideoGames.products[8] = { "Resident Evil 4","","VideoGames - PlayStation 4","60$" };
	VideoGames.products[9] = { "Hogwarts Legacy Deluxe Edition","","VideoGames - PlayStation 4","70$" };

	Groceries.products[0] = { "","","","" };
	Groceries.products[1] = { "","","","" };
	Groceries.products[2] = { "","","","" };
	Groceries.products[3] = { "","","","" };
	Groceries.products[4] = { "","","","" };
	Groceries.products[5] = { "","","","" };
	Groceries.products[6] = { "","","","" };
	Groceries.products[7] = { "","","","" };
	Groceries.products[8] = { "","","","" };
	Groceries.products[9] = { "","","","" };
	
	Office.products[0] = { "","","","" };
	Office.products[1] = { "","","","" };
	Office.products[2] = { "","","","" };
	Office.products[3] = { "","","","" };
	Office.products[4] = { "","","","" };
	Office.products[5] = { "","","","" };
	Office.products[6] = { "","","","" };
	Office.products[7] = { "","","","" };
	Office.products[8] = { "","","","" };
	Office.products[9] = { "Casio FX-991EX ","","","" };

	Beauty.products[0] = { "","","","" };
	Beauty.products[1] = { "","","","" };
	Beauty.products[2] = { "","","","" };
	Beauty.products[3] = { "","","","" };
	Beauty.products[4] = { "","","","" };
	Beauty.products[5] = { "","","","" };
	Beauty.products[6] = { "","","","" };
	Beauty.products[7] = { "","","","" };
	Beauty.products[8] = { "","","","" };
	Beauty.products[9] = { "","","","" };

	SportSupplies.products[0] = { "","","","" };
	SportSupplies.products[1] = { "","","","" };
	SportSupplies.products[2] = { "","","","" };
	SportSupplies.products[3] = { "","","","" };
	SportSupplies.products[4] = { "","","","" };
	SportSupplies.products[5] = { "","","","" };
	SportSupplies.products[6] = { "","","","" };
	SportSupplies.products[7] = { "","","","" };
	SportSupplies.products[8] = { "","","","" };
	SportSupplies.products[9] = { "","","","" };

	HomeFurniture.products[0] = { "","","","" };
	HomeFurniture.products[1] = { "","","","" };
	HomeFurniture.products[2] = { "","","","" };
	HomeFurniture.products[3] = { "","","","" };
	HomeFurniture.products[4] = { "","","","" };
	HomeFurniture.products[5] = { "","","","" };
	HomeFurniture.products[6] = { "","","","" };
	HomeFurniture.products[7] = { "","","","" };
	HomeFurniture.products[8] = { "","","","" };
	HomeFurniture.products[9] = { "","","","" };

	for (int i = 0; i < 10; i++) {
		all_products[i] = Electronics.products[i].name;
	}
	for (int a = 10 , b = 0; a < 20; a++ , b++) {
		all_products[a] = VideoGames.products[b].name;
	}
	for (int c = 20 , d = 0; c < 30; c++ , d++) {
		all_products[c] = Groceries.products[d].name;
	}
	for (int e = 30 , f = 0; e < 40; e++ , f++) {
		all_products[e] = Office.products[f].name;
	}
	for (int g = 40 ,h = 0; g < 50; g++ , h++) {
		all_products[g] = Beauty.products[h].name;
	}
	for (int j = 50 , k = 0; j < 60; j++ , k++) {
		all_products[j] = SportSupplies.products[k].name;
	}
	for (int l = 60 , m=0; l < 70; l++ , m++) {
		all_products[l] = HomeFurniture.products[m].name;
	}

}

void view_categories() {
	for (int i = 0; i < no_categories; i++) {
		cout << i << ". " << categories[i] << endl;
	}
	int no;
	cout << "Choose a number: ";
	cin >> no;
	view_products(no);
}

// hna b2a lazm nstkhdm enum 3shan nrbot elrkm mn fok b esm cateogary 3shan n3rfh mn w nstkhd,h fy struct aw mmkn ydwy 3ady 
void view_products(int number) {
	switch (number) {
	case 1:
		for (int i = 0; i < no_products; i++) {
			cout << i << ". " << Electronics.products[i].name << endl;
		}

		break;
	case 2:
		for (int i = 0; i < no_products; i++) {
			cout << i << ". " << VideoGames.products[i].name << endl;
		}
		break;
	case 3:
		for (int i = 0; i < no_products; i++) {
			cout << i << ". " << Groceries.products[i].name << endl;
		}
		break;
	case 4:
		for (int i = 0; i < no_products; i++) {
			cout << i << ". " << Office.products[i].name << endl;
		}
		break;
	case 5:
		for (int i = 0; i < no_products; i++) {
			cout << i << ". " << Beauty.products[i].name << endl;
		}
		break;
	case 6:
		for (int i = 0; i < no_products; i++) {
			cout << i << ". " << SportSupplies.products[i].name << endl;
		}
		break;
	case 7:
		for (int i = 0; i < no_products; i++) {
			cout << i << ". " << HomeFurniture.products[i].name << endl;
		}
		break;
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
