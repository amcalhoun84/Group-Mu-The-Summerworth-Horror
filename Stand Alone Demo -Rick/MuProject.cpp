// MuProject.cpp : Defines the entry point for the console application.
//


#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "object.hpp"
#include "object.cpp"
#include "room.hpp"
#include "room.cpp"
#include "graphics.cpp"
//#include "./items/*.hpp"
//#include "./critters/*.hpp"

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
		stringstream ss(input);
	
		while (ss >> item)
		{
			commands.push_back(item);
		}
		len = commands.size();
		if (len != 2)
		{
			if (commands[0] == "quit")
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
	if (com == "move" || com == "go")
	{
		filter = 100;
	}
	else
	{
		cout << "That is an invalid command. Try again" << endl;
		return -1;
	}
	com = commands[1];
	if (filter == 100)
	{
		if (com == "north")
		{
			filter = 101;
		}
		else if (com == "south")
		{
			filter = 102;
		}
		else if (com == "east")
		{
			filter = 103;
		}
		else if (com == "west")
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

	Graphics g;

	g.splashScreen();

	cout << "Presents: The Summerworth Horror - project mu demo." << endl;

	srand(time(NULL));
	Room room;
	vector<Room> roomStorage;

	// Rooms are currently hard-coded to keep the secrecy of the game intact,
	// while the primary example of this demo is to show that the engine is
	// functional and basic actions can be done.

	Room room1 = Room("Room1", "Kitchen", 1, 2, -1, -1, -1, true, false);
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
		if (input == "quit")
		{
			int randomTaunt;
			char yesNo;
			randomTaunt = rand() % 6;

			cout <<"Are you sure you want to quit? ";

			while(yesNo != 'N' && yesNo != 'n' && yesNo != 'Y' && yesNo != 'y')
			{
				switch(randomTaunt)
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

				cout << "(y/n): ";
				cin >> yesNo;


				if(yesNo == 'y') 
				{
					gameOver = true;
					cout << "...you'll be back." << endl;
				}
				else if(yesNo == 'n') 
				{
					gameOver = false;
					cout << endl;
				}
				else 
				{
					cout << "(y/n) only..." << endl;
				}
			}

			cin.ignore();

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