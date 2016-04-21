#ifndef _CALEB_HPP
#define _CALEB_HPP

#include "creature.hpp"

class Caleb : public Creature
{

private:
	string insults;
	string response;

public:
	Caleb();
	~Caleb();
	std::string conversation(string cmd);
	std::string randomInsult();
	int attackPlayerHP();
	
};

#endif