#include "creature.hpp"
#include "onewhosleeps.hpp"
#include "creature.cpp"

OWS::OWS()
{
	this->creatureName = "The One Who Sleeps";
	this->creatureDescription = "A malevolent form stands before you, crackling electricity... it undulates strangely and its very presence threatens to rip your sanity to shreds. It does not seem to recognize your existence... yet.";
	this->health = 150;
	this->alive = true;
	this->essential = false;
	this->invincible = true;

}

OWS::~OWS()
{
	cout << "It explodes..." << endl;
}

int OWS::attackPlayerHP()
{

	attack = rand() % 12;

		if(attack >= 1 && < 4)
			std::cout << creatureName << "tries to break your mind." << std::endl;
		else if(attack >= 5 && < 8)
			std::cout << creatureName << " warps reality." << std::endl;
		
		else if(attack > 9)
			std::cout << creatureName << " gets a good kick on you." << std::endl;
		else
			std::cout << "Simply waits." << std::endl;

	}

	return attack;

void OWS::monologue()
{

}

void speaks()
{

}