#include "bowieknife.hpp"

using namespace std;

BowieKnife::BowieKnife()
{
	this->itemID = 7;
	this->objName = "a bowie knife";
	this->objDescription = "Your trusty bowie knife. You've had it in the decade and a half";
	this->shortDesc = "A well-cared for bowie knife";
	this->keywords = "knife";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

BowieKnife::~BowieKnife()
{
	cout << this->objName << " removed from the world." << endl;
}