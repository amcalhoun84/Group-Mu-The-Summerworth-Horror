#include "../object.hpp"
#include "../object.cpp"
#include "ows.hpp"

using namespace std;

OWS::OWS()
{
    this->itemID = 104;  // All Creatures will have prefix 10_ as id.
    this->objName = "The One Who Sleeps";
    this->objDescription = "...it's form is impossible to comprehend, but you see a vaguely humanoid form with a third eye, glaring evilly at you.";
    this->shortDesc = "Myl'tharip'etk, The One Who Sleeps";
    this->health = 100;
    this->scoreValue = 0;
    this->alive = true;
    this->canCarry = false;
    this->invincible = true;
    this->indestructible = false;
    this->essential = false;

}

OWS::~OWS()
{
    cout << "You feel as if a great evil is removed from the world..." << endl;
}

void OWS::evilMonologue()
{
    cout << "Muahaha! I will rule the world!" << endl;
}

void OWS::insults()
{
    cout << "You cannot understand how small you really are..." << endl;
    cout << "Revel in your insignificance!" << endl;
}


int OWS::attackPlayer()
{
    attack = rand() % 10 + 1;
    cout << "You feel your grip on reality slipping..." << endl;
    sanityAttack = attackSanity();
        // sanity = player->getSanity();
        // sanity -= sanityAttack;
        // player->setSanity(sanity);

    return attack;
}

int OWS::attackSanity()
{
    sanityAttack = rand() % 10 + 1;
    return sanityAttack;
}