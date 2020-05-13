/*Samantha Lavrinc
CIT 245-701B - 03/25/2020
This is the implementation file for revolver.*/

#include <string>
#include <iostream>
#include "Revolver.h"

using std::string;
using std::cout;
using std::endl;

namespace LavrincGun {
	Revolver::Revolver() :Handgun(), classNumberOfRounds(0), classSingleAction(false) {
		//intentionally empty
	}

	Revolver::Revolver(const string& userManufacturer, const string& userCaliber,
		const string& userGrips, const string& userSight,
		const bool& userLaser, const int& userNoRounds, const bool& userSingleAction) 
		: Handgun(userManufacturer, userCaliber, userGrips, userSight, userLaser), 
		classNumberOfRounds(userNoRounds), classSingleAction(userSingleAction) {
		//intentionally empty
	}

	int Revolver::getRounds() {
		return classNumberOfRounds;
	}

	void Revolver::setRounds(int userRounds) {
		classNumberOfRounds = userRounds;
	}

	void Revolver::getSingleAction() {
		if (classSingleAction == true) {
			cout << "Single Action";
		}
		else {
			cout << "Double Action";
		}
	}

	void Revolver::setSingleAction(bool userSingleAction) {
		classSingleAction = userSingleAction;
	}

	void Revolver::print() {
		cout << "Revolver: " << endl;
		cout << getManufacturer() << ", " << getCaliber()
			<< ", " << getRounds() << " shot, ";
		getSingleAction();
		cout << ", " << getaGrip() << ", ";
		getLaser();
		cout << ", " << getSights() << endl;
	}

}