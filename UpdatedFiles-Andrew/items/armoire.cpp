#include "../object.hpp"
#include "../object.cpp"
#include "armoire.hpp"

using namespace std;

Armoire::Armoire()
{
	this->itemID = 1;
	this->objName = "Sturdy, Ornate Armoire";
	this->objDescription = "A well crafted, lovingly cared for heir-loom armoire. A bloody handprint is smeared across the front.";
	this->shortDesc = "A Sturdy Victorian Armoire";
	this->keywords = "armoire";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = false;
	this->invincible = false;
	this->indestructible = true;
	this->usable = false;

}

Armoire::~Armoire()
{
	cout << this->objName << " removed from the world." << endl;
}
