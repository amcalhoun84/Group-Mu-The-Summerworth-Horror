#include "player.h"
#include "item.h"
#include "parser.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

Player::Player()
{
	playerHealth = 100;
	playerSanity = 25;
	playerInventory.push_back(1);
	playerInventory.push_back(2);
	playerInventory.push_back(3);
	hasLight = false;
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
	this->playerSanity = sanity;
}

void Player::setEquippedItem(int equippedItem)
{
	this->equippedItem = equippedItem;
}

int Player::getHealth()
{
	return playerHealth;
}

int Player::getSanity()
{
	return playerSanity;
}

int Player::getEquippedItem()
{
	return equippedItem;
}

void Player::displayInventory(vector<Item> &itemStorage)
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

void Player::addInventory(vector<Item> &itemStorage, int itemID)
{
	playerInventory.push_back(itemID);
	cout << "You have added " << getItemName(itemStorage, itemID) << " to your inventory" << endl;
}

void Player::getItems(vector<Item>& itemStorage, vector<string> &items)
{
	for (int i = 0; i < playerInventory.size(); i++)
	{
		items.push_back(getItemName(itemStorage, playerInventory[i]));
	}
}


void Player::removeInventory(int itemID)
{
	playerInventory.erase(find(playerInventory.begin(), playerInventory.end(), itemID));
}

void Player::getKeywords(vector<Item>& itemStorage, vector<string>& words)
{
	for (int i = 0; i < this->playerInventory.size(); i++)
	{
		for (int j = 0; j < itemStorage.size(); j++)
		{
			if (playerInventory[i] == itemStorage[j].getItemID())
			{
				for (int k = 0; k < itemStorage[j].keywords.size(); k++)
				{
					words.push_back(itemStorage[j].keywords[k]);
				}
			}
		}
	}
}


