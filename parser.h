// Parser.h

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

enum command_type
{
	OBJECT, NOTFOUND, DEFAULT, NONE
};

class Command
{
public: 
	Command(std::string commands) {}
	~Command() {}

	Object* findDefault(std::vector<string> &keywords, int& index, std::string& response)
	Object* 
	Creature findDefault()

	bool addItem();
	bool removeItem();

private:
	struct CommandHash
	{

	};

	string commands;
	vector<CommandHash> items;
	vector<CommandHash> creatures;
	vector<CommandHash> defaults;


};

#endif