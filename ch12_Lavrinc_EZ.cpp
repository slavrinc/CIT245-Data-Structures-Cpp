/*	Samantha Lavrinc
	03/12/2020 ~ CIT 245-701B
	This program reads and writes to a file 
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	fstream streamfile;
	string advice,line;
	int x = 1;
	char tmp;

	streamfile.open("demo.txt", ios::in | ios::out);
	if (streamfile.fail()) {
		cout << "No file found, Creating file instead..." << endl;
		streamfile.close();
		streamfile.open("demo.txt", ios::in | ios::out | ios::trunc);
		streamfile.close();
	}
	else {
		cout << "demo File found." << endl;
		cout << "Old Advice: " << endl;

		while (getline(streamfile, line)) {
			cout << line << endl;
		}
		streamfile.close();
	}

	streamfile.open("demo.txt", ios::in | ios::out | ios::app);

	do {
		cout << "Enter your phrase for the next user: " << endl;

		getline(cin, advice);
		streamfile << advice << '\n';
		streamfile.flush();

		cout << "Would you like to add more? (1 = Yes ; 0 = No )" << endl;

		cin >> x;
		tmp = getchar();
		cout << endl;

	} while (x != 0);

	streamfile.close();

	system("PAUSE");
	return 0;
}

