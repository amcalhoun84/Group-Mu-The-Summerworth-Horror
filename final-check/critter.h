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
		critterShortDesc,
		talk1,
		talk2,
		talk3,
		accuse1,
		accuse2;

	

	int id,
		health,
		arraySize,
		damageValue,
		sanityAttack,
		talkCounter;
	// for the combat engine
	int attack;

	bool essential,
		invincible,
		evidence,
		accused;

public:
	vector<string> keywords;

	Critter();
	Critter(string critterName, string critterDesc, string critterShortDesc, int id, int damageValue, int sanityAttack, bool invincible, bool essential, bool evidence, bool accused);
	
	~Critter();

	// setters
	//added additional setters for dataHandler
	void setName(string name) { critterName = name; }
	void setCritterDescription(string description) { critterDesc = description; }
	void setCritterShortDesc(string description) { critterShortDesc = description; }
	void setTalk1(string dialogue) { talk1 = dialogue; }
	void setTalk2(string dialogue) { talk2 = dialogue; }
	void setTalk3(string dialogue) { talk3 = dialogue; }
	void setAccuse1(string dialogue) { accuse1 = dialogue; }
	void setAccuse2(string dialogue) { accuse2 = dialogue; }
	//void setCritterKeywords(string keyword) { keywords.push_back(keyword); }

	void setId(int id) { this->id = id; }
	void setHealth(int _health) { this->health = _health; }
	void setDV(int _dv) { this->damageValue = _dv; }
	void setSA(int _sa) { this->sanityAttack = _sa; }
	void setTalkCounter(int counter) { this->talkCounter = counter; }

	void setEssential(bool _essential) { this->essential = _essential; }
	void setInvincible(bool _invincible) { this->invincible = _invincible; }
	void setEvidence(bool _evidence) { this->evidence = _evidence; }
	void setAccused(bool _accused) { this->accused = _accused; }
	bool getAccused() { return this->accused; }

	void addKeyword(string keyword) { this->keywords.push_back(keyword); }

	// getters
	int getId() { return id; }
	int getHealth() { return health; }
	int getDV() { return damageValue; }
	int getSA() { return sanityAttack; }
	int getTalkCounter() { return talkCounter; }
	string getName() { return critterName; }
	string getDesc() { return critterDesc; }
	string getShortDesc() { return critterShortDesc; }
	string getTalk1() { return talk1; }
	string getTalk2() { return talk2; }
	string getTalk3() { return talk3; }
	string getAccuse1() { return accuse1; }
	string getAccuse2() { return accuse2; }


	// Combat Engine -- we don't need a separate class for this. These will be used in tandem
	// with getters and setters. We just need to know the extend of damage done.
	int attackCritter();
	int attackSanity();
	//int damageOWS(item Item); // there are three items, the blue rose, the silver cross, and mist essence that are used to damage the OWS. 
	//Dialogue functions
	void displayTalk();
	void displayAccuse1();
	void displayAccuse2();
};


#endif // CRITTER_H