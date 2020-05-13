/*	Samantha Lavrinc
	CIT 245-701B | 03-18-2020 
	This program implements the Towers of Hanoi puzzle. */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

void solvePuzzle(int d, int st, int fin, int xtra, int &counter);

int main() {
	int test, counter(0), start(1), dest(2), extra(3);

	cout << "Enter the total number of disks: ";
	cin >> test;

	solvePuzzle(test, start, dest, extra, counter);
	cout << "2 to the " << test << " power = " << pow(2, test) << endl;
	cout << "Number of moves: " << counter << endl;

	system("PAUSE");
	return 0;
}

void solvePuzzle(int disk, int st, int fin, int xtra, int &counter) {
	counter++;
	if (disk == 1) {
		cout << "Disk " << disk << " moved from " << st << " to " << fin << "." << endl;
	}
	else {
		solvePuzzle(disk - 1, st, xtra, fin, counter);
		cout << "Disk " << disk << " moved from " << st << " to " << fin << "." << endl;
		solvePuzzle(disk - 1, xtra, fin, st, counter);
	}
}