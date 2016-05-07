#include "bigdoor.hpp"

using namespace std;

BigDoor::BigDoor()
{
	this->itemID = 2;
	this->objName = "A big door";
	this->objDescription = "The door is finely cared for, with Victorian vaulting. It has brass door handles and is in immaculate condition.";
	this->shortDesc = "A large, vaulted door";
	this->keywords = "door";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = false;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

BigDoor::~BigDoor()
{
	cout << this->objName << " removed from the world." << endl;
}
