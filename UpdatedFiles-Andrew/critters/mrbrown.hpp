#ifndef MRBROWN_HPP
#define MRBROWN_HPP


#include "../object.hpp"

using namespace std;

class MrBrown : public Object
{
private:

    string convo;
    string insult;
    int attack;
    int sanityAttack;
    int randomInsult;

    bool evidenceMrBrown;
    bool accused;

public:

    MrBrown();
    ~MrBrown();

    void convoResponse(string& keyword);
    void fightInsult();
    int attackPlayer();
    int attackSanity();

};
#endif // MRBROWN_HPP
