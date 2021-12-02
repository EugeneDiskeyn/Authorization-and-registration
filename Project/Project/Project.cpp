#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
	int choice = 0;
	cout << "1) Login \n2) Registration" << endl;
	cin >> choice;
	if (choice == 2) {
		string username = "", password = "";
		cout << "Please, enter a username(It can't have spaces):" << endl;
		cin >> username;
		cout << endl << "Please, enter a password (It can't have spaces, also try to use signs, letters and numbers to make your password safe enough):" << endl;
		cin >> password;

		ofstream logsFile;
		logsFile.open(username + ".txt");
		logsFile << password;
		logsFile.close();

		cout << "You have successfully been registrated" << endl;
		main();
	}
	if (choice == 1) {
		ifstream Fin;
		string username1 = "", password1 = "";
		cout << "Please, enter your username:" << endl;
		cin >> username1;
		cout << endl << "Please, enter your password:" << endl;
		cin >> password1;
		Fin.open(username1 + ".txt");
		if (!Fin.is_open()) {
			cout << endl << "There are no any accounts with such name, come back to the menu?" << endl << "1) Yes" << endl << "2) No" << endl;
			int yes = 0;
			cin >> yes;
			if (yes == 1) {
				Fin.close();
				main();
			}
			else {
				return 0;
			}
		}
		else {
			string str = "";
			while (!Fin.eof()) {
				str = "";
				Fin >> str;
				if (str != password1) {
					cout << endl << "The password is wrong. We will send you to the menu" << endl;
					Fin.close();
					main();
				}
				else {
					cout << endl << "You have successfully entered"  << endl;
					return 0;
				}
			}
		}
	}
}