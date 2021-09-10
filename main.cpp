#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string forgetPassword() {
	string username, checkUsername, checkPassword;

	cout << "Enter Your User UserName To Change Password: ";
	cin >> username;

	ifstream read("txt\\" + username + ".txt");
	getline(read, checkUsername);
	getline(read, checkPassword);

	if (username == checkUsername) {
		checkPassword.erase();
		ofstream file;
		file.open("txt\\" + username + ".txt");
		file << checkUsername << endl;
		file.close();
	}
	return checkUsername;
}

bool validPassword(char pass[]) {
	bool upperCase = false,
		lowerCase = false,
		digit = false;

	if (strlen(pass) < 6) {
		cout << "The password must be 6";
		return false;
	}

	for (int i = 0; i <= 32; i++) {
		if (pass[i] >= 65 && pass[i] <= 90)
			upperCase = true;
		else if (pass[i] >= 0 && pass[i] <= 9)
			digit =  true;
	}

	if (!upperCase || !digit) {
		cout << "The password must have:\n";
		cout << "\tat least one uppercase character,\n";
		cout << "\tat least one numeric digit\n";
		return false;
	}
	
	return true;
}

bool loggedIn()
{
	string username, password, checkusername, checkpassword;
	system("cls");

	cout << "Please Enter the Following Data to LoggedIn\n\n";
	cout << "UserName: ";
	cin >> username;
	cout << endl;
	cout << "PassWord: ";
	cin >> password;

	ifstream read("txt\\" + username + ".txt");
	getline(read, checkusername);
	getline(read, checkpassword);

	if (checkusername == username && checkpassword == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main() {
	int choice;
	const int size = 32;
	string username;
	char password[size];
	char password2[size];

	cout << "Enter 1 To Register: " << endl;
	cout << "Enter 2 To Login: " << endl;
	cout << "Enter 3 To Forget: \n" << endl;
	cout << "Your Choice: ";
	cin >> choice;

	if (choice == 1) {
		cout << "\nEnter Username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;
		
		if (!validPassword(password))
			cout << "The password is not valid.\n";
		else{
			ofstream file;
			file.open("txt\\"+ username+ ".txt");
			file << username << endl;
			file << password << endl;
			file.close();

			system("cls");
			cout << "*******Successfully Registered*******\n";
			main();
		}
	}
	else if (choice == 2) {
		bool status;
		status = loggedIn();

		if (!status) {
			system("cls");
			cout << "*******Invalid Id Try Again*******\n\n" << endl;
			main();
		}
		else {
			system("cls");
			cout << "*******Successfully LoggedIn********" << endl;
			cin.get();
			cin.get();
		}
	}

	else if (choice == 3) {
		bool flag = true;
		string user = forgetPassword();
		cout << "Create a new Password: ";
		cin >> password;
		cout << "Renter a new Password: ";
		cin >> password2;

		for(int i = 0; i<=size; i++){
			if (password[i] != password2[i]) {
				flag = false;
			}
		}
		cout << "\nPassword 1 didnt match with Password 2" << endl;


		if (!validPassword(password))
			cout << "The password is not valid.\n";
		else if(flag) {
			ofstream file;
			file.open("txt\\" + user + ".txt");
			file << user << endl;
			file << password << endl;
			file.close();

			system("cls");
			cout << "*******Password Change Successfully*******\n\n";
			main();
		}

	}

	return 0;
}