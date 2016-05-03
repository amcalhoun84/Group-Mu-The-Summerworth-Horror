#include "../object.hpp"
#include "../object.cpp"
#include "pistol.hpp"

using namespace std;

Pistol::Pistol()
{
	this->itemID = 17;
	this->objName = "9MM S&W Pistol";
	this->objDescription = "A standard issue cop pistol.";
	this->shortDesc = "standard issue pistol";
	this->keywords = "pistol";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

Pistol::~Pistol()
{
	cout << this->objName << " removed from the world." << endl;
}