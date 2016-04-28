#ifndef _LIVINGMIST_HPP
#define _LIVINGMIST_HPP

#include "creature.hpp"

class LivingMist : public creature
{

private: 
	string randomScare;

public:
	LivingMist();
	~LivingMist();
	int MistAttack();
	int MistInsanity();

};


#endif