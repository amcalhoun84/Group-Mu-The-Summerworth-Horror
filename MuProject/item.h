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

	int itemId;     // ID for the vector functions -- will be set for each object
	int scoreValue; // what is the score you get for collecting it?
	int damageValue;
	// booleans
	bool canCarry;
	bool usable;
	bool edible;
	
	

public:

	vector<string> keywords;

	Item() {}; // generic constructor

	Item(string name, string description, string shortDesc, int itemId, int scoreValue, int damageValue, bool canCarry, bool usable, bool edible);

	// Setters
	void setName(string name) { this->name = name; }
	void setDesc(string desc) { this->description = desc; }
	void setShort(string sdesc) { this->shortDesc = sdesc; }

	void setItemId(int id) { this->itemId = id; }
	void setScoreValue(int score) { this->scoreValue = score; }
	void setDamageValue(int damage) { this->damageValue = damage; }

	void setCanCarry(bool cCarry) { this->canCarry = cCarry; }
	void setUsable(bool setUse) { this->usable = setUse; }
	void setEdible(bool edible) { this->edible = edible; }

	// Getters
	string getName() { return name; }
	string getDesc() { return description; }
	string getObjShort() { return shortDesc; }

	int getItemId() { return itemId; }
	int getScoreValue() { return scoreValue; }
	int getDamageValue() { return damageValue; }

	bool getCanCarry() { return canCarry; }
	bool getUsable() { return usable; }
	bool getEdible() { return edible; }

	void displayDescription();
	void displayName();
	void displayShortDesc();
};


#endif // ITEM_H