#include "murderbodies.hpp"

using namespace std;

MurderBodies::MurderBodies()
{
	this->itemID = 15;
	this->objName = "murder bodies";
	this->objDescription = "A nasty murder";
	this->shortDesc = "the bodies of the Summerworths";
	this->keywords = "bodies";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = false;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

MurderBodies::~MurderBodies()
{
	cout << this->objName << " removed from the world." << endl;
}