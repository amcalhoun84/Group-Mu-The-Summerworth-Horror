#include "player.hpp"

Player::Player()
{
	this->itemID = 0;
	this->objName = "You";
	this->objDescription = "You are a hard boiled detective.";
	this->shortDesc = "You";
	this->keywords = "me";
	this->health = 100;
	this->sanityPoints = 30;
	this->usable = false;
	this->essential = false;
	this->indestructible = false;
	this->invincible = false;
	this->canCarry = false;
	this->alive = true;

}

Player::~Player()
{

}

void Player::putInventory(Object object)
{
	inventory.push_back(object);
}

void Player::getInventory()
{
	cout << "The following items are in your inventory: " << endl;
	for(int i=0; i<inventory.size(); i++)
	{
		cout << inventory.at(i).getObjName() << endl;
	}
}

void Player::getRecord()
{
	cout << "Number of moves: " << this->getMoves() << endl;
	cout << "Health: " << this->getHealth() << endl;
	cout << "Sanity: " << this->sanityPoints;
	cout << "Other information." << endl;
}