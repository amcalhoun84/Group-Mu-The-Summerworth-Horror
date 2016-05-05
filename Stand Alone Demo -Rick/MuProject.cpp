// MuProject.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include<string>
#include <iostream>
#include<sstream>
#include <vector>
#include "room.h"

using namespace std;

//Thanks for the helper function Andrew
string toUpperStr(string buffer)
{
	for (int i = 0; i<buffer.size(); i++)
		buffer.at(i) = toupper(buffer.at(i));
	return buffer;
}

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
string getItem(string item)
{
	string object = item;
	/*vector<string>roomInventory{ "flashlight","book","note","knife" };
	vector<string>::iterator iter;*/
	return object;
}
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
		filter = 100; //All 100 filters will be functions called from room objects, later player (200) and creature(300) filters will be added
	}
	else
	{
		cout << "That is an invalid command. Try again" << endl;
		return -1;
	}
	com = commands[1];
	if (filter == 100)
	{
		if (com == "NORTH")
		{
			filter = 101;
		}
		else if (com == "SOUTH")
		{
			filter = 102;
		}
		else if (com == "EAST")
		{
			filter = 103;
		}
		else if (com == "WEST")
		{
			filter = 104;
		}
	}
	return filter;
}

void callFunction(vector <Room> &roomStorage, Room &room, int filter)
{
	int id;
	switch (filter)
	{
		case 101:		
			id = room.getNorth();
			if (id == -1)
			{
				cout << "You can't go north. Try another command" << endl;
				break;
			}
			for (int i = 0; i < roomStorage.size(); i++)
			{
				if (roomStorage[i].getRoomId() == id)
				{
					room = roomStorage[i];
				}
			}
			room.displayName();
			room.displayDesc();
			break;
		case 102:		
			id = room.getSouth();
			if (id == -1)
			{
				cout << "You can't go south. Try another command" << endl;
				break;
			}
			for (int i = 0; i < roomStorage.size(); i++)
			{
				if (roomStorage[i].getRoomId() == id)
				{
					room = roomStorage[i];
				}
			}
			room.displayName();
			room.displayDesc();
			break;
		case 103:		
			id = room.getEast();
			if (id == -1)
			{
				cout << "You can't go east. Try another command" << endl;
				break;
			}
			for (int i = 0; i < roomStorage.size(); i++)
			{
				if (roomStorage[i].getRoomId() == id)
				{
					room = roomStorage[i];
				}
			}
			room.displayName();
			room.displayDesc();
			break;
		case 104:		
			id = room.getWest();
			if (id == -1)
			{
				cout << "You can't go west. Try another command" << endl;
				break;
			}
			for (int i = 0; i < roomStorage.size(); i++)
			{
				if (roomStorage[i].getRoomId() == id)
				{
					room = roomStorage[i];
				}
			}
			room.displayName();
			room.displayDesc();
			break;
	}
}


int main()
{
	Room room;
	vector<Room> roomStorage;

	//sample room created by constructor - Room(string name, string roomDescription, int id, int north, int south, int east, int west, bool indoor, bool dark)
	Room room1 = Room("Room1", "Kitchen", 1, 2, -1, -1, -1, true, false);  //-1 indicates that the player can't go that direction
	Room room2 = Room("Room2", "Living Room", 2, 3, 1, -1, -1, true, false);
	Room room3 = Room("Room3", "Hall", 3, 4, 2, -1, -1, true, false);
	Room room4 = Room("Room4", "Library", 4, 5, 3, -1, -1, true, false);
	Room room5 = Room("Room5", "Billiard Room", 5, -1, 4, -1, -1, true, false);

	room1.addItem(1);
	room1.addItem(2);
	room2.addItem(5);
	room2.addItem(6);
	room3.addItem(7);
	room3.addItem(8);
	room4.addItem(9);
	room4.addItem(10);
	room5.addItem(11);
	room5.addItem(12);

	roomStorage.push_back(room1);
	roomStorage.push_back(room2);
	roomStorage.push_back(room3);
	roomStorage.push_back(room4);
	roomStorage.push_back(room5);
	
	room = roomStorage[0];
	room.displayName();
	room.displayDesc();

	bool gameOver = false;
	string input;
	int filter;

	while (!gameOver)
	{
		
		input = getPlayerInput();
		if (input == "QUIT")
		{
			gameOver = true;
		}
		else
		{
			filter = parseCommand(input);
			if (filter != -1)
			{
				callFunction(roomStorage, room, filter);
			}			
		}
		
	}
		
	return 0;
}

