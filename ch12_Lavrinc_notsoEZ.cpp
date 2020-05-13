/*	Samantha Lavrinc
	03/12/2020 ~ CIT 245-701B
	This program reads and writes to a file
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class StreamAccess {
public:
	StreamAccess();	 //creates default filename & does not fill it.
	StreamAccess(string userInput);	 //creates default filename & fills file with user defined string.
	StreamAccess(string userInput, string fileName); //uses predefined filename & fills file with user defined string.

	void createFile(string fileName);
	void alterFile();
	void closeFile();
	void printFile();
	
private:
	fstream streamfile;
	string advice;
	string fileName = "demo.txt";
	string advicefile = ".txt";
	int x = 1;
	char tmp;
};

StreamAccess::StreamAccess() {
	createFile(fileName);
}

StreamAccess::StreamAccess(string userInput) {
	createFile(fileName);
	streamfile << userInput << '\n';
	streamfile.flush();
}

StreamAccess::StreamAccess(string userInput, string fileName) {
	fileName.append(advicefile);
	createFile(fileName);
	streamfile << userInput << '\n';
	streamfile.flush();
}

void StreamAccess::createFile(string fileName){
	streamfile.open(fileName, ios::in | ios::out);
	if (streamfile.fail()) {
		cout << "No file found, Creating file instead..." << endl;
		streamfile.close();
		streamfile.open(fileName, ios::in | ios::out | ios::trunc);
	}
	else {
		cout << "File found!" << endl;
		streamfile.close();
		streamfile.open(fileName, ios::in | ios::out | ios::app);
		printFile();
	}
	streamfile.close();
}

void StreamAccess::printFile() {
	cout << "Old Advice: " << endl;

	while (getline(streamfile, advice)) {
		cout << advice << endl;
	}
}

void StreamAccess::alterFile() {
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
}

void StreamAccess::closeFile() {
	streamfile.close();
}

int main() {
	StreamAccess demo = StreamAccess();

	demo.alterFile();
	demo.closeFile();

	system("PAUSE");
	return 0;
}