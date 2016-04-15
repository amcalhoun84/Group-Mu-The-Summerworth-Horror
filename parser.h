// Parser.h

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

enum command_type
{
	OBJECT, CREATURE, NOTFOUND, DEFAULT, NONE
};

class Object;
class Creature;

class Command
{
public: 
	Command(std::string commands) {}
	~Command() {}

    Object* findDefault(std::vector<string> &keywords, int& index, std::string& response);
    Object* findSpecial(string& response, command_type c_type); // strings need pointers and addressing.
    Creature* findDefault(std::vector<string> &keywords, int& index, std::string& response);
    
    int findItems(std::vector<string> &keywords, std::vector<int> &idVector, std::vector<Object*> results, std::vector<Object*> resultResponses);
    int findItems(std::vector<string> &keywords, std::vector<int> &idVector, std::vector<Creature*> results, std::vector<Object*> resultResponses);

	bool addItem();
	bool removeItem();
    string command() const { return cmd; }

private:
	struct CommandHash
	{
        CommandHash(Item* i, std::string r, command_type c_type : item(i), response(r), type(t)) {}
        Item* item;
        string response;
        command_type c_type;

	};

	string commands;
	vector<CommandHash> items;
	vector<CommandHash> creatures;
	vector<CommandHash> defaults;


};

#endif