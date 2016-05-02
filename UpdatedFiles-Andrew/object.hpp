#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <ctime>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Object
{

protected:

    string objName;
    string objDescription;
    string shortDesc;

    int itemID;     // ID for the vector functions -- will be set for each object
    int scoreValue; // what is the score you get for collecting it?
    int health;     // how much damage can it take before it dies or breaks?
    // booleans

    bool alive;      // is it living or dead?
    bool canCarry;
    bool invincible; // For the One Who Sleeps Only
    bool indestructible; // Can't destroy the item -- only false for certain plot items.
    bool essential;

public:

    Object(); // generic constructor
    ~Object(); // Destructor

    // Setters
    void setName(string name) { this->objName = name; }
    void setDesc(string desc) { this->objDescription = desc; }
    void setShort(string sdesc) { this->shortDesc = sdesc; }

    void setHealth(int _health) { this->health = _health; }
    void setScoreValue(int score) { this->scoreValue = score; }

    void setAlive(bool live) { this->alive = live; }
    void setCanCarry(bool cCarry) { this->canCarry = cCarry; }
    void setInvincible(bool invinc) { this->invincible = invinc; }
    void setIndestructible(bool indest) { this->indestructible = indest; }
    void setEssential(bool essen) { this->essential = essen; }

    // Getters

    string getName() { return this->objName; }
    string getDesc() { return this->objDescription; }
    string getShort() { return this->shortDesc; }

    int getItemID() { return this->itemID; }
    int getHealth() { return this->health; }
    int getScore() { return this->scoreValue; }

    bool getAlive() { return this->alive; }
    bool getCanCarry() { return this->canCarry; }
    bool getInvincible() { return this->invincible; }
    bool getIndestructible() { return this->indestructible; }
    bool getEssential() { return this->essential; }

};


#endif // OBJECT_HPP
