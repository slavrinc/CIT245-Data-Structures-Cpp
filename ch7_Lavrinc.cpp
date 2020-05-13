/*  Samantha Lavrinc
	02-18-2020 ~ CIT 245-701B
	This program creates a counter class with functions that
	increase and decrease the counter size.*/

#include <cstdlib>
#include <iostream>

using namespace std;

class Counter {
public:
	int  getCount(), getInc();
	void addCount(int addC), subCount(int subC);
	void displayInfo(Counter counter);

//default constructor
	Counter() {
		countSize = 0;
	}

//overloaded constructor
	Counter(int countSize1) {
		countSize = countSize1;
	}

private: 
	int countSize;
	static int incCount;
};

int main() {
	Counter* d = new Counter();
	Counter* c = new Counter(200);

	cout << "This demo creates two class objects, increases and decreases member values," << endl;
	cout << "and tracks a static counter variable." << endl;

	cout << "\nCurrent state of \"d\" default constructor counter: " << endl;
	d->displayInfo(*d);

	cout << "\nCurrent state of \"c\" counter created by assigning a value: " << endl;
	c->displayInfo(*c);

	cout << "\nAdding 85 to \"d\"..." << endl;
	d->addCount(85);
	d->displayInfo(*d);

	cout << "\nSubtracting 242 from \"c\"..." << endl;
	c->subCount(242);
	c->displayInfo(*c);

	cout << endl;
	system("PAUSE");
	return 0;
}

int Counter::incCount = 0;

int Counter::getCount() {
	return countSize;
}

int Counter::getInc() {
	return incCount;
}

void Counter::addCount(int addC) {
	for (int i = 0; i < addC; i++) {
		incCount++;
		countSize++;
	}
}

void Counter::subCount(int subC) {
	for (int i = 0; i < subC; i++) {
		incCount++;
		countSize--;
	}
}

void Counter::displayInfo(Counter counter) {
	cout << "Current count: " << getCount() << endl;
	cout << "Total increments/decrements: " << getInc() << endl;
}

