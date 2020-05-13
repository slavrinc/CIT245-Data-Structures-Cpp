/*  Samantha Lavrinc
	02-18-2020 ~ CIT 245-701B
	This program creates a money class and demonstrates
	overloaded friend functions.*/

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class Money {

public:
	Money();
	Money(double amount);
	Money(int dollars, int cents);
	Money(int dollars);
	double getAmount() const;
	int getDollars() const;
	int getCents() const;
	//void input();
	//void output() const;
	friend const Money operator + (const Money& amount1,
		const Money& amount2);
	friend const Money operator - (const Money& amount1,
		const Money& amount2);
	friend bool operator ==(const Money& amount1, const Money& amount2);
	friend bool operator >(const Money& amount1, const Money& amount2);
	friend bool operator <(const Money& amount1, const Money& amount2);
	friend const Money operator -(const Money& amount);
	friend const Money operator %(const Money& amount1, const Money& perc);
	friend ostream& operator << (ostream& outputStream, const Money& amount);
	friend istream& operator >> (istream& inputStream, Money& amount);

private:
	int dollars; 
	int cents; 
	int dollarsPart(double amount) const;
	int centsPart(double amount) const;
	int round(double number) const;
};

int main() {
	int percInt(10), tryAgain(1);
	Money yourAmount, myAmount(10, 9), percMoney(percInt);

	cout << "This program takes a user defined amount of money and\n";
	cout << "compares it to a pre-defined amount of money.\n";

	do {
		cout << "\n--------------------------------\n";
		cout << "Enter an amount of money: ";
		cin >> yourAmount;
		cout << "Your amount is " << yourAmount << endl;
		cout << "My amount is " << myAmount << endl;

		if (yourAmount == myAmount) {
			cout << "We have the same amount!\n";
		}
		else {
			cout << "One of us is richer...";
			if (yourAmount > myAmount) {
				cout << " and it's you!" << endl;
			}
			else {
				cout << " and it's me!" << endl;
			}
		}

		cout << endl;
		cout << percInt << "% of your money is " << (yourAmount % percInt) << endl;

		Money ourAmount = yourAmount + myAmount;
		cout << yourAmount << " + " << myAmount
			<< " equals " << ourAmount << endl;
		
		Money diffAmount = yourAmount - myAmount;
		cout << yourAmount << " - " << myAmount
			<< " equals " << diffAmount << endl;
		
		cout << "\nWould you like to try again? \n(1 = Yes / 0 = No): ";
		cin >> tryAgain;

	} while (tryAgain != 0);

	cout << "\nExiting...\n";
	system("PAUSE");
	return 0;
}

const Money operator +(const Money& amount1, const Money& amount2) {
	int allCents1 = amount1.cents + amount1.dollars * 100;
	int allCents2 = amount2.cents + amount2.dollars * 100;
	int sumAllCents = allCents1 + allCents2;
	int absAllCents = abs(sumAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;

	if (sumAllCents < 0) {
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return Money(finalDollars, finalCents);
}

const Money operator - (const Money& amount1, const Money& amount2) {
	int allCents1 = amount1.cents + amount1.dollars * 100;
	int allCents2 = amount2.cents + amount2.dollars * 100;
	int diffAllCents = allCents1 - allCents2;
	int absAllCents = abs(diffAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;

	if (diffAllCents < 0) {
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return Money(finalDollars, finalCents);
}

const Money operator %(const Money& amount1, const Money& perc) {
	int allCents1 = amount1.cents + amount1.dollars * 100;
	double allCents2 = double(perc.cents + perc.dollars) / 100;
	int percAllCents = allCents1 * allCents2;
	int absAllCents = abs(percAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;

	if (percAllCents < 0) {
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return Money(finalDollars, finalCents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
	return ((amount1.dollars == amount2.dollars) 
		&& (amount1.cents == amount2.cents));
}

bool operator >(const Money& amount1, const Money& amount2) {
	return ((amount1.dollars > amount2.dollars)
		&& (amount1.cents > amount2.cents));
}

bool operator <(const Money& amount1, const Money& amount2) {
	return ((amount1.dollars < amount2.dollars)
		&& (amount1.cents < amount2.cents));
}

const Money operator -(const Money& amount) {
	return Money(-amount.dollars, -amount.cents);
}


Money::Money() : dollars(0), cents(0) {
	//body intentionally empty
}

Money::Money(double amount)
	: dollars(dollarsPart(amount)), cents(centsPart(amount)) {
	//body intentionally empty
}

Money::Money(int theDollars)
	: dollars(theDollars), cents(0) {
	//body intentionally empty
}

Money::Money(int theDollars, int theCents) {
	if ((theDollars < 0 && theCents > 0) ||
		(theDollars > 0 && theCents < 0)) {
		cout << "Inconsistent money data.\n";
		exit(1);
	}
	dollars = theDollars;
	cents = theCents;
}

double Money::getAmount() const {
	return (dollars + cents * 0.01);
}

int Money::getDollars() const {
	return dollars;
}

int Money::getCents() const {
	return cents;
}

/* void Money::output() const {
	int absDollars = abs(dollars);
	int absCents = abs(cents);

	if (dollars < 0 || cents < 0) {
		cout << "$-";
		cout << absDollars;
	}
	else {
		cout << "$"; 
		cout << absDollars;
	}

	if (absCents >= 10) {
		cout << '.' << absCents;
	}
	else {
		cout << '.' << '0' << absCents;
	}
}

void Money::input() {
	char dollarSign;
	cin >> dollarSign;
	if (dollarSign != '$') {
		cout << "No dollar sign in Money input.\n";
		exit(1);
	}

	double amountAsDouble;
	cin >> amountAsDouble;
	dollars = dollarsPart(amountAsDouble);
	cents = centsPart(amountAsDouble);
} */

int Money::dollarsPart(double amount) const {
	return static_cast <int> (amount);
}

int Money::centsPart(double amount) const {
	double doubleCents = amount * 100;
	int intCents = (round(fabs(doubleCents))) % 100;
	if (amount < 0) {
		intCents = -intCents;
	}
	return intCents;
}

int Money::round(double number) const {
	return static_cast<int>(floor(number + 0.5));
}

ostream& operator << (ostream& outputStream, const Money& amount) {
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);
	if (amount.dollars < 0 || amount.cents < 0) {
		outputStream << "$-";
		outputStream << absDollars; //sneaky!!
	}
	else {
		outputStream << '$';
		outputStream << absDollars;
	}

	if (absCents >= 10) {
		outputStream << '.' << absCents;
	}
	else {
		outputStream << '.' << '0' << absCents;
	}
	return outputStream;
}

istream& operator >>(istream& inputStream, Money& amount) {
	char dollarSign;
	inputStream >> dollarSign; 
	if (dollarSign != '$') {
		cout << "No dollar sign in Money input. \n";
		exit(1);
	}

	double amountAsDouble;
	inputStream >> amountAsDouble;
	amount.dollars = amount.dollarsPart(amountAsDouble);
	amount.cents = amount.centsPart(amountAsDouble);

	return inputStream;
}
