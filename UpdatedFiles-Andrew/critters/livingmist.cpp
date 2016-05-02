#include "../object.hpp"
#include "../object.cpp"
#include "livingmist.hpp"

using namespace std;

LivingMist::LivingMist()
{
    this->itemID = 103;  // All Creatures will have prefix 10_ as id.
    this->objName = "Living Mist";
    this->objDescription = "Malevolent energy seems to whirl about in the mists...";
    this->shortDesc = "The Living Mist";
    this->health = 20;
    this->scoreValue = 0;
    this->alive = true;
    this->canCarry = false;
    this->invincible = true;
    this->indestructible = false;
    this->essential = false;

}

LivingMist::~LivingMist()
{
    cout << "The living mists temporarily part..." << endl;
}


int LivingMist::attackPlayer()
{
    attack = rand() % 4 + 1;
    cout << "You feel your grip on reality slipping..." << endl;
    sanityAttack = attackSanity();
        // sanity = player->getSanity();
        // sanity -= sanityAttack;
        // player->setSanity(sanity);

    return attack;
}

int LivingMist::attackSanity()
{
    sanityAttack = rand() % 8 + 1;
    return sanityAttack;
}