#include "alfred.hpp"

Alfred::Alfred()
{
	this->creatureName = "Alfred the Gardner";
	this->creatureDescription = "A sun-weathered man in his late 40s.";
	this->critterHealth = 60;
	this->essential = true;
	this->alive = true;
	this->invincible = false;
}

Alfred::~Alfred()
{
	cout << "Zed's death baby... Zed's dead.";
}

int Alfred::attackPlayerHP()
{

	attack = rand() % 11;

	switch(attack)
	{
		case 1:
		case 2:
			cout << this->creatureName << " throws a punch and grazes you." << endl;
			break;
		case 3:
		case 4:
			cout << this->creatureName << " throws a punch and lands pretty firmly." << endl;
			break;
		case 5:
		case 6:
			cout << this->creatureName << " gets a good kick on you." << endl;
			break;

		case 7:
		case 8:
			cout << this->creatureName << " slugs you square in the jaw. You see stars." << endl;
			break;

		case 9:
		case 10:
			cout << this->creatureName << " smacks you straight in your nose." << endl;
			break;
		default:
			cout << this->creatureName << " swings at you and misses." << endl;
			break;
	}

	return attack;
}

std::string Alfred::randomInsult()
{
	return insult;
}

std::string Alfred::conversation(string cmd)
{
	// conversation tree; keywords from parser
}
