#include "ritualdoor.hpp"

using namespace std;

RitualDoor::RitualDoor()
{
	this->itemID = 19;
	this->objName = "ritual door";
	this->objDescription = "A door with occult symbology.";
	this->shortDesc = "smyboled door";
	this->keywords = "door";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = false;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

RitualDoor::~RitualDoor()
{
	cout << this->objName << " removed from the world." << endl;
}