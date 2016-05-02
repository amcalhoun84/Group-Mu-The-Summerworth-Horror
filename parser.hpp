#ifndef _PARSER_HPP
#define _PARSER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#include "worldEngine.hpp"
#include "worldEngine.cpp"
#include "object.hpp"
#include "room.hpp"
#include "player.hpp"


// The en_enumerators are demonstrations for the prototype. We hope to have a dictionary of words and synonyms to work from for the final project.

enum cmd_type { OBJECT = 0, CREATURE, NOTFOUND, NONE, DEFAULT };

enum en_VERBS { V_TAKE, V_ATTACK, V_DROP, V_USE, V_LOOK, V_INVENTORY, V_EXAMINE, V_HELP, V_TALK, V_QUIT };

// const int NOT = -1;


const int VERBS = 10;


class Object;

class Parser
{
private:

    struct words
    {
        string word;
        int wordID;

    };

   string subString;
   vector<string> words;


	struct PlayerInputObject
	{
		PlayerInput(Object* obj, string input, cmd_type cmd) : object(obj), response(r), type(t) {}
		Object* object;
		string response;
		bool living;
		cmd_type ct;	// command cmd_type

	};

	string verb;
	string noun;

	// auxilliary, optional.
	string auxnoun;
	string preposition;
	char srch;

	string command;
	vector<PlayerInput> cmd_objects;
	vector<PlayerInput> cmd_default;

public:

	Parser(string command);
	~Parser();
	void interpretCommand(noun *nouns, word *verbs, string Command, string &word1, string &word2);
    void setVerbs(word *verbs);


    void look(int roomID, room *rooms, word *dir, noun *nouns);
    void take(int roomID, room *rooms, word *dir, noun *nouns);
    void drop(int roomID, room *rooms, word *dir, noun *nouns);
    void viewInventory(int roomID, room *rooms, word *dir, noun *nouns);
    void use(int roomID, room *rooms, word *dir, noun *nouns);
    void talk(int roomID, room *rooms, word *dir, noun *nouns);
    void attack(int roomID, room *rooms, word *dir, noun *nouns);
    void help(int roomID, room *rooms, word *dir, noun *nouns);

    void quit();

    bool parser(int &roomID, string word1, string word2, word *dir, word verbs, room *rooms, noun *nouns);



};

#endif // PARSER
