/*	Samantha Lavrinc
	CIT-245-701B
	04-01-2020
	This file defines the search functions.
*/

#include <iostream>

using std::cout;
using std::endl;

template<class T>
void sort(T a[], int numUsed) {
	int indexOfNextSmallest;
	for (int index = 0; index < numUsed - 1; index++) {
		indexOfNextSmallest = 
			indexOfSmallest(a, index, numUsed);
		swapVals(a[index], a[indexOfNextSmallest]);
	}
}

template<class T>
void swapVals(T& var1, T& var2) {
	T temp;

	temp = var1;
	var1 = var2;
	var2 = temp;
}

template<class T> 
int indexOfSmallest(const T a[], int startIndex, int numUsed) {
	T min = a[startIndex];
	int indexOfMin = startIndex;

	for (int index = startIndex + 1; index < numUsed; index++) {
		if (a[index] < min) {
			min = a[index];
			indexOfMin = index;
		}
	}

	return indexOfMin;
}

template<class T>
void printRes(const T a[], int startIndex, int numUsed) {
	for (int i = startIndex; i < numUsed; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

template <class T>
int searchArray(T* arr, T key, int sizeOfArr){
	int first(0), mid;
	int last = sizeOfArr - 1;

	while (first <= last){
		mid = (first + last) / 2;

		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}
	return -1;
}

template <class T>
void toString(T key, int result) {
	if (result == -1) {
		cout << key << " is not in the array." << endl;
	}
	else {
		cout << key << " is at index " << result << "." << endl;
	}
}


