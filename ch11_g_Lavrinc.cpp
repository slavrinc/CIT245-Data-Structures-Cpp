/*	Samantha Lavrinc
	CIT-245-701B
	03-10-2020
	This is the implementation file for g.
*/

#include "ch11_g_Lavrinc.h"
#include <cstdlib>
#include <iostream>

using namespace std;

G::G() {
	greeting = "Hello from g.";
}

void G::hello() {
	cout << greeting << endl;
}
