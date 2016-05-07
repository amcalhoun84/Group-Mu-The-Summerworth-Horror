#ifndef CALEB_HPP
#define CALEB_HPP


#include "../object.hpp"

using namespace std;

class Caleb : public Object
{
private:

    string convo;
    string insult;
    int attack;
    int randomInsult;

    bool evidenceCaleb;
    bool accused;

public:

    Caleb();
    ~Caleb();

    void convoResponse(string& keyword);
    void fightInsult();
    int attackPlayer();





};
#endif // CALEB_HPP
