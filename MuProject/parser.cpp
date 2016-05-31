#include <string>
#include <iostream>
#include <sstream>
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
//getPlayerInput() will be correctly formatted
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
	else if (com == "GET" || com == "TAKE" || com == "GRAB")
	{
		filter = 2;
	}
	else if (com == "LOOK" || com == "EXAMINE" || com == "INSPECT")
	{
		filter = 3;
	}
	else if (com == "DROP")
	{
		filter = 4;
	}
	else if (com == "EQUIP" || com == "WIELD")
	{
		filter = 5;
	}
	else if (com == "EAT")
	{
		filter = 6;
	}
	else if (com == "USE")
	{
		filter = 7;
	}
	else if (com == "ATTACK" || com == "FIGHT" || com == "KILL")
	{
		filter = 8;
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

bool callFunction(vector<Room> &roomStorage,vector<Item> &itemStorage, Room &room, Player &player, int filter,string command)
{
	int id;
	vector<string> commands;
	vector<string> items;
	string com;
	string com1;
	string com2;
	stringstream ss(command);
	bool gameOver;
	bool itemPresent = false;
	
	
	while (ss >> com)
	{
		commands.push_back(com);
	}

	com1 = commands[0];
	//Basically, if input is not "QUIT", it should be a 2 word command and safe to assign com2 to the second element of commands
	if (filter != 9999)
	{
		com2 = commands[1];
	}
			
	switch (filter)
	{
	case -1: 
		gameOver = false;
		break;
	case 1: //go or move
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
				displayRoom(roomStorage, itemStorage, player, room, id);
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
				displayRoom(roomStorage, itemStorage, player, room, id);
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
				displayRoom(roomStorage, itemStorage, player, room, id);
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
				displayRoom(roomStorage, itemStorage, player, room, id);
				gameOver = false;
				break;
			}
		}
		else if (com2 == "UP")
		{
			id = room.getUp();
			if (id == -1)
			{
				cout << "You can't " << com1 << " up. Try another command" << endl;
				gameOver = false;
				break;
			}
			else
			{
				displayRoom(roomStorage, itemStorage, player, room, id);
				gameOver = false;
				break;
			}
		}
		else if (com2 == "DOWN")
		{
			id = room.getDown();
			if (id == -1)
			{
				cout << "You can't " << com1 << " down. Try another command" << endl;
				gameOver = false;
				break;
			}
			else
			{
				displayRoom(roomStorage, itemStorage, player, room, id);
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
	case 2: //get
		if (com2 == "INVENTORY")
		{
			player.displayInventory(itemStorage);
			gameOver = false;
			break;
		}
		else
		{
			vector<string> items;
			room.getKeywords(itemStorage, items);

			for (int i = 0; i < items.size(); i++)
			{
				if (com2 == toUpperStr(items[i]))
				{
					itemPresent = true;
				}
			}

			if (itemPresent)
			{
				id = getItemId(itemStorage, room, com2);
				player.addInventory(itemStorage, id);
				room.removeItem(roomStorage, id);
				gameOver = false;
				break;
			}
			else
			{
				cout << "I don't know what you what to " << com1 << endl;
				gameOver = false;
				break;
			}	
			
		}
	case 3: //look
		if (com2 == "ROOM")
		{
			room.displayDesc();
			room.displayRoomItems(itemStorage);
			gameOver = false;
			break;
		}
		else
		{
			vector<string>items;
			room.getItems(itemStorage, items);
			for (int i = 0; i < items.size(); i++)
			{
				if (com2 == toUpperStr(items[i]))
				{
					itemPresent = true;
				}
			}
			if (itemPresent)
			{
				for (int i = 0; i < itemStorage.size(); i++)
				{
					if (com2 == toUpperStr(itemStorage[i].getName()))
					{
						itemStorage[i].displayDescription();
						gameOver = false;
						
					}
				}
				break;
			}
			else
			{
				cout << "I don't know what you want to " << com1 << " at. Please try again." << endl;
				gameOver = false;
				break;
			}
			
		}
	case 4: //drop
		
		player.getItems(itemStorage, items);
		player.getKeywords(itemStorage, items);

		for (int i = 0; i < items.size(); i++)
		{
			if (com2 == toUpperStr(items[i]))
			{
				itemPresent = true;
			}
		}

		if (itemPresent)
		{
			id = getItemId(itemStorage, room, com2);
			player.removeInventory(id);
			room.addItem(roomStorage,id);
			cout << "You dropped " << getItemName(itemStorage, id) << " from your inventory." << endl;
			gameOver = false;
			break;
		}
		else
		{
			cout << "I don't know what you what to " << com1 << endl;
			gameOver = false;
			break;
		}
	case 5:  //equip
		
		player.getItems(itemStorage, items);

		player.getKeywords(itemStorage, items);

		for (int i = 0; i < items.size(); i++)
		{
			if (com2 == toUpperStr(items[i]))
			{
				itemPresent = true;
			}
		}
		if (itemPresent)
		{
			id = getItemId(itemStorage, room, com2);
			player.setEquippedItem(id);
			cout << "You equipped " << getItemName(itemStorage, id) << " ." << endl;
			gameOver = false;
			break;
		}
		else
		{
			cout << "I don't know what you what to " << com1 << endl;
			gameOver = false;
			break;
		}
	case 6: //eat 
		if (com2 == "TOMATO" || com2 == "SANDWICH" || com2 == "BANANA" || com2 == "ENERGY" || com2 == "BAR")
		{
			vector<string> items;
			player.getKeywords(itemStorage, items);

			for (int i = 0; i < items.size(); i++)
			{
				if (com2 == toUpperStr(items[i]))
				{
					itemPresent = true;
				}
			}
			if (itemPresent)
			{
				srand(time(NULL));
				int randomTaunt = rand() % 6 + 1;

				switch (randomTaunt)
				{
				case 1:
					cout << "That really hit the spot!" << endl;
					break;

				case 2:
					cout << "Could have used some ketchup!" << endl;
					break;

				case 3:
					cout << "That was delicious. Do you have any beer?" << endl;
					break;

				case 4:
					cout << "Wow, that was surprisingly good!" << endl;
					break;

				case 5:
					cout << "Just like Momma used to make!" << endl;
					break;

				case 6:
					cout << "Please sir, may I have another?" << endl;
					break;

				default:
					cout << "My writer got bored and forgot to include a taunt here... " << endl;
					break;
				}
			
				id = getItemId(itemStorage, room, com2);
				player.removeInventory(id);
				gameOver = false;
				break;
			}
			else
			{
				srand(time(NULL));
				int randomTaunt = rand() % 6 + 1;

				switch (randomTaunt)
				{
				case 1:
					cout << "That sounds good! Do you have one?" << endl;
					break;

				case 2:
					cout << "You certainly have a vivid imagination. Please enjoy your non-existent meal!" << endl;
					break;

				case 3:
					cout << "There's no " << com2 << " here. How many fingers am I holding up? " << endl; ;
					break;

				case 4:
					cout << "There's no " << com2 << " here. Did you hit your head on something? " << endl;
					break;

				case 5:
					cout << "I think you should get your eyes checked! " << "There's no " << com2 << " here." << endl;
					break;

				case 6:
					cout << "You're kidding, right?" << endl;
					break;

				default:
					cout << "My writer got bored and forgot to include a taunt here... " << endl;
					break;
				}

				gameOver = false;
				break;
			}
			
		}
		else
		{			
			srand(time(NULL));
			int randomTaunt = rand() % 6 + 1;

			switch (randomTaunt)
			{
			case 1:
				cout << "I wouldn't eat that if I were you!" << endl;
				break;

			case 2:
				cout << "I don't think that's on your diet!" << endl;
				break;

			case 3:
				cout << "You're kidding, right?" << endl; ;
				break;

			case 4:
				cout << "I don't think that would taste very good!" << endl;
				break;

			case 5:
				cout << "Ha ha. Very funny!" << endl;
				break;

			case 6:
				cout << "I would never thought of trying to eat that!" << endl;
				break;

			default:
				cout << "My writer got bored and forgot to include a taunt here... " << endl;
				break;
			}
			gameOver = false;
			break;
		}
	case 7: //use
		if (com2 == "FLASHLIGHT")
		{	
			vector<string> items;
			player.getKeywords(itemStorage, items);

			for (int i = 0; i < items.size(); i++)
			{
				if (com2 == toUpperStr(items[i]))
				{
					itemPresent = true;
				}
			}

			if (itemPresent)
			{
				cout << "You can see a lot better now!" << endl;
				room.displayDesc();
				room.displayRoomItems(itemStorage);
				player.setHasLight(true);

				gameOver = false;
				break;
			}
			else
			{
				cout << "I don't know what you what to " << com1 << endl;
				gameOver = false;
				break;
			}
		}
		else if (com2 == "KEY")
		{
			vector<string> items;
			player.getKeywords(itemStorage, items);

			for (int i = 0; i < items.size(); i++)
			{
				if (com2 == toUpperStr(items[i]))
				{
					itemPresent = true;
				}
			}

			if (itemPresent)
			{
				cout << "The door is unlocked!" << endl;
				room.setLocked(false);
				gameOver = false;
				break;
			}
			else
			{
				cout << "I don't know what you what to " << com1 << endl;
				gameOver = false;
				break;
			}
		}
		else
		{
			cout << "I don't know what you want to " << com1 << endl;
			gameOver = false;
			break;
		}
		case 8: // attack 	
			for(int i=0; i < roomStorage.size()-1; i++)
			{
				itemName = roomStorage.at(i).getName();
				if(com2 == itemName)
				{

				}
			}


			if(!critter)
			{
				cout << "You cast magic missile at the darkness..." << endl;
				cout << "OH, look! A Gazebo!" << endl;
				cout << "If there are hot chicks at the tavern, I want to do them!!!!" << endl;
				cout << "Do you have any Mountain Dew or Doritos?" << endl;
			}

			if(critter.getEssential() == true)
			{
				int randomTaunt = (rand() % 6) + 1;

				switch(randomTaunt)
				{
					case 1:
						cout << "You want to go to jail?" << endl;
						break;
	
					case 2:
						cout << "Without cause or warrant, trying to arrest or assaulting someone is against the law." << endl;
						break;

					case 3:
						cout << "Remember your oath to serve and protect... need I remind you again?" << endl;
						break;

					case 4:
						cout << "Nope. Tell Death, not Today." << endl;
						break;

					case 5: 
						cout << "What are you, five? You can't just hit people." << endl;
						break;

					case 6: 
						cout << "Uh-oh, looks like someone is getting feisty." << endl;
						break;

					default:
						cout << "The author got lazy and didn't want to write anymore..." << endl;
						break;


				}
				break;
			}

			if(critter.getInvcinble() == true)
			{
				int randomTaunt = (rand() % 6) + 1;

				switch(randomTaunt)
				{
					case 1:
						cout << "Your attack is utterly ineffective." << endl;
						break;
	
					case 2:
						cout << "Today, a God shall bleed, but not with how you are going at it." << endl;
						break;

					case 3:
						cout << "That didn't work. Try something else." << endl;
						break;

					case 4:
						cout << "Conventional means are ineffective." << endl;
						break;

					case 5: 
						cout << "Hint: This isn't working. Try something else." << endl;
						break;

					case 6: 
						cout << "Your blow is deflected and ineffective." << endl;
						break;

					default:
						cout << "The author got lazy and didn't want to write anymore..." << endl;
						break;


				}
				break;
			}

			p.setInCombat(true);
			while(p.getInCombat() == true)
			{
				int attackResults;
				int coinFlip = rand() % 2;

				critterHealth = c.getHealth();
				playerHealth = p.getHealth();
				playerSanity = p.getSanity();

				if(critterHealth <= 0)
				{
					inCombat = false
					this->room.CritterID = 0;
					// remove Critter from Room
					// Add Corpse Object, will be
					// critter ID + 10;
					break;
				}

				if(playerHealth <= 0)
				{
					g.deathScreen();
					gameOver = true;

				}

				if(playerSanity <= 0)
				{
					g.insanityScreen();
					gameOver = true;
				}

				if(coinFlip == 0) // player goes first
				{
					attackResults = p.attackCritter();
					attackResults = c.attackPlayer();


				}
				else // enemy goes first this round
				{
					attackResults = p.attackPlayer();
					
					playerHealth -= attackResults;
					p.setHealth(playerHealth);
					
					attackResults = c.attackCritter();

					critterHealth -= attackResults
					if((c.getCritterID() == 103 || c.getCritterID() == 104)) && attackResults >= (c.getDamageValue() * .75));
					{
						attackResults = c.attackSanity();
						playerSanity -= attackResults;
						p.setSanity(playerSanity);
					}
				
				}
			}			
				

	// We need to do some special cases for the One Who Sleeps as it is more of a puzzle battle
			// than an actual fight. The OWS still gets to attack though.

	case 9999: //quit
		gameOver = quit();
		break;
	default:
		gameOver = false;
		break;
	}
	return gameOver;
}

void displayRoom(vector<Room> &roomStorage, vector<Item> &itemStorage,Player &player, Room &room, int id)
{
	for (int i = 0; i < roomStorage.size(); i++)
	{
		if (roomStorage[i].getRoomId() == id)
		{
			room = roomStorage[i];
		}
	}
	room.displayName();
	if (!room.getDark() || player.getHasLight())
	{
		room.displayDesc();
		room.displayRoomItems(itemStorage);
		if(room.getID() == 33)
		{
			int OWSID = 105;
				if(room.CritterID == 105)
				{
					g.OneWhoSleeps();
				}

		}
	}
	else
	{
		cout << "It's dark and you can't see anything!" << endl;
	}
	
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
string getItemName(vector<Item> &itemStorage, int itemId)
{
	string itemName = "";
	for (int j = 0; j < itemStorage.size(); j++)
	{
		if (itemId == itemStorage[j].getItemID())
		{
			itemName = itemStorage[j].getName();
		}
	}
	return itemName;
}

int getItemId(vector<Item> &itemStorage, Room &room, string item)
{
	int id = 0;
	vector<int> items;
	
	bool endLoop = false;
	room.getItemsVector(items);
	

	for (int i = 0; i < itemStorage.size(); i++)
	{
		for (int j = 0; j < itemStorage[i].keywords.size(); j++)
		{
			
				if (toUpperStr(itemStorage[i].keywords[j]) == item)
				{
					id = itemStorage[i].getItemID();
					for (int k = 0; k < items.size(); k++)
					{
						if (id == items[k])
						{
							return id;
						}
					}
				}
		}
	}
	return id;
}

int getPlayerItemId(vector<Item> &itemStorage, Player &player, string item)
{
	int id = 0;
	vector<int> items;

	bool endLoop = false;
	player.getItemsVector(items);


	for (int i = 0; i < itemStorage.size(); i++)
	{
		for (int j = 0; j < itemStorage[i].keywords.size(); j++)
		{

			if (toUpperStr(itemStorage[i].keywords[j]) == item)
			{
				id = itemStorage[i].getItemID();
				for (int k = 0; k < items.size(); k++)
				{
					if (id == items[k])
					{
						return id;
					}
				}
			}
		}
	}
	return id;
}