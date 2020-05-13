/*Samantha Lavrinc
CIT 245-701B - 03/25/2020
This is the implementation file for pistol.*/

#include <string>
#include <iostream>
#include "Pistol.h"

using std::string;
using std::cout;
using std::endl;

namespace LavrincGun {
	Pistol::Pistol() :Handgun(), classSemiAuto(false) {
		//intentionally empty
	}

	Pistol::Pistol(const string& userManufacturer, const string& userCaliber,
		const string& userGrips, const string& userSight,
		const bool& userLaser, const bool& userSemiAuto)
		: Handgun(userManufacturer, userCaliber, userGrips, userSight, userLaser),
		 classSemiAuto(userSemiAuto) {
		//intentionally empty
	}

	void Pistol::getSemiAuto() {
		if (classSemiAuto == true) {
			cout << "Semi-Auto";
		}
	}

	void Pistol::setSemiAuto(bool userSemiAuto) {
		classSemiAuto = userSemiAuto;
	}

	void Pistol::print(){
		cout << "Pistol: " << endl;
		cout << getManufacturer() << ", " << getCaliber() << ", ";
		getSemiAuto();
		cout << ", " << getaGrip() << ", ";
		getLaser();
		cout << ", " << getSights() << endl;
	}

}