/*  Samantha Lavrinc
	02-26-2020 ~ CIT 245-701B
	This program reversed a string using the STL stack.
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>

using namespace std;

class StackIt {
public:
	StackIt();
	StackIt(char* s);
	void reverseIt();
	

private:
	char* stdef;
	stack <char> stackUSER;
};

int main() {
	int go = 1;
	char tmp;
	char* s = (char*)malloc(80);

	cout << "This program reverses a string using the STL stack" << endl;

	while (go == 1) {
		cout << "Enter your string of less than 80 characters followed by an ENTER" << endl;
	
		cin.getline(s, 81, '\n'); // user input as a string of 80 char + 1 ENTER key

		StackIt stacked(s);
		stacked.reverseIt();

		cout << "\nEnter another? 1 = continue. Anything else to stop" << endl;

		cin >> go;			// 1 char + ENTER
		tmp = getchar();	// remove ENTER
		cout << endl;
	}

	free(s);

	//StackIt test(s);  *tested to ensure memory is freed.
	//test.reverseIt(); *prior to null pointer execution.

	s = NULL;

	system("PAUSE");
	return 0;
}

StackIt::StackIt():stdef(NULL) {
	// body intentionally left empty. 
	// uses different pointer because none was assigned.
}

StackIt:: StackIt(char* s) {
	for (int i = 0;  s[i] != '\0'; i++) {
		stackUSER.push(s[i]);		// pushes char*[i] values onto stack one by one
	}
}

void StackIt::reverseIt() {
	while (!stackUSER.empty()) {	// while stack is not empty
		cout << stackUSER.top();	// output top value
		stackUSER.pop();			// pop the top value off
	}
}
