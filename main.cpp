#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>
using namespace std;
struct user{
	string username;
	string password;
};
struct date{
	string day;
	string month;
	string year;
};
void signup();
void login();
void menu(user you);
void writediary(user you);
void readdiary(user you);
void deletediary(user you);
int main(){
	int choice;
	cout << "HALLO! WELCOME TO CipherLog! :)" << endl << endl;
	do{
		cout << "1. Login" << endl;
		cout << "2. SignUp" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch(choice){
			case 1:
				login();
				break;
			case 2:
				signup();
				break;
			case 3:
				cout << "Goodbye :)" << endl;
				break;
			default:
				cout << "Invalid Input" << endl << endl;	
		}
	}while(choice != 3);
	
	return 0;
}
void signup(){
	user make;
	string cpass;
	cout << "Creating Account...." << endl;
	bool usernameExists;
	do {
		usernameExists = false;
		cout << "Create a username: ";
		getline(cin, make.username);
		stringstream checkUserStream;
		for(int i = 0; i < make.username.length(); i++) {
			checkUserStream << (int)make.username[i] << " ";
		}
		string targetUser = checkUserStream.str() + "|";
		fstream file;
		file.open("accounts.txt", ios::in);
		if(file.is_open()){
			string fileLine;
			while(getline(file, fileLine)){
				if(fileLine.rfind(targetUser, 0) == 0){ 
					cout << "ERROR: Username already exists. Try a different one." << endl << endl;
					usernameExists = true; 
					break;
				}
			}
			file.close();
		}
	} while(usernameExists);
	
	do{
		cout << "Create a STRONG password: ";
		getline(cin, make.password);
		while(make.password.length() < 8){
			cout << "The password is too WEAK! It must be atleast 8 character" << endl;
			cout << "Try again: ";
			getline(cin, make.password);
		}
		cout << "Confirm your password: ";
		getline(cin, cpass);
		if (cpass != make.password){
		cout << "ERROR: Those password do not match! Try again." << endl;
		}
	}while (cpass != make.password);
	fstream file;
	file.open("accounts.txt", ios::app);
	if(file.is_open()){
		for(int i = 0; i < make.username.length(); i++) {
			file << (int)make.username[i] << " ";
		}
		file << "| ";
		for(int i = 0; i < make.password.length(); i++) {
            file << (int)make.password[i] << " ";
        }
		file << endl;
		file.close();
		cout << "Account Created Successfully!" << endl << endl;
	}
	else{
		cout << "ERROR: Can't open file" << endl << endl;
	}	
}
void login(){
	user you;
	cout << "Enter your Username: ";
	getline(cin, you.username);
	cout << "Enter your Password: ";
	getline(cin, you.password);
	stringstream userStream;
	for(int i = 0; i < you.username.length(); i++) {
		userStream << (int)you.username[i] << " ";
	}
	stringstream passStream;
	for(int i = 0; i < you.password.length(); i++) {
		passStream << (int)you.password[i] << " ";
	}
	string targetLine = userStream.str() + "| " + passStream.str();
	fstream file;
	file.open("accounts.txt", ios::in);
	bool found = false;
	if(file.is_open()){
		string fileLine;
		while(getline(file, fileLine)){
			if(fileLine == targetLine){
				found = true;
				break;
			}
		}
		file.close();
	}
	if(found){
		cout << endl << "Login Successful!" << endl << endl;
		menu(you);
	}
	else{
		cout << endl << "ERROR: Invalid username or password." << endl << endl;
	}
}
void writediary(user you){
	string fullentry;
	string outline;
	date entry;
	cout << endl << "Dating the Entry: " << endl;
	cout << "Enter day: ";
	cin >> entry.day;
	cout << "Enter month: ";
	cin >> entry.month;
	cout << "Enter year: ";
	cin >> entry.year;
	cin.ignore();
	cout << endl << "Enter what you want to write in your secret dairy: " << endl;
	getline(cin, outline);
	fullentry = "Date: [" + entry.day + "/" + entry.month + "/" + entry.year + "]\n" + outline + "\n\n";
	fstream file;
	file.open(you.username + ".txt", ios::app);
	if(file.is_open()){
		for(int i = 0; i < fullentry.length(); i++) {
			file << (int)fullentry[i] << " ";
		}
		file << endl;
		file.close();
		cout << "Saved in dairy successfully" << endl << endl;
	}
	else{
		cout << "ERROR: Can't open file" << endl << endl;
	}
}
void readdiary(user you){
	fstream file;
	file.open(you.username + ".txt", ios::in);
	if(file.is_open()){
		int asciiValue;
		cout << endl << "Diary Content: " << endl;
		while (file >> asciiValue) {
			cout << (char)asciiValue;
		}
		cout << endl << endl;
		file.close();
	}
	else{
		cout << "ERROR: Can't open file (it may not exist)" << endl << endl;
	}
}
void deletediary(user you) {
    string filename = you.username + ".txt";
	if (remove(filename.c_str()) == 0){
        cout << endl <<"Diary File Deleted Successfully!" << endl << endl;
    } 
    else {
        cout << endl << "ERROR: Can't delete file (it may not exist)" << endl << endl;
    }
}
void menu(user you){
	int choice;
	do{
		cout << "1. Write to the diary" << endl;
		cout << "2. Read the diary" << endl;
		cout << "3. Delete diary" << endl;
		cout << "4. Logout" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch(choice){
			case 1:
				writediary(you);
				break;
			case 2:
				readdiary(you);
				break;
			case 3:
				deletediary(you);
				break;
			case 4:
				cout << "Logged Out" << endl << endl;
				break;
			default:
				cout << "Invalid Input" << endl << endl;	
		}
	}while(choice != 4);	
}
