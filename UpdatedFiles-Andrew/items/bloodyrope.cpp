#include "../object.hpp"
#include "../object.cpp"
#include "bloodyrope.hpp"

using namespace std;

BloodyRope::BloodyRope()
{
	this->itemID = 5;
	this->objName = "A bloody length of rope";
	this->objDescription = "A frayed bit of rope, soaked in blood.";
	this->shortDesc = "bloody rope";
	this->keywords = "rope";
	this->health = 1;
	this->scoreValue = 10;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

BloodyRope::~BloodyRope()
{
	cout << this->objName << " removed from the world." << endl;
}