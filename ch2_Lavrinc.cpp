/*  ----------
	Samantha Lavrinc
	CIT 245-701B
	2020-01-30
	This program determines the buoyant force 
	of a sphere, and whether it will float.
	----------		*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	int cont;
	double radius, weight, buoF, volume;
	const double PI(3.141592), waterD(62.4);

	do {
		cout << "This program computes Buoyant Force in water given the volume of a sphere." << endl;
		cout << "Based on these results, it determines whether the sphere is a witch." << endl;

		cout << "\nEnter the radius of the sphere: ";
		cin >> radius;
		cout << "You entered: " << radius << endl;

		cout << "\nEnter the weight of the sphere: ";
		cin >> weight;
		cout << "You entered: " << weight << endl;

		volume = (4.0 / 3.0) * PI * pow(radius, 3);
		buoF = volume * waterD;

		cout << "\nBuoyant Force = " << buoF << endl;

		if (weight <= buoF) 
			cout << "\nThe sphere floats. It's a witch!" << endl;
		else 
			cout << "\nThe sphere sinks. It's not a witch." << endl;
		
		cout << "\nWould you like to recalculate? (1 = Yes, 0 = Exit)" << endl;
		cin >> cont;

	} while (cont != 0); 

	system("PAUSE");
	return 0;
}