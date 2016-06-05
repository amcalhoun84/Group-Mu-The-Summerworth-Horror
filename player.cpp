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
			if (playerInventory[i] == itemStorage[j].getItemId())
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
	for (int i = 0; i < playerInventory.size(); i++)
	{
		if (playerInventory[i] == itemID)
		{
			swap(playerInventory[i], playerInventory[playerInventory.size()-1]);
			playerInventory.pop_back();
			break;
		}
	}
}

void Player::getKeywords(vector<Item>& itemStorage, vector<string>& words)
{
	for (int i = 0; i < this->playerInventory.size(); i++)
	{
		for (int j = 0; j < itemStorage.size(); j++)
		{
			if (playerInventory[i] == itemStorage[j].getItemId())
			{
				for (int k = 0; k < itemStorage[j].keywords.size(); k++)
				{
					words.push_back(itemStorage[j].keywords[k]);
				}
			}
		}
	}
}

bool Player::hasItem(int id)
{
	bool itemPresent = false;
	for (int i = 0; i < this->playerInventory.size(); i++)
	{
		if (this->playerInventory[i] == id)
		{
			itemPresent = true;
		}
	}
	return itemPresent;
}


