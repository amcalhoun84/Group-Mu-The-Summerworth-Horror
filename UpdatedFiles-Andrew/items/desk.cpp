#include "../object.hpp"
#include "../object.cpp"
#include "desk.hpp"

using namespace std;

Desk::Desk()
{
	this->itemID = 9;
	this->objName = "a desk";
	this->objDescription = "A big heavy desk";
	this->shortDesc = "An old desk";
	this->keywords = "desk";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = false;
	this->invincible = false;
	this->indestructible = true;
	this->usable = false;

}

Desk::~Desk()
{
	cout << this->objName << " removed from the world." << endl;
}