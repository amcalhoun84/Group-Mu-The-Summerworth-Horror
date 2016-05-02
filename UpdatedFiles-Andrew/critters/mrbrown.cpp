#include "../object.hpp"
#include "../object.cpp"
#include "mrbrown.hpp"

using namespace std;

MrBrown::MrBrown()
{
	this->itemID = 102;  // All Creatures will have prefix 10_ as id.
	this->objName = "Mr. Brown";
	this->objDescription = "A refined gentleman of late middle age, his hair has gracefully faded from gray to near white. His brown eyes hold a certain hardness...";
	this->shortDesc = "Alosius Brown, the Valet";
	this->health = 60;
	this->scoreValue = 0;
	this->alive = true;
	this->canCarry = false;
	this->invincible = false;
	this->indestructible = false;
	this->essential = true;

	// story tropes
	this->evidenceMrBrown = false;
	this->accused = false;

}

MrBrown::~MrBrown()
{
	cout << "Mr. Brown disintegrates to ash." << endl;
}

void MrBrown::convoResponse(string &keyword)
{
	if(keyword == "paul" || keyword == "abigail" || keyword == "death" || keyword == "deaths" || keyword == "murder" || keyword == "murders")
	{
		
		cout << "\'Good employers. Mr. Summerworth was a very kind man... He treated his servants and assistants like family.\'" << endl;
		cout << "\'He did make some powerful enemies though... it really is no surprise that someone did this. To me at least.\'" << endl;
	
	}

	else if(keyword == "robe" || keyword == "robes" || keyword == "bloody" || keyword == "clothes")
	{
		if(evidenceMrBrown == false && accused == false)
		{
			
		}
		else if(evidenceMrBrown == true && accused == false)
		{
			cout << "\'I was woken from my slumber by the murder... I was overwrought with grief.\'" << endl;
		}
		else 
		{
			cout << "\'You will make a fine sacrifice...\'" << endl;
			// attacks player;
		}
	}
	
	else if(keyword == "bedroom" || keyword == "scene")
	{
		cout << "\'I heard screaming, so I went to investigate the bedroom. Alfred was already there...\'" << endl;
	}
	

	else if(keyword == "accuse")
	{ 
		// MrBrown->accused = true;
		cout << "You accused me...";
		// if evidence not succifcient -- insults player
		//else attacks player
	}

	else
	{
			cout << "I'm sorry, I don't know anything about that." << endl;
	}
}

void MrBrown::fightInsult()
{
	randomInsult = rand() % 3 + 1;

	if(randomInsult == 1)
	{
		cout << "I'll use your bones to build an altar to the Sleeping One!" << endl;
	}
	
	if(randomInsult == 2)
	{
		cout << "You have meddled in things beyond your comprehension!" << endl;
	}

	if(randomInsult == 3)
	{
		cout << "Die, wretch!" << endl;
	}

}

int MrBrown::attackPlayer()
{
	attack = rand() % 6 + 1;
	if(attack >= 5)
	{
		cout << "You feel your connection to reality slipping." << endl;
		sanityAttack = attackSanity();
		// sanity = player->getSanity();
		// sanity -= sanityAttack;
		// player->setSanity(sanity);
	}

	return attack;
}

int MrBrown::attackSanity()
{
	sanityAttack = rand() % 3 + 1;
	return sanityAttack;
}