#include "item.h"
#include "graphics.h"
#include <iostream>
#include<string>

using namespace std;


Item::Item(string name, string description, string shortDesc, int itemId, int scoreValue, int damageValue, bool canCarry, bool usable, bool edible)
{
	this->name = name;
	this->description = description;
	this->shortDesc = shortDesc;
	this->itemId = itemId;
	this->scoreValue = scoreValue;
	this->damageValue = damageValue;
	this->canCarry = canCarry;
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
