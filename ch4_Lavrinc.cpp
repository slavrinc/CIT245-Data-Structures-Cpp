/*  Samantha Lavrinc
	2020-02-06
	CIT 245-701B
	This program reduces a fraction to its lowest terms. */

#include <cstdlib>
#include <iostream>

using namespace std;

void prompt(int& num, int& denom);
// precondition: num and denom value via reference.
// - changes 'global' num and denom value based on user input.

void reduce(int& num, int& denom);
// precondition: num and denom value via reference.
// - divides 'global' num and denom values by the GCD.

int gcd(int num, int denom);
// precondition: num and denom.
// returns the GCD.

int main() {
	int num, denom, contprompt;
	cout << "----------------------------------------------------";
	cout << "\nThis program reduces a fraction to its lowest terms.";

	do {
		prompt(num, denom);
		if (denom != 0) { //needs divide by 0 exception. if/else used as placeholder.
			reduce(num, denom);
			cout << "This fraction can be reduced to: " << num << "/" << denom << endl;
		}
		else { 
			cout << "Input error: Cannot divide by 0." << endl;
		}
		cout << "\nWould you like to try again? (1 = YES, 0 = EXIT): ";
		cin >> contprompt;

	} while (contprompt != 0);

	cout << "\n----------------------------------------------------\n";
	cout << "\nExiting..." << endl;
	cout << endl;
	system("PAUSE");
	return 0;
}

int gcd(int num, int denom) {
	
	//recursive method calls on itself as long as numerator != 0.
	if (num == 0) {
		return denom;
	}
	return gcd(denom % num, num);

	/* Method based on provided psudocode:
	while (denom != 0) {
		int tmp = denom;
		denom = num % denom;
		num = tmp;
	}
	return num;*/
}

void reduce(int& num, int& denom) {
	int g = gcd(num, denom);
	num = num / g;
	denom = denom / g;

	cout << "\nThe greatest common factor is: " << g << endl;
}

void prompt(int& num, int& denom) {
	double num_tmp,denom_tmp; //allows type conversion buffer.

	cout << "\n----------------------------------------------------\n";
	cout << "\nEnter the numerator: ";
	cin >> num_tmp;
	cout << "Enter the denominator: ";
	cin >> denom_tmp;

	num = round(num_tmp);
	denom = round(denom_tmp);
}
