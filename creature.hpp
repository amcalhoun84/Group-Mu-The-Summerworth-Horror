#ifndef _CREATURE_HPP
#define _CREATURE_HPP

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "worldEngine.hpp"

using namespace std;

class Creature
{
protected:

	string creatureName;
	string creatureDescription;
	// hashMap -- descriptive words;

	int wanderDirection;
	int critterHealth;
	int attack;

	vector<int> critterInventory; // in case it is carrying anything 

	bool alive;
	bool essential; // protects creature from being attacked until certain parameters are fulfilled.
	bool invincible; // need a special item to attack.

public:
	Creature();
	Creature(string creatureName, string creatureDescription);
	~Creature();
	
	string getName();
	string getDesc();

	int attackPlayerHP();
	int setHealth(int attack);
	int getHealth();
	
	Command* wanderAround(string wanderCmd);
	Command* flee();
	
	void die();
	void setStatus(bool status);
	bool getStatus();
	// int??? replaceDeadWithCorpse();

};

#endif