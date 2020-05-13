/*Samantha Lavrinc
CIT 245-701B - 03/25/2020
This is the header file for gun.*/

#pragma once

#ifndef GUN_H
#define GUN_H

#include <string>
#include <cstdlib>

using std::string;

namespace LavrincGun {

	class Gun {
	public:
		Gun();
		Gun(const string& userManufacturer, const string& userCaliber);
		string getManufacturer();
		string getCaliber();
		void setManufacturer(const string& userManufacturer);
		void setCaliber(const string& userCaliber);
		virtual void print();

	private:
		string classManufacturer, classCaliber, classGrips, classSight;
	};
}

#endif