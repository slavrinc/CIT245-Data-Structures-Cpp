/*Samantha Lavrinc
CIT 245-701B - 03/25/2020
This is the header file for pistol*/

#pragma once
#ifndef PISTOL_H
#define PISTOL_H

#include <string>
#include "Handgun.h"

using std::string;

namespace LavrincGun {
	class Pistol : public Handgun {
	public:
		Pistol();
		Pistol(const string& userManufacturer, const string& userCaliber,
			const string& userGrips, const string& usersights, const bool& userLaser,
			const bool& userSemiAuto);

		void getSemiAuto();
		void setSemiAuto(bool userSemiAuto);
		void print();

	private:
		bool classSemiAuto;
	};
}

#endif
