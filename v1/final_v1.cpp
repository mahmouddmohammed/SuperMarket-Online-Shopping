#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void update_data();
void login_register_menu();
void login_();
void register_();
bool update_information(int index_no);


const int no_customers = 100;
int no_actualusers = 2; //one- Based
int user_index;

struct users_information {
	int id;
	string name;
	string email;
	string phone_number;
	string password;
	string location;
};
users_information customer[no_customers]; //global

int main() {
	update_data();
	login_register_menu();


	return 0;
}

void login_register_menu() {
	int no;
	cout << "*****************************************************" << endl;
	cout << "\t   SuperMarket Online Shopping \t \t" << endl;
	cout << "\t \t • Main Menu • \t \t" << endl;
	cout << "*****************************************************" << endl;
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
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
	default:
		cout << "Invalid Input" << endl;
		system("pause");
		login_register_menu();
		break;
	}
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
		cout << "if you dont register , you have to register first";
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
		login_();
		break;
	default:
		cout << "Invalid Input" << endl;
		update_information(user_index);
		break;

	}
}
