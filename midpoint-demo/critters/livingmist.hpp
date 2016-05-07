#ifndef LIVINGMIST_HPP
#define MRBROWN_HPP


#include "../object.hpp"

using namespace std;

class LivingMist : public Object
{
private:

    int attack;
    int sanityAttack;

public:

    LivingMist();
    ~LivingMist();

    int attackPlayer();
    int attackSanity();

};
#endif // LIVINGMIST_HPP
