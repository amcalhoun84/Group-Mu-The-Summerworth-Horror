#include "redcandles.hpp"

using namespace std;

RedCandles::RedCandles()
{
	this->itemID = 18;
	this->objName = "red candles";
	this->objDescription = "They look like the kind of candles you get at an occult bookstore.";
	this->shortDesc = "red ritual candles";
	this->keywords = "candles";
	this->health = 1;
	this->scoreValue = 10;
	this->alive = false;
	this->canCarry = true;
	this->invincible = false;
	this->indestructible = true;
	this->usable = true;

}

RedCandles::~RedCandles()
{
	cout << this->objName << " removed from the world." << endl;
}