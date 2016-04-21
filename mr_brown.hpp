#ifndef _MR_BROWN_HPP
#define _MR_BROWN_HPP

#include "creature.hpp"

class Mr_Brown : public Creature
{

private:

	std::string curse;
	std::string chants;
	std::string response;

	int sanity;

public:

	Mr_Brown();
	~Mr_Brown();
	std::string conversation(std::string cmd);
	std::string randomCurse();

	int attackPlayerHP();
	int sanityAttack();

};

#endif