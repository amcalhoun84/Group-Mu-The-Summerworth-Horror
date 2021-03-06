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

	vector<int> playerInventory;
	string characterName;
	string characterDescription;

	bool hasLight;

public:

	Player();
	Player(int health, int sanity);
	void setHealth(int health);
	void setSanity(int sanity);
	int getHealth();
	int getSanity();
	void getInventory(vector<Item> &itemStorage);
	void addInventory(int itemID);
	void removeInventory(int itemID);

};

#endif // !PLAYER_H