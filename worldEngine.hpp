#ifndef _WORLDENGINE_HPP
#define _WORLDENGINE_HPP

#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cctype>

#include "room.hpp"
#include "object.hpp"
#include "parser.hpp"
#include "story.hpp"    // This is for the story mode. I plan to use this engine to make other interactive fiction.

// These are currently placeholders, given that we don't know how many rooms are going
// to make it through, or objects.

#define GAMESIZE 5 // the number of rooms in the game;
#define OBJSIZE 8// the number of objects in the game;
#define VERBS 8
#define NOUNS 8
#define MAXEQ 10
#define WTLIMIT 64  // player can carry up to 64 units of weight.

using namespace std;

struct CommandHash
{
    commandHash(string name);
        Parser* inputCmd;
        CommandHash* hashNext;
};

class WorldEngine
{

private:
    int choice;

    // On load, load in all of the rooms.
    //vector<Room> roomVector;

    // On load, load in all of the objects.
    //vector<Object> objectVector;

    string settings,
            responseFile,
            roomFiles,
            storyFile;

    string command,
            word_1,
            word_2;

protected:

    bool firstLaunch;
    bool gameOver;
    bool gameWon;
    bool mysterySolved;
    bool artifactFound;
    bool mysteryStarted;

    bool newline;

    int moves;
    int score;
    vector<int> movesTaken;

    string gameName;

    // accesses

    vector<string> gameKW; // game keywords
    vector<string> gamePreps; // Prepositions
    vector<Room*> roomVector // rooms are stored in this vector.
    vector<int> roomID;
    vector<Object*> objectVector // objects are stored in this vectot.
    vector<int> objectId;

    CommandHash commandsHash[CMD_HASH_SIZE]; // the hashmap
    vector<Parser> commands; // all commands

    vector<int> objs;   // room objects ... use objs.size() to count the number of objects.
    vector<int> invtry; // inventory    ... use

    int equipment[MAXEQ]; // array of equipped items.
    int variables[16];    // track the in game variables. Good for save games.

    // counters     -- Mainly for the Developers, will factor into player records.
    int roomCount,          // How many rooms have you visited
        responseCount,      // how many different responses there are in the game
        moveCount,          // count how many moves you've made.
        commandCount,       // count how many commands
        objectCount;        // how many objects are in the game.

    // room trackers
    int currentRoomId,
        startRoomID,
        vector<int> RoomMoves;


public:

    worldEngine(string settings, string responseFile, string roomFiles, string storyFile); // Constructor
    ~worldEngine(); // Destructor

    // Create the World on Initialization
    int loadSettings(string* settings);
    int loadResponses(string* responseFile);
    int loadRooms(string* roomFiles);   // this will load the room file directory...
    int loadStory(string* storyFile);

    void launch();  // Launch the game and/or story -- may cut.

    // play, load, save game
    void playGame();
    void newGame();
    void saveGame(string gameName);
    void loadGame(string gameName);

    // Interaction and Navigation
    int navigate(int roomID);
    void showInv();
    int handleRoom(string &dir, Room* room); // handle the room
    int handleCommand(string input, bool newline);
    // display what is happening in the game world.
     void display(int roomID, worldEngine wE);
     void manual();

     // quit the program

     // Access Members -- constant and never changing.
     string intro(int introStory) const;
     string standards(int response) const;
     Room* room(int roomID) const;
     int roomCurrent() const;
     Object* object(int itemID) const;
     int obj(int itemID) const;
     int inventory(int itemID) const;

     // do we have equipment? Might be a good thought...

     string prevCmd() const;
     Story* currentStory() const;

     bool quitGame();

};



#endif // _WORLDENGINE_HPP
