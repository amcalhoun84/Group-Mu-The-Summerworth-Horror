#include "../object.hpp"
#include "../object.cpp"
#include "caleb.hpp"

using namespace std;

Caleb::Caleb()
{
    this->itemID = 101;  // All Creatures will have prefix 10_ as id.
    this->objName = "Caleb";
    this->objDescription = "The scion of the Summerworth Family is a classic example of the New England Brahmin class. He is tall, well muscled, with sandy blonde hair. He has a look of horror in his stormy blue eyes.";
    this->shortDesc = "Caleb Summerworth";
    this->health = 80;
    this->scoreValue = 0;
    this->alive = true;
    this->canCarry = false;
    this->invincible = false;
    this->indestructible = false;
    this->essential = true;

    // story tropes
    this->evidenceCaleb = false;
    this->accused = false;

}

Caleb::~Caleb()
{
    cout << "Caleb howls in agony as he dies." << endl;
}

void Caleb::convoResponse(string &keyword)
{
   if(keyword == "paul" || keyword == "abigail" || keyword == "summerworth" || keyword == "summerworths" || keyword == "murder" || keyword == "murders" || keyword == "death" || keyword == "deaths" || keyword == "parents")
   {
        cout << "Caleb looks ready to break down into tears, \'I can't believe anyone could kill Mommy and Dad. They were such generous, kind people...\'" << endl;
        cout << "\'If you really want my guess about who did it, it was probably Mr. Brown, the Valet.\'" << endl;
    }

    else if(keyword == "amulet" || keyword == "necklace" || keyword == "symbol")
    {
        cout << "\'Yea, I bought that when I was slumming around Ireland last summer.\'" << endl;
        cout << "\'I thought it looked interesting and wanted to keep it as a memento.\'" << endl;
    }

    else if(keyword == "dagger" || keyword == "knife") cout << "He looks away for a moment, \'Yea, I collect knives. I should have kept it locked up more tightly, I guess.\'" << endl;
    else if(keyword == "bedroom" || keyword == "scene")
         cout << "\'I came home to find out my parents were murdered. I wasn't around when it happened.\'" << endl;

    else if(keyword == "St. Moritz" || keyword == "tickets" || keyword == "passport" || keyword == "trip")
        cout << "\'I was planning to go on a ski-trip after Thanksgiving, sure... what does that have to do with any of this?\'" << endl;

    else if(keyword ==  "accuse")
    {
            // Caleb->accused = true;
            cout << "You accused me...";
            // if evidence not sufficient -- insults player
            // attack player if enough evidence
    }
    else
    {
        cout << "Wish I could help about " << keyword << "." << endl;
    }
}

void Caleb::fightInsult()
{
    randomInsult = rand() % 3 + 1;

    if(randomInsult == 1)
    {
        cout << "You couldn't leave well enough alone!" << endl;
    }
    
    if(randomInsult == 2)
    {
        cout << "The fortune was supposed to be mine in exchange for their lives!" << endl;
    }

    if(randomInsult == 3)
    {
        cout << "I'll kill you!" << endl;
    }

}

int Caleb::attackPlayer()
{
    attack = rand() % 8 + 1;
    return attack;
}

