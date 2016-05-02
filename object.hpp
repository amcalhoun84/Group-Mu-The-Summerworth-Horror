#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "worldEngine.hpp"

using namespace std;

enum en_OBJECTS { O_DOOR, O_FLASHLIGHT, O_ROSE, O_PAMPHLET, O_GUN, O_KEY, O_CALEB, O_ALFRED, O_BROWN };

const int OBJECTS = 9;


class Object
{
protected:

     struct noun
    {

      int objectID;
      int location; // eventually change and make with room IDs
      int weight;
      string word;
      string description;
      string longDesc;

      bool can_pickup,
            usable,
            useState,
            canConversate,
            convState,
            indestructable,
            invincible;

    };

public:
    void setNouns(noun *nouns);


};


#endif
