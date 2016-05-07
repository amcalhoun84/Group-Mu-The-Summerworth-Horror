#include "flashlight.hpp"

using namespace std;

Flashlight::Flashlight()
{
	this->itemID = 10;
	this->objName = "flashlight";
	this->objDescription = "A standard issue, industrial flashlight";
	this->shortDesc = "A standard issue flashlight";
	this->keywords = "flashlight";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

Flashlight::~Flashlight()
{
	cout << this->objName << " removed from the world." << endl;
}