/*	Samantha Lavrinc
	CIT 245-701B
	04/22/2020
	This program creates a map and stores social security
	numbers by name. */

#include <iostream>
#include <cstdlib>	
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, int> m;

	m["Paul Brown"] = 123456790;
	m["Mary Smith"] = 123456791;
	m["John Smith"] = 123456789;
	m["Lisa Brown"] = 123456792;

	cout << "Iterating through list..." << endl;
	map<string, int>::const_iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->second << ": " << iter->first << endl;
	}

	cout << endl;

	string JB = "John Brown";
	string PB = "Paul Brown";

	cout << "Searching for " << JB << endl;
	if (m.find(JB) != m.end()) {
		cout << JB << "was found!" << endl;
		cout << "SSN: " << m[PB] << endl;
	}
	if (m.find(JB) == m.end()) {
		cout << JB << " was not found." << endl;
	}

	cout << endl;

	cout << "Searching for " << PB << endl;
	if (m.find(PB) != m.end()) {
		cout << PB << " was found!" << endl;
		cout << "SSN: " << m[PB] << endl;
	}
	if (m.find(PB) == m.end()) {
		cout << PB << " was not found." << endl;
	}

	cout << endl;
	system("PAUSE");
	return 0;
}

