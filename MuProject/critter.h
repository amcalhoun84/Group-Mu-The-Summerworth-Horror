#ifndef CRITTER_H
#define CRITTER_H

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "item.h"

using namespace std;

class Critter
{
private:

	string critterName,
		critterDesc,
		critterShortDesc;

	vector<string> keywords;

	int critterID,
		health,
		arraySize,
		damageValue,
		sanityAttack;
	// for the combat engine
	int attack;

	bool essential,
		invincible,
		evidence,
		accused;

public:
	Critter();
	Critter(string critterName, string critterDesc, string critterShortDesc, vector<string> keywords, int health, int damageValue, int sanityAttack, bool essential, bool invincible, bool evidence, bool accused);
	~Critter();

	// setters
	void setCritterID(int id) { this->critterID = id; }
	void setName(string name) { this->critterName; }
	void setHealth(int _health) { this->health = _health; }
	void setDV(int _dv) { this->damageValue = _dv; }
	void setSA(int _sa) { this->sanityAttack = _sa; }

	void setEssential(bool _essential) { this->essential = _essential; }
	void setInvincible(bool _invincible) { this->invincible = _invincible; }
	void setEvidence(bool _evidence) { this->evidence = _evidence; }
	void setAccused(bool _accused) { this->accused = _accused; }

	// getters
	int getCritterID() { return this->critterID; }
	int getHealth() { return this->health; }
	int getDV() { return this->damageValue; }
	int getSA() { return this->sanityAttack; }
	string getName() { return this->critterName; }


	// Combat Engine -- we don't need a separate class for this. These will be used in tandem
	// with getters and setters. We just need to know the extend of damage done.
	int attackCritter();
	int attackSanity();
	//int damageOWS(item Item); // there are three items, the blue rose, the silver cross, and mist essence that are used to damage the OWS. 

};


#endif // CRITTER_H
