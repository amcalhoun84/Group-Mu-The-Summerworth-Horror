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

bool Parser::isAlive(Object *obj, string response)
{
	for(int i, i < cmd_objects.size()-1; i++)
	{
		if(cmd_objects.at(i).living == true) 
		{
			cmd_type ct = 1;
			isCreature(obj, response, ct);
			return true;
		}
		else
		{
			addObject(obj, response, ct);
			return false;
		}

	}
}


bool Parser::addObject(Object *obj, string response, cmd_type ct)
{
	for(int i=0; i < cmd_objects.size()-1; i++)
	{
		if(cmd_objects.at(i).object = object) return false;
	}

	cmd_objects.push_back(PlayerInput(object, response, type);
	return true;
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

void