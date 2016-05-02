#include "../object.hpp"
#include "../object.cpp"
#include "alfred.hpp"

using namespace std;

Alfred::Alfred()
{
	this->itemID = 100;  // All Creatures will have prefix 10_ as id.
	this->objName = "Alfred";
	this->objDescription = "You see a healthy, well-built, but weathered man in his early to mid forties. His brown hair is thick, wavy, with more than a touch of grey around the temples and his green eyes are marked with mirth lines from a life time of fulfilling work. He wears sturdy coveralls, workman's gloves, and has a number of tools on his belt, including a very sharp looking pair of shears.";
	this->shortDesc = "Alfred the Gardner";
	this->health = 60;
	this->scoreValue = 0;
	this->alive = true;
	this->canCarry = false;
	this->invincible = false;
	this->indestructible = false;
	this->essential = true;

	// story tropes
	this->evidenceAlfred = false;
	this->accused = false;

}

Alfred::~Alfred()
{
	cout << "Alfred crumples into a heap." << endl;
}

void Alfred::convoResponse(string &keyword)
{
	if(keyword == "paul" || keyword == "abigail" || keyword == "death" || keyword == "deaths" || keyword == "murder" || keyword == "murders")
	{
		
		cout << "\'That's a shame. They were good employers. Loved the grounds, estate, and their children. I don't think I'll ever find a pair as nice as those two. They even let me stay here, rent-free, with a generous stipend. It's helped put my daughter through school.\'" << endl;
		cout << "He shakes his head. \'I don't know why anyone would do something like that... and so gruesomely too!\'" << endl;
	
	}

	else if(keyword == "coveralls" || keyword == "overalls" || keyword == "bloody" || keyword == "clothes")
	{
		if(evidenceAlfred == false && accused == false)
		{
			cout << "Giving a slight chuckle, shaking his head, he holds up his hand and removes his glove, showing a nasty gash." << endl;
			cout << "\'Hazards of the job, I guess. I was pruning the prized blue roses and I wasn't paying attention to where I put my shears. Cut myself good.\'";
		}
		else if(evidenceAlfred == true && accused == false)
		{
			cout << "\'Look, I was the one who found the bodies, so of course it\'s going to look like I did it.\' Alfred, shakes his head." << endl;
		}
		else 
		{
			cout << "\'So, you figured out my involvement... well then... I'm going to have to fix that." << endl;
			// attacks player;
		}
	}
	
	else if(keyword == "bedroom" || keyword == "scene")
	{
		cout << "\'I heard screaming, so I went upstairs to investigate.\'" << endl;
	}
	

	else if(keyword == "accuse")
	{ 
		// Alfred->accused = true;
		cout << "You accused me...";
		// if evidence not succifcient -- insults player
		//else attacks player
	}

	else
	{
			cout << "I'm sorry, I don't know anything about that." << endl;
	}
}

void Alfred::fightInsult()
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

int Alfred::attackPlayer()
{
	attack = rand() % 10 + 1;
	return attack;
}

