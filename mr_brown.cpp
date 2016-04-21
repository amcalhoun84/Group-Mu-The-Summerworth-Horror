#include "mr_brown.hpp"
#include "creature.hpp"
#include "creature.cpp"

Mr_Brown::Mr_Brown()
{
	this->creatureName = "Mr. Brown";
	this->creatureDescription = "The valet of the Summerworth family. A middle aged gentleman...";
	this->critterHealth = 45;
	this->alive = true;
	this->essential = true;
	this->invincible = false;

}

Mr_Brown::~Mr_Brown()
{
	std::cout << "Mr. Brown is dead." << std::endl;

}

int Mr_Brown::attackPlayerHP()
{

	attack = rand() % 7;

	switch(attack)
	{
		case 1:
			std::cout << creatureName << "'s stiletto grazes you." << std::endl;
			break;
		case 2:
			std::cout << creatureName << " gets good slice on you." << std::endl;
		
		case 3:
		case 4:
			std::cout << creatureName << " gets a good kick on you." << std::endl;
			break;

		case 5:
			std::cout << creatureName << " stabs you with great force." << std::endl;
			break;

		case 6:
			std::cout << creatureName << " slices you nastily across the face." << std::endl;
			break;
		default:
			std::cout << creatureName << " swings at you and misses." << std::endl;
			break;
	}

	if(attack == 6)
	{
		sanity = sanityAttack();
	//	setPlayerSanity(totalSanity);
	}

	return attack;
}

int Mr_Brown::sanityAttack()
{
	sanity = (rand() % 3) + 1;

	int totalSanity = // getPlayerSanity();
	totalSanity -= sanity;

	return totalSanity;
	
}

std::string conversation(std::string cmd) {}

std::string randomCurse() {}

