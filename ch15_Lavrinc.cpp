/*Samantha Lavrinc
CIT 245-701B - 03/25/2020
This program demonstrates base and 
inheretance classes.*/

#include <cstdlib>
#include <iostream>
#include <string>
#include "Gun.h"
#include "Handgun.h"
#include "Revolver.h"
#include "Pistol.h"

using namespace LavrincGun;
using std::cout;
using std::endl;

int main() {
	Revolver testRevolver("Smith & Wesson", "0.357", "Hoague Grips", "Trijicon", true, 6, false);
	//testRevolver.print();
	cout << endl;

	string manufacturer = "Glock", caliber = "9 mm", grips = "Manufacturers Grips",
		   sights = "3 dot sights";
	bool laser(false), semiAuto(true);

	//Pistol testPistol("Glock", "9mm", "Manufacturers grips", "3 dot sights", false, false);
	Pistol testPistol;
	testPistol.setManufacturer(manufacturer);
	testPistol.setCaliber(caliber);
	testPistol.setGrip(grips);
	testPistol.setSights(sights);
	testPistol.setLaser(laser);
	testPistol.setSemiAuto(semiAuto);
	//testPistol.print();

	const int numOfGuns(2);

	Gun* gunCabinet[numOfGuns];

	gunCabinet[0] = &testRevolver;
	gunCabinet[1] = &testPistol;

	for(int i = 0; i < numOfGuns; i++) {
		gunCabinet[i]->print();
	}

	cout << endl;


	system("PAUSE");
	return 0;

}