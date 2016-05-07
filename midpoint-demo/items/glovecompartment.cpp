#include "glovecompartment.hpp"

using namespace std;

GloveCompartment::GloveCompartment()
{
	this->itemID = 11;
	this->objName = "glove compartment";
	this->objDescription = "The car glove compartment";
	this->shortDesc = "a glove compartment";
	this->keywords = "glove compartment";
	this->health = 1;
	this->scoreValue = 0;
	this->alive = false;
	this->canCarry = false;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

GloveCompartment::~GloveCompartment()
{
	cout << this->objName << " removed from the world." << endl;
}