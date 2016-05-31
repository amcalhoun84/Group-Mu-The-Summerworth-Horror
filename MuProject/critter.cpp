#include "critter.h"
using namespace std;

Critter::Critter()
{
	this->critterID = -1;
	this->critterName = "Default Critter";
	this->critterDesc = "You see a very non-descript critter. In fact, try clicking it about 30 times. See what happens."; // Warcraft/Starcraft reference.
	this->critterShortDesc = "A critter!";
	this->keywords.at(0) = "Critter";
	this->health = 1;
	this->damageValue = 1;
	this->sanityAttack = 0;
	this->essential = false;
	this->invincible = false;
	this->evidence = false;
	this->accused = false;

}

Critter::Critter(int critterID, string critterName, string critterDesc, string critterShortDesc, int health, int damageValue, int sanityAttack, bool essential, bool invincible, bool evidence, bool accused)
{

	this->critterID = critterID; 
	this->critterName = critterName;
	this->critterDesc = critterDesc;
	this->critterShortDesc = critterShortDesc;
	this->keywords = keywords;
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

int Critter::attackPlayer()
{
	attack = (rand() % damageValue) + 1;
	return attack;
}

int Critter::attackSanity()
{
	attack = (rand() % sanityAttack) + 1;
	return attack;
}