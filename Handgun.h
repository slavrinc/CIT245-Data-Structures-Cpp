/*Samantha Lavrinc
CIT 245-701B - 03/25/2020
This is the header file for handgun.*/

#pragma once
#ifndef HANDGUN_H
#define HANDGUN_H

#include <string>
#include "Gun.h"

using std::string;

namespace LavrincGun {
	class Handgun : public Gun {
	public:
		Handgun();
		Handgun(const string& userManufacturer, const string& userCaliber,
			const string& userGrips, const string& usersights, bool userLaser);

		string getaGrip();
		string getSights();
		void setGrip(const string& userGrip);
		void setSights(const string& userSight);

		void getLaser();
		void setLaser(bool userLaser);
		void print();

	private:
		string classGrips, classSight;
		bool classLaser;

	};
}

#endif