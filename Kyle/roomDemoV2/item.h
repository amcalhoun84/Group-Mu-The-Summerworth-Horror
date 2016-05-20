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
					// booleans
	bool canCarry;
	bool indestructible; // Can't destroy the item -- only false for certain plot items.
	bool usable;

public:

	Item() {}; // generic constructor

	Item(string name, string description, string shortDesc, int itemId, int scoreValue, int health, bool canCarry, bool indestructible, bool usable);

	// Setters
	void setName(string name) { this->name = name; }
	void setDesc(string desc) { this->description = desc; }
	void setShort(string sdesc) { this->shortDesc = sdesc; }

	void setHealth(int health) { this->health = health; }
	void setScoreValue(int score) { this->scoreValue = score; }

	void setCanCarry(bool cCarry) { this->canCarry = cCarry; }
	void setIndestructible(bool indest) { this->indestructible = indest; }
	void setUsable(bool setUse) { this->usable = setUse; }

	// Getters
	string getName() { return name; }
	string getDesc() { return description; }
	string getObjShort() { return shortDesc; }

	int getItemID() { return itemID; }
	int getHealth() { return health; }
	int getScore() { return scoreValue; }

	bool getCanCarry() { return canCarry; }
	bool getIndestructible() { return indestructible; }
	bool getUsable() { return usable; }
	
	void displayDescription();
	void displayName();
	void displayShortDesc();
};


#endif // ITEM_H