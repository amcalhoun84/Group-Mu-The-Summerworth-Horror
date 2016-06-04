#include "critter.h"
using namespace std;

Critter::Critter()
{
	this->critterName = "Default Critter";
	this->critterDesc = "You see a very non-descript critter. In fact, try clicking it about 30 times. See what happens."; // Warcraft/Starcraft reference.
	this->critterShortDesc = "A critter!";
	this->health = 1;
	this->damageValue = 1;
	this->sanityAttack = 0;
	this->talkCounter = 0;
	this->essential = false;
	this->invincible = false;
	this->evidence = false;
	this->accused = false;
}

Critter::Critter(string critterName, string critterDesc, string critterShortDesc, int id, int damageValue, int sanityAttack, bool invincible, bool essential, bool evidence, bool accused)
{
	this->critterName = critterName;
	this->critterDesc = critterDesc;
	this->critterShortDesc = critterShortDesc;
	this->health = health;
	this->damageValue = damageValue;
	this->sanityAttack = sanityAttack;
	this->essential = essential;
	this->invincible = invincible;
	this->evidence = evidence;
	this->accused = accused;
}

Critter::~Critter()
{
}

int Critter::attackCritter()
{
	int attack = (rand() % damageValue) + 1;
	return attack;
}

int Critter::attackSanity()
{
	attack = (rand() % sanityAttack) + 1;
	return attack;
}

void Critter::displayTalk()
{
	if (talkCounter == 0)
	{
		cout << talk1 << endl << endl;
		talkCounter++;
	}
	else if (talkCounter == 1)
	{
		cout << talk2 << endl << endl;
		talkCounter++;
	}
	else if (talkCounter == 2)
	{
		cout << talk3 << endl << endl;
		talkCounter = 0;
	}
}

void Critter::displayAccuse1()
{
	cout << accuse1 << endl << endl;
}
void Critter::displayAccuse2()
{
	cout << accuse2 << endl << endl;
}


