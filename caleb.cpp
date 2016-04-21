#include "caleb.hpp"
#include "creature.hpp"
#include "creature.cpp"

Caleb::Caleb()
{
	this->creatureName = "Caleb";
	this->creatureDescription = "You see Caleb Summerworth, the heir to the Summerworth Fortune. He is a man in his mid-twenties with sandy blonde hair, deep brown eyes, and a haunted look.";
	this->critterHealth = 40;
	this->alive = true;
	this->essential = true;
	this->invincible = false;
}

Caleb::~Caleb()
{
	cout << "Caleb's dead." << endl;
}

int Caleb::attackPlayerHP()
{

	attack = rand() % 9;

	switch(attack)
	{
		case 1:
			cout << creatureName << " throws a punch and grazes you." << endl;
			break;
		case 2:
			cout << creatureName << " throws a punch and lands pretty firmly." << endl;
			break;
		case 3:
		case 4:
			cout << creatureName << " gets a good kick on you." << endl;
			break;

		case 5:
		case 6:
			cout << creatureName << " slugs you square in the jaw. You see stars." << endl;
			break;

		case 7:
		case 8:
			cout << creatureName << " smacks you straight in your nose." << endl;
			break;
		default:
			cout << creatureName << " swings at you and misses." << endl;
			break;
	}

	return attack;
}

std::string Caleb::randomInsult()
{
	// return a randomized insult;
	return insults;
}

std::string Caleb::conversation(string cmd)
{
	// conversation tree; keywords from parser
}
