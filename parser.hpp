#ifndef _PARSER_HPP
#define _PARSER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#include "worldEngine.hpp";
#include "worldEngine.cpp";

enum cmd_type {
	OBJECT = 0, CREATURE, NOTFOUND, NONE, DEFAULT;

};

class Object;

class Parser
{
private: 

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

	string command;
	vector<PlayerInput> cmd_objects;
	vector<PlayerInput> cmd_default;

public:

	Parser(string command);
	~Parser();
	void interpretCommand(string command);

	Object* findDefault(vector<string> &keywords, int& itemID, string &response);
	Object* findSpecial(vector<string> &keywords, cmd_type ct);
	int findObject(vector <string> &keywords, vector<int> &objID, vector<Object*> &result, vector<string> &response);

	bool addObject(Object* obj, string response, cmd_type ct = OBJECT);
	bool addDefault(Object* def, string response);
	bool isAlive(Object *obj);

	bool isCreature(Object *obj, string response, cmd_type ct = CREATURE);

	int matchKeywords(string inputcmd, Game* game);


};

#endif // PARSER