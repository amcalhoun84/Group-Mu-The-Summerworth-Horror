#include "object.cpp"

Object::Object()
{
	this->objectName = "Object";
	this->objectDesc = "It's an object. It is pretty non-descript. In fact, it kind of looks like a tea pot.";
	this->weight = 1;
	this->indestructible = true;
	this->alive = false;
	this->invincible = false;
}

Object::Object(string objName, string objDesc, int weight, bool live)
{
	this->objectName = objName;
	this->objectDesc = objDesc; 
	this->weight = weight;
	this->indestructible = true;
	this->alive = live;
	this->essential = false;
	this->invincible = false;
}

Object::~Object()
{
	cout << "Object removed from the world."
}

// Methods for non-living objects

void Object::addItem(int itemID)
{
	// put the item in the inventory
	player_inv.push_back(itemID);
}

void Object::removeItem(int itemID)
{
	Object* removedItem = plchdr.at(itemID)
	player_inv.pop(itemID);
}

