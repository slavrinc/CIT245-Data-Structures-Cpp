/*Samantha Lavrinc
CIT 245-701B - 03/25/2020
This is the implementation file for handgun.*/

#include <string>
#include <iostream>
#include "Handgun.h"

using std::string;
using std::cout;
using std::endl;

namespace LavrincGun {
	Handgun::Handgun():Gun(), classGrips("Grips Unknown."), classSight("Sights unknown"), classLaser(false) {
		//intentionally empty
	}

	Handgun::Handgun(const string& userManufacturer, const string& userCaliber,
		const string& userGrips, const string& userSight, bool userLaser) 
		: Gun(userManufacturer, userCaliber), classGrips(userGrips), classSight(userSight), classLaser(userLaser) {
		//intentionally empty
	}

	string Handgun::getaGrip() {
		return classGrips;
	}

	string Handgun::getSights() {
		return classSight;
	}

	void Handgun::setGrip(const string& userGrip) {
		classGrips = userGrip;
	}

	void Handgun::setSights(const string& userSight) {
		classSight = userSight;
	}

	void Handgun::getLaser() {
		if (classLaser == true) {
			cout << "laser";
		}
		else {
			cout << "no laser";
		}
	}

	void Handgun::setLaser(bool userLaser) {
		classLaser = userLaser;
	}

	void Handgun::print() {
		cout << "Handgun: " << endl;
		cout << getManufacturer() << ", " << getCaliber()
			<< ", " << getaGrip() << ", ";
		getLaser();
		cout << ", " << getSights() << endl;
	}


}