#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
// #include ... other necessary includes.

class Player 
{

private:

	int playerHealth;
	int playerSanity;
	int carryWeight;

	vector<int> playerInventory;
	std::string characterName;
	std::string characterDescription;

	bool hasLight;

public:

	Player();
	~Player();
	void setHealth(int health);
	void setSanity(int sanity);
	int getHealth();
	int getSanity();
	struct record getRecord();
	struct inventory getInventory();
	void addInventory(int itemID);
	void removeInventory(int itemID);
	// list of player commands

		// links to PARSERS
		// links to dictionary
		// other commands

};


#endif

