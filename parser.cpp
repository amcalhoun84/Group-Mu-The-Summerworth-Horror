#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "object.hpp"
#include "object.cpp"
#include "worldEngine.hpp"
#include "worldEngine.cpp"
#include "parser.hpp"


using namespace std;


Parser::Parser(string cmd)
{
	return cmd;
}

Parser::~Parser()
{
	// debugging purposes.
	cout << "Parse complete." << endl;
}

void Parser::interpretCommand(noun *nouns, word *verbs, string Command, string &word1, string &word2)
{
	srch = ' ';
	for(int i=0; i < Command.size(); i++)
	{
		if(Command.at(i) != ' ')
		{
			subString.insert(sub_str.end(), Command.at(i));
		}
		if(i == Command.size()-1)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
		if(Command.at(i) == srch)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
	}
}


void Parser::look(int roomID, room *rooms, word *dir, noun *nouns)
{
	cout << rooms[roomID].name << endl << endl;
	cout << rooms[roomID].description << endl << endl;

	for(int i = 0; i < DIRS; i++)
	{
		cout << "You can go to " << dir[i].word << " to " << rooms[rooms[roomID].exits_to_room[i].name << "." << endl;			
	}

	for(int i = 0; i < NOUNS; i++)
	{
		if(nouns[i].location == roomID)
		{
			cout << "You see " << nouns[i].name << "." << endl;
		}
	}
}


void Parser::viewInventory(vector<int> inventory)
{
	cout << "Here is what you are carrying: " << endl; 

	for(int i=0; i < inventory.size(); i++)
	{
			cout << inventory.at(i).name << endl;
		
	}
}

void Parser::use(int roomID, room *rooms, word *dir, noun *nouns)
{
	if(nouns[O_FLASHLIGHT].useState == false)
	{
		cout << "You turn on the flashlight" << endl;
		nouns[O_FLASHLIGHT].useState = true;
	}

	while(nouns[O_FLASHLIGHT].useState == true)
	{
		rooms[roomID].dark = false;
	}

	while(nouns[O_ROSE].useState == true)
	{
		cout << "The rose smells wonderful." << endl;

	}
}

bool Parser::parser(int &roomID, string word1, string word2, word *dir, word *verbs, room *rooms, noun *nouns)
{
	static bool door = false;
	for(int i = 0; i < DIRS; i++)
	{
		if(word1 == dir[i].word)
		{
			if(rooms[roomID.exits_to_room[dir[i].roomID] != NONE)
			{
				roomID = rms[roomID].exits_to_room[dir[i].roomID];
				cout << "You go to " << rooms[roomID].name << "." << endl;
				return true;
			}
			else
			{
				cout << "You cannot go that way." << endl;
			}
		}
	}

	int actionMatch = NONE, nounMatch = NONE;

	for(i=0; i < VERBS; i++)
	{
		if(word1 == verbs[i].word)
		{
			actionMatch = verbs[i].wordID;
			break;
		}
	}

	if(word2 != "")
	{
		for(int i=0; i < NOUNS; i++)
		{
			if(word2 == nouns[i].word)
			{
				nounMatch = nouns[i].objectID;
				break;
			}
		}
	}

	if(actionMatch == NONE)
	{
		cout << "Don't understand..." << endl;
		return true;
	}

	// look around

	if(actionMatch == V_LOOK || V_EXAMINE)
	{
		look(roomID, rooms, dir, nouns);
		return true;
	}

	// look at inventory

	if(actionMatch == V_INVENTORY)
	{
		viewInventory(inventory);
		return true;
	}

	if(actionMatch == V_DROP)
	{
		if(word2 == nouns[i].word)
		{
			for(int i=0; i < NOUNS; i++)
			{
				nouns[i].location == roomID;
				cout << "You have dropped: " << nouns[i].name << endl;
				return true;
			}

			else
			{
				cout << "You are not carrying anything like that." << endl;
			}
		}
		else
		{
			cout << "Drop what now?" << endl;
		}
	}

	// Get something
	if(actionMatch == V_TAKE)
	{
		if(word2 == nouns[i].word)
		{
			if(nouns[i].location == roomID)
			{
				if(nouns[i].canCarry == true)
				{
					inventory.push_back(nouns[i].itemID);
					cout << "You have picked up the " << nouns[i].name << endl;
					return true;
				}
				else
				{
					cout << "You can't pick that up." << endl;
				}
			}
			else
			{
				cout << "I don't see that here." << endl;
			}

		}
		else
		{
			cout << "Get what?" << endl;
		}
	}

}


bool Parser::addDefault(Object* def, string response)
{
	for(int i=0; i < cmd_default.size()-1; i++)
		if(cmd_defaults.at(i).object == def) return false;

	cmd_defaults.push_back(PlayerInput(def, response, DEFAULT);
		return true;
}

Object* Parser::findDefault(vector<string> &keywords, int& itemID, string& response);
{
	for(int i=0; i<cmd_default.size()-1; i++)
	{
		if(cmd_defaults.at(i).object->matchKeyword(keyword, itemID, type));
		return cmd_defaults.at(i).object;
	}

	return NULL;

}


bool Parser::matchKeywords(vector<string> first, vector<string> second)
{
	for(int i=0; i < first.size()-1; i++)
	{
		for(int j=0; j < second.size()-1; i++)
		{
			if(first[i] == second[j])
				return true;
		}
	}
	return false;
}

void Parser::executeResponse(string response, string object)
{
	replaceAllStr(response, "&o", object);

	if(response.at(0) == '@')
}