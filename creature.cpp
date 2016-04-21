#include "creature.hpp"

Creature::Creature()
{
	srand(time(NULL));
	// this->creatureName = "Default Creature";
	// this->creatureDescription = "It's a creature. What do you expect?";
	// this->critterHealth = 10;
	// this->alive = true;
	// this->invincible = false; // only a special item can harm it -- FALSE

}

Creature::Creature(string _cName, string _cDescription)
{
	this->creatureName = _cName;
	this->creatureDescription = _cDescription;
	this->critterHealth = 10;
	this->alive = true;
	this->invincible = false; // only a special item can harm it -- FALSE 
}

Creature::~Creature()
{
	// cout << "Creature is being deleted.";
}

string Creature::getName()
{
	return creatureName;
}

string Creature::getDesc()
{
	return creatureDescription;
}

int Creature::attackPlayerHP()
{

	attack = 1;
	return attack;

}

Command* Creature::wanderAround()
{
	/*      N   
   NW 7__   8	__9 NE
		 \  |  /
	   	  \ | /
	W 4 --- O --- 6 E
	   	  / | \
   SW 1__/	|  \__3 SE
	  		2
	  		S
	DOWN = 0, UP = 10;

	*/

	wanderDirection = (rand() % 11);
	std::cout << creatureName << " is going: " << wanderDirection << std::endl;

	switch(wanderDirection)
	{
		case 0:
			// commandGo("d"); -- dummy direction function.
			break;
		case 1: 
			// commandGo("sw");
			break;
		case 2:
			// commandGo("s");
			break;
		case 3: 
			// commandGo("se")
			break;
		case 4:
			break;
		case 5: 
			break;
		case 6: 
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10: 
			break;

	}		
}

Command* Creature::flee()
{
	// critter flees if health is low or repelled?
}


void Creature::setStatus(bool _alive)
{
	alive = _alive;
}

bool Creature::getStatus()
{
	return alive;
}


void Creature::die()
{
	// remove the creature from the game world
}