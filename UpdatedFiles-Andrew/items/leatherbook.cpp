#include "../object.hpp"
#include "../object.cpp"
#include "leatherbook.hpp"

using namespace std;

LeatherBook::LeatherBook()
{
	this->itemID = 13;
	this->objName = "leather-bound book";
	this->objDescription = "A leather-bound book with strange writing inside. It's in a language you don't understand.";
	this->shortDesc = "leather book";
	this->keywords = "book";
	this->health = 1;
	this->scoreValue = 15;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

LeatherBook::~LeatherBook()
{
	cout << this->objName << " removed from the world." << endl;
}