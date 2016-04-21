#ifndef _OWS_HPP
#define _OWS_HPP

#include "creature.hpp"

class OWS :: public Creature
{
private:
	string monologue;
	string horror;

public:
	int attackPlayerHP();
	int sanityAttack();
};


#endif