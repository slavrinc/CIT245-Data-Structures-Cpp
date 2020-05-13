/*	Samantha Lavrinc
	CIT-245-701B
	03-10-2020
	This is the implementation file for f.
*/

#include "ch11_f_Lavrinc.h"
#include <cstdlib>
#include <iostream>

using namespace std;

F::F() {
	greeting = "Hello from f.";
}

void F::hello() {
	cout << greeting << endl;
}
