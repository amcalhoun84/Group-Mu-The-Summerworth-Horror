#include "ladder.hpp"

using namespace std;

Ladder::Ladder()
{
	this->itemID = 12;
	this->objName = "ladder";
	this->objDescription = "Looks like an ordinary ladder";
	this->shortDesc = "Ladder";
	this->keywords = "ladder";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = false;
	this->invincible = false;
	this->indestructible = true;
	this->usable = false;

}

Ladder::~Ladder()
{
	cout << this->objName << " removed from the world." << endl;
}