#include "../object.hpp"
#include "../object.cpp"
#include "bloodypamphlet.hpp"

using namespace std;

BloodyPamphlet::BloodyPamphlet()
{
	this->itemID = 3;
	this->objName = "A bloody pamphlet";
	this->objDescription = "There's a bloody pamphlet describing a catered trip to St. Moritz in Switzerland and a luxurious lodge for skiing.";
	this->shortDesc = "A blood-soaked travel brochure";
	this->keywords = "pamphlet";
	this->health = 1;
	this->scoreValue = 10;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

BloodyPamphlet::~BloodyPamphlet()
{
	cout << this->objName << " removed from the world." << endl;
}
