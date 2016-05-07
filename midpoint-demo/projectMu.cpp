// MuProject.cpp : Defines the entry point for the console application.
//


#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "projectMu-includes.hpp"
#include "object.hpp"
#include "object.cpp"
#include "room.hpp"
#include "room.cpp"
#include "graphics.cpp"

using namespace std;

// Globals for now; not standard practice, but for testing purposes.

	Player player;

	Object object1;
	Armoire armoire;
	BigDoor bigDoor;
	BloodyPamphlet bPhm;
	BloodyRobe blRobe;
	BloodyRope blRope;
	BlueRose bRose;
	BowieKnife bKnife;
	CaseDossier cDossier;
	Desk desk;
	Flashlight flLight;

// End Globals

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
	
	else if(com == "kick" || com == "hit")
	{
		filter = 110;
		cout << "You stub your toe kicking that." << endl;
		cout << "Swinging madly at the air isn't going to accomplish much." << endl;
	}

	else if(com == "eat" || com == "consume" || com == "nosh")
	{
		filter = 111;
		cout << "It would taste really good... if you would tell me what it was you wanted to eat." << endl;
	}
	else if(com == "shoot")
	{
		filter = 112;
		cout << "You fire bullets into the darkness!" << endl;
	}

	else if(com == "get")
	{
		filter = 113;
	}

	else if(com == "inventory")
	{
		filter = 114;
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

	else if(filter == 113)
	{

		// We will search for the item, if it matches, we can pick it up unless
		// we can't carry it. We will integrate this soon, but we needed to do something
		// to demonstrate the inventory. Right now, if it exists in the keywords below, 
		// it will be put in your inventory.

		/*
			for(int i=0; i<roomItems.size(); i++)
			{
				if(roomItems.at(i) == com[1])
				{
					// add to player inventory.
				}
			}

			*/

		if(com == "armoire")
		{
			
			cout << "It's too heavy." << endl;
		}
		else if(com == "flashlight")
		{
			player.putInventory(flLight);
			cout << "You pick up the flashlight." << endl;
		}
		else if(com == "rose")
		{
			player.putInventory(bRose);
			cout << "You pick up the blue rose." << endl;
		}
		else if(com == "knife")
		{
			player.putInventory(bKnife);
			cout << "You pick up the bowie knife." << endl;
		}

		else if(com == "pamphlet")
		{
			player.putInventory(bPhm);
			cout << "You pick up the bloody pamphlet." << endl;
		}
		else
		{
			cout << "That item doesn't exist" << endl;
		}
	}
	else if(filter == 114)
	{
		player.getInventory();
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
			room.displayExits();
			room.displayItems();
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
			room.displayExits();
			room.displayItems();
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
			room.displayExits();
			room.displayItems();
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
			room.displayExits();
			room.displayItems();
			break;
	}
}

int main()
{

	Graphics g;

	g.splashScreen();
	g.introScreen();

	cout << "Presents: The Summerworth Horror - project mu demo." << endl;

	srand(time(NULL));
	Room room;
	vector<Room> roomStorage;
	vector<Object> objectStorage;

	objectStorage.push_back(object1);
	objectStorage.push_back(armoire);
	objectStorage.push_back(bigDoor);
	objectStorage.push_back(bPhm);
	objectStorage.push_back(blRobe);
	objectStorage.push_back(blRope);
	objectStorage.push_back(bRose);
	objectStorage.push_back(bKnife);
	objectStorage.push_back(cDossier);
	objectStorage.push_back(desk);
	objectStorage.push_back(flLight);


	// Rooms are currently hard-coded to keep the secrecy of the game intact,
	// while the primary example of this demo is to show that the engine is
	// functional and basic actions can be done.

	Room room1 = Room("Kitchen", "A dimly lit kitchen, with depressing linoleum tile.", 1, 2, 4, 3, 5, true, false);
	Room room2 = Room("Living Room", "A rustic 1970s style living room, with worn shag carpeting. It looks like a lot of family type stuff happened here.", 2, 3, 1, 4, 5, true, false);
	Room room3 = Room("Hall", "The hall is long and it looks like a kid or bored teenager may have drawn something on the walls in the recent past. ...definitely a teenager. There's colorful obscenities about an English teacher named Mr. Davisson.", 3, 4, 2, 5, -1, true, false);
	Room room4 = Room("Library", "A cozy library with a ton of books. Whoever lives here is an avid reader and quite literate. It's not just dimestore novels, but heady books of physics, philosophy, computer science, and math.", 4, 5, 3, -1, 2, true, false);
	Room room5 = Room("Billiard Room", "Who's up for some snooker?!", 5, 2, 4, 3, -1, true, false);

	room1.addItem(object1);
	room1.addItem(bPhm);
	room2.addItem(blRope);
	room2.addItem(cDossier);
	room3.addItem(flLight);
	room3.addItem(bKnife);
	room4.addItem(desk);
	room4.addItem(bigDoor);
	room5.addItem(armoire);
	room5.addItem(bRose);

	roomStorage.push_back(room1);
	roomStorage.push_back(room2);
	roomStorage.push_back(room3);
	roomStorage.push_back(room4);
	roomStorage.push_back(room5);
	
	room = roomStorage[0];
	room.displayName();
	room.displayDesc();
	room.displayExits();
	room.displayItems();

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