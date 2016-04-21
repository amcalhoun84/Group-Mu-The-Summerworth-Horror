#ifndef _ALFRED_HPP
#define _ALFRED_HPP

#include "creature.hpp"
#include "creature.cpp"

class Alfred : public Creature
{

private:
	string insult;
	string response;

public:

	Alfred();
	~Alfred();
	int attackPlayerHP();
	string conversation(string cmd);
	string randomInsult();

};

#endif