#include "passport.hpp"

using namespace std;

Passport::Passport()
{
	this->itemID = 16;
	this->objName = "Caleb's Passport";
	this->objDescription = "Judging by the number of places Caleb has been, he will need to get an extension to his passport soon. In fact, you're surprised Mars and the Moon aren't on here by now.";
	this->shortDesc = "A heavily stamped passport.";
	this->keywords = "passport";
	this->health = 1;
	this->scoreValue = 20;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

Passport::~Passport()
{
	cout << this->objName << " removed from the world." << endl;
}