#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../object.hpp"

using namespace std;

class Player : public Object
{
private:

	int moves;
	int score;
	int sanityPoints;
	vector<Object> inventory;

public:

	Player();
	~Player();

	void putInventory(Object object);

    int getScore() { return this->score; }
    int getMoves() { return this->moves; }
    void getInventory();
    void getRecord();

};





#endif // PLAYER_HPP
