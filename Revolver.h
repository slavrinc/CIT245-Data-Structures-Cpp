/*Samantha Lavrinc
CIT 245-701B - 03/25/2020
This is the header file for revolver.*/

#pragma once
#ifndef REVOLVER_H
#define REVOLVER_H

#include <string>
#include "Handgun.h"

using std::string;

namespace LavrincGun {
	class Revolver : public Handgun {
	public:
		Revolver();
		Revolver(const string& userManufacturer, const string& userCaliber,
			const string& userGrips, const string& usersights, const bool& userLaser,
			const int& userNoRounds, const bool& userSingleAction);

		int getRounds();
		void setRounds(int userRounds);

		void getSingleAction();
		void setSingleAction(bool userSingleAction);
		void print();

	private:
		int classNumberOfRounds;
		bool classSingleAction;
	};
}

#endif
