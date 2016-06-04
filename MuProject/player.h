#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <stdio.h>
#include "item.h"

using namespace std;

class Player
{
private:

	int playerHealth;
	int playerSanity;
	int equippedItem;
	int score;

	vector<int> playerInventory;
	string characterName;
	string characterDescription;

	bool hasLight;

public:

	Player();
	Player(int health, int sanity);
	void setHealth(int health);
	void setSanity(int sanity);
	void setEquippedItem(int equippedItem);
	void setScore(int score) { this->score = score; }
	void setHasLight(bool hasLight) { this->hasLight = hasLight; }

	int getHealth();
	int getSanity();
	int getEquippedItem();
	int getScore() { return score; }
	bool getHasLight() { return this->hasLight; }
	void displayInventory(vector<Item> &itemStorage);
	void addInventory(vector<Item> &itemStorage, int itemID);
	void getItems(vector<Item> &itemStorage, vector<string>&items);
	
	void removeInventory(int itemID);
	void getKeywords(vector<Item>& itemStorage, vector<string>& words);
	void getItemsVector(vector<int>&items) { items = this->playerInventory; }
	bool hasItem(int id);
};

#endif // !PLAYER_H