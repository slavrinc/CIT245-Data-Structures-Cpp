/*  ----------
	Samantha Lavrinc
	CIT 245-701B
	2020-01-28
	This program applies the Babylonian Square root
	algorithm to a user specified input value.
	----------		*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	float input, r, guess, tmp_guess, answer;

	cout << "Enter a number and I will apply the Babylonian square root algorithm\n";
	cout << "until I am within .001 of the correct answer.\n";
	cin >> input;
	cout << "\nYou entered: " << input << endl;

	guess = input / 2;

	do {
		tmp_guess = guess;
		r = input / guess;
		guess = (guess + r) / 2;

		cout << "\nGuessing... " << guess;

	} while ((tmp_guess - guess) > (tmp_guess * .001));

	answer = guess * guess;

	cout << endl;
	cout << "\nThe Babylonian algorithm gives " << guess << endl;
	cout << "\nChecking: " << guess << " * " << guess << " = " << answer << endl;
	
	system("PAUSE");
	return 0;
}