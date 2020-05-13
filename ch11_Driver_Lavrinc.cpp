/*	Samantha Lavrinc
	CIT-245-701B
	03-10-2020
	This program demonstrates the use of separate files.
*/

#include <cstdlib>
#include "ch11_f_Lavrinc.h"
#include "ch11_g_Lavrinc.h"

using namespace std;

int main() {
	F ftest;
	G gtest;

	ftest.hello();
	gtest.hello();

	system("PAUSE");
	return 0;
}