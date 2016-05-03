#include "../object.hpp"
#include "../object.cpp"
#include "strangebook.hpp"

using namespace std;

StrangeBook::StrangeBook()
{
	this->itemID = 23;
	this->objName = "strange book";
	this->objDescription = "A very strange book... the binding looks to be human skin";
	this->shortDesc = "strange ritual book";
	this->keywords = "book";
	this->health = 1;
	this->scoreValue = 30;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = false;
	this->usable = false;

}

StrangeBook::~StrangeBook()
{
	cout << this->objName << " removed from the world." << endl;
}