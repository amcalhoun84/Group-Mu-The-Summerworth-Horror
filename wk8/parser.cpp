#include<string>
#include <iostream>
#include<sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "parser.h"
#include "room.h"
#include "helper.h"
#include "player.h"
#include "item.h"

using namespace std;



string getPlayerInput()
{
	vector<string> commands;
	string item;
	string input;
	int len = 0;

	while (len != 2)
	{
		cout << "Please enter a 2 word command (Verb + Noun): ";
		getline(cin, input);
		input = toUpperStr(input);
		stringstream ss(input);

		while (ss >> item)
		{
			commands.push_back(item);
		}
		len = commands.size();
		if (len != 2)
		{
			if (commands[0] == "QUIT")
			{
				return input;
			}
			cout << "You entered a " << len << " word command. Please enter a 2 word command" << endl;
			commands.clear();
		}
	}
	return input;
}

//It is assumed that the string passed to this function is a 2 word command(with the exception of "QUIT"). The string returned from
//getPlayerInput() would provide a string like this
int parseCommand(string command)
{
	vector<string> commands;
	string com;
	stringstream ss(command);
	int filter;

	while (ss >> com)
	{
		commands.push_back(com);
	}

	com = commands[0];
	if (com == "MOVE" || com == "GO")
	{
		filter = 1; 
	}
	else if (com == "GET")
	{
		filter = 2;
	}
	else if (com == "QUIT")
	{
		filter = 9999;
	}
	else
	{
		cout << "That is an invalid command. Try again" << endl;
		return -1;
	}
	
	return filter;
}

bool callFunction(vector <Room> roomStorage,vector <Item> itemStorage, Room &room, Player &player, int filter,string command)
{
	int id;
	vector<string> commands;
	string com;
	string com1;
	string com2;
	stringstream ss(command);
	bool gameOver;
	
	while (ss >> com)
	{
		commands.push_back(com);
	}

	com1 = commands[0];
	//Basically, if input is not "QUIT", it should be a 2 word command
	if (filter != 9999)
	{
		com2 = commands[1];
	}
			
	switch (filter)
	{
	case -1: 
		gameOver = false;
		break;
	case 1:
		if (com2 == "NORTH")
		{
			id = room.getNorth();
			if (id == -1)
			{
				cout << "You can't " << com1 << " north. Try another command" << endl;
				gameOver = false;
				break;
			}
			else
			{
				displayRoom(roomStorage, room, id);
				gameOver = false;
				break;
			}
		}
		else if (com2 == "SOUTH")
		{
			id = room.getSouth();
			if (id == -1)
			{
				cout << "You can't " << com1 << " south. Try another command" << endl;
				gameOver = false;
				break;
			}
			else
			{
				displayRoom(roomStorage, room, id);
				gameOver = false;
				break;
			}
		}
		else if (com2 == "EAST")
		{
			id = room.getEast();
			if (id == -1)
			{
				cout << "You can't " << com1 << " east. Try another command" << endl;
				gameOver = false;
				break;
			}
			else
			{
				displayRoom(roomStorage, room, id);
				gameOver = false;
				break;
			}
		}
		else if (com2 == "WEST")
		{
			id = room.getWest();
			if (id == -1)
			{
				cout << "You can't " << com1 << " west. Try another command" << endl;
				gameOver = false;
				break;
			}
			else
			{
				displayRoom(roomStorage, room, id);
				gameOver = false;
				break;
			}
		}
		else
		{
			cout << "I don't understand where you want to " << com1 << "." << endl;
			gameOver = false;
			break;
		}
	case 2:
		if (com2 == "INVENTORY")
		{
			player.getInventory(itemStorage);
			gameOver = false;
			break;
		}
		else
		{
			cout << "I don't know what you what to " << com1 << endl;
			gameOver = false;
			break;
		}
	case 9999:
		gameOver = quit();
		break;
	default:
		gameOver = false;
		break;
	}
	return gameOver;
}

void displayRoom(vector<Room> roomStorage, Room &room, int id)
{
	for (int i = 0; i < roomStorage.size(); i++)
	{
		if (roomStorage[i].getRoomId() == id)
		{
			room = roomStorage[i];
		}
	}
	room.displayName();
	room.displayDesc();
}

bool quit() 
{
	int randomTaunt;
	string input;
	bool result;

	srand(time(NULL));
	randomTaunt = rand() % 6 + 1;

	switch (randomTaunt)
	{
	case 1:
		cout << "Cowardice does not become you. ";
		break;

	case 2:
		cout << "Scared of the dark, are we? ";
		break;

	case 3:
		cout << "Thou wish to quit? Thou hath lost an eigth! "; // Ultima reference
		break;

	case 4:
		cout << "Oh, so now you want to work... ";
		break;

	case 5:
		cout << "Don't worry. You'll come crawling back. ";
		break;

	case 6:
		cout << "Why would you want to quit this great game? ";
		break;

	default:
		cout << "My writer got bored and forgot to include a taunt here... ";
		break;
	}
	bool invalid = true;
	while (invalid)
	{
		cout << "Do you really want to quit? Please enter Y or N:";
		getline(cin, input);
		input = toUpperStr(input);
		if (input.at(0) == 'Y')
		{
			cout << "You'll be back..." << endl;
			invalid = false;
			result = true;
		}
		else if (input.at(0) == 'N')
		{
			cout << "I knew you didn't really want to quit..." << endl;
			invalid = false;
			result = false;
		}
		else
		{
			cout << "Please enter something that at least starts with y or n!" << endl;
		}

	}
	return result;
}