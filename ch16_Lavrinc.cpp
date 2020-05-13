/*	Samantha Lavrinc
	CIT-245-701B
	04-01-2020
	This program tests the generic binary search.
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <array>

using std::cout;
using std::endl;
using std::string;

template <class T>
void sort(T a[], int numUsed);

template <class T>
void swapVals(T& var1, T& var2);

template <class T>
int indexOfSmallest(const T a[], int startIndex, int numUsed);

template <class T>
void printRes(const T a[], int startIndex, int numUsed);

template <class T>
int searchArray(T* arr, T key, int sizeOfArr);

template <class T>
void toString(T key, int result);

#include "templateDEMO.cpp"

int main() {
	cout << "This program demonstrates a generic binary search.\n" << endl;

	int testSize(8), arrLen1(11), arrLen2(4);
	int binInt[11] = {55, 0, 1, 32, 21, 1, 13, 3, 2, 6, 5};

	cout << "Unsorted int array: " << endl;
	printRes(binInt, 0, arrLen1);

	sort(binInt, arrLen1);
	cout << "\nSorted int array: " << endl;
	printRes(binInt, 0, arrLen1);

	cout << endl;
	for (int j = -1; j < testSize; j++) {
		int result = searchArray(binInt, j, testSize);
		toString(j, result);
	}

	string binBody[4] = { "knees", "shoulders", "toes", "head" };
	cout << "\nUnsorted string array: " << endl;
	printRes(binBody, 0, arrLen2);

	sort(binBody, arrLen2);
	cout << "\nSorted string array: " << endl;
	printRes(binBody, 0, arrLen2);

	cout << endl;

	string key = "elbow";
	int result = searchArray(binBody, key, 4);
	toString(key, result);

	key = "shoulders";
	result = searchArray(binBody, key, 4);
	toString(key, result);

	cout << endl;

	system("PAUSE");
	return 0;
}

