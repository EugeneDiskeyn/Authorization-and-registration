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
		logsFile << username << endl << password;
		logsFile.close();

		cout << "You have successfully been registrated";
		main();
	}
}