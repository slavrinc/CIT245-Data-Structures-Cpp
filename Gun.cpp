/*Samantha Lavrinc
CIT 245-701B - 03/25/2020
This is the implementation file for gun.*/

#include <string>
#include <cstdlib>
#include <iostream>
#include "Gun.h"

using std::string;
using std::cout;
using std::endl;

namespace LavrincGun {
	Gun::Gun() : classManufacturer("Manufacturer Unknown."),
				 classCaliber("Caliber Unknown.") {
		//intentionally empty
	}

	Gun::Gun(const string& userManufacturer, const string& userCaliber) :
				 classManufacturer(userManufacturer),
				 classCaliber(userCaliber) {
		//intentionally empty
	}

	string Gun::getManufacturer() {
		return classManufacturer;
	}

	string Gun::getCaliber() {
		return classCaliber;
	}

	void Gun::setManufacturer(const string& userManufacturer) {
		classManufacturer = userManufacturer;
	}

	void Gun::setCaliber(const string& userCaliber) {
		classCaliber = userCaliber;
	}

	void Gun::print() {
		cout << "Gun: " << endl;
		cout << getManufacturer() << ", " << getCaliber() << endl;
	}
}
