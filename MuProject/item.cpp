#include "item.h"
#include <iostream>
#include <string>

using namespace std;

Item::Item(string name, string description, string shortDesc, int itemId, int scoreValue, int health, bool canCarry, bool usable, bool edible)
{
	this->name = name;
	this->description = description;
	this->shortDesc = shortDesc;
	this->itemID = itemId;
	this->scoreValue = scoreValue;
	this->health = health;
	this->canCarry = canCarry;
	this->edible = edible;
	this->usable = usable;

}



void Item::displayDescription()
{
	cout << description << endl;
}

void Item::displayName()
{
	cout << name << endl;
}

void Item::displayShortDesc()
{
	cout << shortDesc << endl;
}