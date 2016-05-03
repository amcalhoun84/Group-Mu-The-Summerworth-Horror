#include "../object.hpp"
#include "../object.cpp"
#include "bloodyrobe.hpp"

using namespace std;

BloodyRobe::BloodyRobe()
{
	this->itemID = 4;
	this->objName = "A bloody robe";
	this->objDescription = "You'd figure it was a cheap bathrobe made of heavy, dark brown cloth, but the hood gives it a sinister edge";
	this->shortDesc = "A bloody, heavy robe";
	this->keywords = "robe";
	this->health = 1;
	this->scoreValue = 10;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

BloodyRobe::~BloodyRobe()
{
	cout << this->objName << " removed from the world." << endl;
}