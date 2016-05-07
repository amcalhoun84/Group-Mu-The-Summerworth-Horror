#include "serpdagger.hpp"

using namespace std;

SerpDagger::SerpDagger()
{
	this->itemID = 20;
	this->objName = "A serpentine dagger";
	this->objDescription = "A long curved, flamberge knife.";
	this->shortDesc = "A curvy knife";
	this->keywords = "dagger";
	this->health = 1;
	this->scoreValue = 15;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

SerpDagger::~SerpDagger()
{
	cout << this->objName << " removed from the world." << endl;
}