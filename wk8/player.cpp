#include "player.h"
#include "item.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

Player::Player()
{
	playerHealth = 100;
	playerSanity = 25;
	playerInventory.push_back(3);
	playerInventory.push_back(32);
	playerInventory.push_back(33);
	playerInventory.push_back(204);
}

Player::Player(int health, int sanity)
{
	this->playerHealth = health;
	this->playerSanity = sanity;
}

void Player::setHealth(int health)
{
	this->playerHealth = health;
}

void Player::setSanity(int sanity)
{
	playerSanity = sanity;
}

int Player::getHealth()
{
	return playerHealth;
}

int Player::getSanity()
{
	return playerSanity;
}

void Player::getInventory(vector<Item> &itemStorage)
{
	cout << "Your inventory: " << endl;
	for (int i = 0; i < playerInventory.size(); i++)
	{
		for (int j = 0; j < itemStorage.size(); j++)
		{
			if (playerInventory[i] == itemStorage[j].getItemID())
			{
				itemStorage[j].displayName();
			}			
		}
	}
}

void Player::addInventory(int itemID)
{
	playerInventory.push_back(itemID);
}

void Player::removeInventory(int itemID)
{
	playerInventory.erase(find(playerInventory.begin(), playerInventory.end(), itemID));
}


