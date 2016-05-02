#include "object.hpp"

using namespace std;

Object::Object()
{
	this->itemID = -1;
	this->objName = "an object";
	this->objDescription = "An object for the tech demo for our engine";
	this->shortDesc = "A demo object";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;

}

Object::~Object()
{
	cout << "Object removed from the world." << endl;
}