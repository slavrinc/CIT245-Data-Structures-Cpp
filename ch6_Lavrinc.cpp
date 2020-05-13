/*  Samantha Lavrinc
	02-13-2020 ~ CIT 245-701B
	This program creates a class to represent players in a game
	and tests class member functions.*/

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Player {
private:
	string name, password, items[4];
	int experience, PPosX, PPosY;
	const int arrSize = 4;

public: 
	//constructors
	Player() {
		name = "Default";
		password = "NULL";
		experience = 0;
		PPosX = 0;
		PPosY = 0;
		for (int i = 0; i < arrSize; i++) {
			items[i] = "NULL";
		}
	}

	Player(string items1[], string name1, string password1, int experience1, int PPosX1, int PPosY1) {
		name = name1;
		password = password1;
		experience = experience1;
		PPosX = PPosX1;
		PPosY = PPosY1;
		for (int j = 0; j < arrSize; j++) {
			items[j] = items1[j];
		}
	}

	//public mutator and accesor methods
	//setVarName functions allows you to set the value of the member variable.
	//getVarName functions allows you to get the value of the member variable.
	string getName() {
		return name;
	}

	void setName(string n) {
		name = n;
	}

	string getPass() {
		return password;
	}

	void setPass(string p) {
		password = p;
	}

	int getExp() {
		return experience;
	}

	void setExp(int e) {
		experience = e;
	}

	int getXPos() {
		return PPosX;
	}

	void setXPos(int x) {
		PPosX = x;
	}

	int getYPos() {
		return PPosY;
	}

	void setYPos(int y) {
		PPosY = y;
	}

	string* getItems() {
		return items;
	}

	void setInv(string newitems[]);

	void replaceItem(string olditem, string newitem);
	//input a current inventory item and a new item to replace single item.
	
	void displayInfo(Player player);
	//displays the player information
	
};

int main() {
	cout << "This program generates three player objects and displays them."<<endl;

	string p1items[] = { "Swiss Army Knife", "ID Card", "Paper Clip", "Duct Tape" };
	Player *p1 = new Player(p1items, "MacGyver", "M4cIsB4ck", 1985, 300, 1024);

	string p2items[] = { "Cricket", "Ticket to Circus", "String", "Gold Badge" };
	Player* p2 = new Player(p2items, "Pinocchio", "n3v3rLi3", 1940, 285, 345);

	string p3items[] = { "My Precious", "Birthday Present", "One Ring","Fish" };
	Player* p3 = new Player(p3items, "Smeagol", "TricksyHobbitses2", 589, 4654, 28);

	p1->displayInfo(*p1);
	p2->displayInfo(*p2);
	p3->displayInfo(*p3);
	
	cout << "\nTesting Default Constructor...\n";
	Player* pdefault = new Player();
	pdefault->displayInfo(*pdefault);

	cout << "\nSetting variables...\n";
	pdefault->setName("NewName");
	pdefault->setPass("TestPass");
	pdefault->setExp(325);
	pdefault->setXPos(42);
	pdefault->setYPos(4574687);
	pdefault->setInv(p1items);
	pdefault->displayInfo(*pdefault);

	pdefault->replaceItem("Swiss Army Knife", "Candy");
	pdefault->displayInfo(*pdefault);

	cout << endl;
	system("PAUSE");
	return 0;
}


void Player::displayInfo(Player player) {
	cout << "\nPlayer Info - \n";
	cout << "Name: " << getName() << endl;
	cout << "Password: " << getPass() << endl;
	cout << "Experience: " << getExp() << endl;
	cout << "(X,Y): (" << getXPos() << "," << getYPos() << ")" << endl;
	cout << "Item Inventory: " << endl;

	string* inv = getItems();
	for (int m = 0; m < arrSize; m++) {
		cout << "- " << inv[m] << endl;
	}
}

void Player::setInv(string newitems[]) {
	for (int n = 0; n < arrSize; n++) {
		items[n] = newitems[n];
	}
}

void Player::replaceItem(string oldItem, string newItem) {
	for (int o = 0; o < arrSize; o++) {
		if (items[o].compare(oldItem)) {
			items[o] = items[o];
		}
		else {
			cout << "\n-Removing: \"" << items[o] << "\" +Inserting: \"" << newItem << "\"...\n";
			items[o] = newItem;
		}
	}
}