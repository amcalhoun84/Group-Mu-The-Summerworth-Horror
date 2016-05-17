#include "item.h"
#include <iostream>
#include <string>

using namespace std;

Item::Item(string name, string description, string shortDesc, int itemId, int scoreValue, int health, int damageValue, int charges, bool canCarry, bool indestructible, bool usable, bool edible)
{
	this->name = name;
	this->description = description;
	this->shortDesc = shortDesc;
	this->itemID = itemId;
	this->scoreValue = scoreValue;
	this->health = health;
	this->damageValue = damageValue
	this->charges = charges;
	this->canCarry = canCarry;
	this->indestructible = indestructible;
	this->usable = usable;
	this->edible = edible;
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
