#ifndef _WORLDENGINE_HPP
#define _WORLDENGINE_HPP

#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ncurses.h>
#include <iostream>
#include <fstream>


// These are currently placeholders, given that we don't know how many rooms are going
// to make it through, or objects.

#define GAMESIZE 64 // the number of rooms in the game;
#define OBJSIZE 30 // the number of objects in the game;

using namespace std;

class worldEngine
{

private:
    int choice;

    // On load, load in all of the rooms.
    //vector<Room> roomVector;

    // On load, load in all of the objects.
    //vector<Object> objectVector;


protected:

    bool gameOver;
    bool gameWon;
    bool mysterySolved;
    bool artifactFound;
    bool mysteryStarted;

    int moves;
    int score;
    vector<int> movesTaken;

    string gameName;

public:

    worldEngine();
    ~worldEngine();


    // play, load, save game
    void playGame();
    void newGame();
    void saveGame(string gameName);
    void loadGame(string gameName);

    // display what is happening in the game world.
     void display(int roomID, worldEngine wE);
     void manual();

     // quit the program

     void quitGame();

};



#endif // _WORLDENGINE_HPP
