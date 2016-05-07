#include "bluerose.hpp"

using namespace std;

BlueRose::BlueRose()
{
	this->itemID = 6;
	this->objName = "A beautiful blue rose";
	this->objDescription = "The famous Summerworth blue rose. It bears a significant importance to the family dating back to the 1800s.";
	this->shortDesc = "A gorgeous, rare blue rose";
	this->keywords = "rose";
	this->health = 1;
	this->scoreValue = 5;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = false;

}

BlueRose::~BlueRose()
{
	cout << this->objName << " removed from the world." << endl;
}