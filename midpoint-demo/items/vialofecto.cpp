#include "vialofecto.hpp"

using namespace std;

VialOfEcto::VialOfEcto()
{
	this->itemID = 24;
	this->objName = "a vial of ectoplasm";
	this->objDescription = "The collected ectoplasm of the One Who Sleeps";
	this->shortDesc = "vial of ecto";
	this->keywords = "ectoplasm";
	this->health = 1;
	this->scoreValue = 50;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = false;
	this->usable = true;

}

VialOfEcto::~VialOfEcto()
{
	cout << this->objName << " removed from the world." << endl;
}