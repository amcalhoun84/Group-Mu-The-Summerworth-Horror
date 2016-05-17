#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Item
{

private:

	string name;
	string description;
	string shortDesc;

	int itemID;     // ID for the vector functions -- will be set for each object
	int scoreValue; // what is the score you get for collecting it?
	int health;     // how much damage can it take before it dies or breaks?
	int charges;
	int damageValue;

					// booleans
	bool canCarry;
	bool indestructible; // Can't destroy the item -- only false for certain plot items.
	bool usable;
	bool edible;


public:

	Item() {}; // generic constructor

	Item(string name, string description, string shortDesc, int itemId, int scoreValue, int health, int damageValue, int charges, bool canCarry, bool indestructible, bool usable, bool edible);
	~Item() {}; // generic destructor

	// Setters
	void setName(string name) { this->name = name; }
	void setDesc(string desc) { this->description = desc; }
	void setShort(string sdesc) { this->shortDesc = sdesc; }

	void setHealth(int health) { this->health = health; }
	void setScoreValue(int score) { this->scoreValue = score; }
	void setDV(int _dv) { this->damageValue = _dv; }
	void setCharges(int _charges) { this->charges = _charges; }

	void setCanCarry(bool cCarry) { this->canCarry = cCarry; }
	void setIndestructible(bool indest) { this->indestructible = indest; }
	void setUsable(bool setUse) { this->usable = setUse; }
	void setEdible(bool _edible) { this->edible = _edible; }


	// Getters
	string getName() { return this->name; }
	string getDesc() { return this->description; }
	string getObjShort() { return this->shortDesc; }

	int getItemID() { return this->itemID; }
	int getHealth() { return this->health; }
	int getScore() { return this->scoreValue; }
	int getDV() { return this->damageValue; }
	int getCharges() { return this->charges; }

	bool getCanCarry() { return this->canCarry; }
	bool getIndestructible() { return this->indestructible; }
	bool getUsable() { return this->usable; }
	bool getEdible() { return this->edible; }
	
	void displayDescription();
	void displayName();
	void displayShortDesc();
};


#endif // ITEM_H