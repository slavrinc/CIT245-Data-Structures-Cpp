/*  Samantha Lavrinc
	2020-02-04 
	CIT 245-701B
	This program rolls two dice based on user input and calculates
	the odds of rolling a certain sum. */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

#define FIXED_FLOAT(x) std::fixed << std::setprecision(4) << (x)

using namespace std;

void roll(int trials); 
int randomGen(); 
double oddsCheck(int total);
double percErr(int rolled, double odds);

int main() {
	int cont, trials;
	srand(time(NULL));

	cout << "This program rolls two dice and tabulates the results." << endl;
	do {
		cout << "Please enter the number of desired rolls: ";
		cin >> trials;
		roll(trials);
		cout << "Would you like to continue? (1 = Yes, 0 = Exit)" << endl;
		cin >> cont;
	} while (cont != 0);

	system("PAUSE");
	return 0;
}
 
void roll(int trials) {
	int dice1, dice2, total, rollArr[13] = { 0 };
	
	for (int i = trials; i > 0; i--) {
		dice1 = randomGen();
		dice2 = randomGen();
		total = dice1 + dice2;
		rollArr[total]++;	
	}

	cout.width(5); cout << right << "Sum";
	cout.width(9); cout << right << "#Rolled";
	cout.width(10); cout << right << "Odds";
	cout.width(10); cout << right << "%Error" << endl;

	for (int i = 2; i <= 12; i++) {
		double odds = oddsCheck(i) * trials;
		int rolled = rollArr[i];
		double errPerc = percErr(rolled, odds);
		
		std::ios cout_state(nullptr);
		cout_state.copyfmt(std::cout);

		cout.width(4); cout << right << i << ":";
		cout.width(9); cout << right << rolled;
		cout.width(10); cout << right  << odds ;
		cout.width(10); cout << right  << FIXED_FLOAT(errPerc) <<endl;

		std::cout.copyfmt(cout_state);
	}
}

int randomGen() {
	return (rand() % 6) + 1;
}

double oddsCheck(int total){
	if (total <= 7) {
		return double(total - 1) / 36;
	}
	else {
		return double(12 - (total - 1)) / 36;
	}
}

double percErr(int rolled, double odds) {
	return abs((odds - rolled) * 100 / odds);
}


