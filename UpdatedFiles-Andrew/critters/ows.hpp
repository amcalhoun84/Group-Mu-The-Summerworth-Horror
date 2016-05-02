#ifndef OWS_HPP
#define OWS_HPP


#include "../object.hpp"

using namespace std;

class OWS : public Object
{
private:

    int attack;
    int sanityAttack;

public:

    OWS();
    ~OWS();

    void evilMonologue();
    void insults();

    int attackPlayer();
    int attackSanity();

};
#endif // OWS_HPP
