#include "signetring.hpp"

using namespace std;

SignetRing::SignetRing()
{
	this->itemID = 21;
	this->objName = "signet ring";
	this->objDescription = "The Summerworth family signet ring.";
	this->shortDesc = "signet ring";
	this->keywords = "ring";
	this->health = 1;
	this->scoreValue = 20;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = false;

}

SignetRing::~SignetRing()
{
	cout << this->objName << " removed from the world." << endl;
}