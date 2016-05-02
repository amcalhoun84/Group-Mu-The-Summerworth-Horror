#ifndef ALFRED_HPP
#define ALFRED_HPP

#include "../object.hpp"

using namespace std;

class Alfred : public Object
{
private:

    string convo;
    string insult;
    int attack;
    int randomInsult;

    bool evidenceAlfred;
    bool accused;

public:

    Alfred();
    ~Alfred();

    void convoResponse(string& keyword);
    void fightInsult();
    int attackPlayer();


};

#endif // ALFRED_HPP
