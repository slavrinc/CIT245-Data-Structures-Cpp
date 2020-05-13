/*  Samantha Lavrinc
	02-10-2020 ~ CIT 245-701B
	This program creates an array and fills and sorts it 
	with random values from 1-10, then tabulates the results */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int randoGen();
void fillArr(int twentyArr[], int arrSize);
void printList(int twentyArr[], int arrSize);
void countArr(int twentyArr[],int tenArr[], int arrSize, int countSize);

int main() {
	srand(time(NULL));
	const int arrSize = 20;
	const int countSize = 10;
	int tryAgain;

	do {
		int twentyArr[arrSize];
		int tenArr[countSize] = { 0 };

		fillArr(twentyArr, arrSize);
		sort(twentyArr, twentyArr + arrSize);

		cout << "This program generates a sorted list and tabulates the results.\n";

		cout << "\nSorted List:\n";
		printList(twentyArr, arrSize);

		cout << "\n N: Count:" << endl;
		countArr(twentyArr, tenArr, arrSize, countSize);

		cout << "\nWould you like to try again? (1 = Yes, 0 = Exit): ";
		cin >> tryAgain;

	} while (tryAgain != 0);

	cout << "\nExiting program..."<< endl;
	cout << endl;

	system("PAUSE");
	return 0;
}

int randoGen() {
	return (rand() % 10) + 1;
}

void fillArr(int twentyArr[],int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		twentyArr[i] = randoGen();
	}
}

void countArr(int twentyArr[],int tenArr[],int arrSize, int countSize) {
	for (int i = 1; i <= countSize; i++ ) {
		for (int j = 0; j < arrSize; j++ ) {
			if (twentyArr[j] == i) {
				tenArr[i - 1] += 1;
			}
		}
	}

	for (int i = 1; i <= countSize; i++) {
		cout.width(2); cout << right << i << ":";
		cout.width(7); cout << right << tenArr[i - 1]<<endl;
	}
}

void printList(int arrayInput[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << right << "a[";
		cout.width(2); cout << right << i << "]: ";
		cout.width(2); cout << right << arrayInput[i] << endl;
	}
}

