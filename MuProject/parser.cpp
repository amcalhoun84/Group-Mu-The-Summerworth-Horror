#include "parser.h"

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
	cout << endl;
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
	if (com == "MOVE" || com == "GO" || com == "PROCEED" || com == "WALK")
	{
		filter = 1; 
	}
	else if (com == "GET")
	{
		filter = 2;
	}
	else if (com == "LOOK" || com == "EXAMINE")
	{
		filter = 3;
	}
	else if (com == "DROP")
	{
		filter = 4;
	}
	else if (com == "EQUIP")
	{
		filter = 5;
	}
	else if (com == "EAT" || com == "CHOW" || com == "DEVOUR" || com == "GNOSH")
	{
		filter = 6;
	}
	else if (com == "USE")
	{
		filter = 7;
	}
	else if (com == "TALK" || com == "QUESTION" || com == "INTERROGATE" || com == "INTEROGATE" || com == "GRILL")
	{
		filter = 8;
	}
	else if (com == "ACCUSE")
	{
		filter = 9;
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

bool callFunction(vector<Room> &roomStorage,vector<Item> &itemStorage, vector<Critter> &critterStorage, Room &room, Player &player, int filter,string command)
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
	bool accuseCondition = false;
	
	
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
	case -1: //invalid command
		gameOver = false;
		break;
	case 1: //go or move
		if (com2 == "NORTH" || com2 == "SOUTH" || com2 == "EAST" || com2 == "WEST" || com2 == "UP" || com2 == "DOWN")
		{
			if (com2 == "NORTH")
			{
				id = room.getNorth();
			}
			else if (com2 == "SOUTH")
			{
				id = room.getSouth();
			}
			else if (com2 == "EAST")
			{
				id = room.getEast();
			}
			else if (com2 == "WEST")
			{
				id = room.getWest();
			}
			else if (com2 == "UP")
			{
				id = room.getUp();
			}
			else if (com2 == "DOWN")
			{
				id = room.getDown();
			}
			if (id == -1)
			{
				cout << "You can't " << com1 << " "<< com2 << ". Try another command" << endl;
				gameOver = false;
				break;
			}
			else if (checkLock(roomStorage, id))
			{
				cout << "I'm sorry. That room is locked." << endl;
				gameOver = false;
				break;
			}
			else
			{
				if (room.getDark() && !player.getHasLight())
				{
					cout << "You can't see to go anywhere!" << endl;
					gameOver = false;
					break;
				}
				else
				{
					displayRoom(roomStorage, itemStorage, critterStorage, player, room, id);
					gameOver = false;
					break;
				}
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
			id = getIdFromItemVector(itemStorage, com2);
			if (id == -1)
			{
				cout << "I don't know what you want to " << com1 << endl;
				gameOver = false;
				break;
			}
			else
			{
				if (room.hasItem(id))
				{
					if (canCarry(itemStorage, id))
					{
						player.addInventory(itemStorage, id);
						room.removeItem(roomStorage, id);
						gameOver = false;
						break;
					}
					else
					{
						cout << "And just how do you think you are going to carry that?" << endl;
						gameOver = false;
						break;
					}
				}
				else
				{
					cout << "There doesn't seem to be any " << com2 << " in the room." << endl;
					gameOver = false;
					break;
				}
				
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
			id = getIdFromItemVector(itemStorage, com2);
			if (id == -1)
			{
				cout << "I don't know what you want to " << com1 << endl;
				gameOver = false;
				break;
			}
			else
			{
				if (room.hasItem(id) || player.hasItem(id))
				{
					cout << getItemDescription(itemStorage, id) << endl;
					gameOver = false;
					break;
				}
				else
				{
					cout << "There isn't a " << com2 << " in the room or in your inventory." << endl;
					gameOver = false;
					break;
				}
			}
		}
	case 4: //drop
		
		id = getIdFromItemVector(itemStorage, com2);
		if (id == -1)
		{
			cout << "I don't know what you want to " << com1 << endl;
			gameOver = false;
			break;
		}
		else
		{
			if (player.hasItem(id))
			{
				player.removeInventory(id);
				room.addItem(roomStorage, id);
				cout << "You dropped " << getItemName(itemStorage, id) << " from your inventory." << endl;
				gameOver = false;
				break;
			}
			else
			{
				cout << "You don't have a " << com2 << " in your inventory." << endl;
				gameOver = false;
				break;
			}
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
			
		id = getIdFromItemVector(itemStorage, com2 );

		if (id == -1)
		{
			cout << "I don't understand what you want to " << com1 << "." << endl;
			gameOver = false;
			break;
		}
		else if (isEdible(itemStorage, id))
		{
			if (player.hasItem(id))
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
				player.removeInventory(id);
				gameOver = false;
				break;
			}
			else
			{
				if (room.hasItem(id))
				{
					cout << "You need to use \'get\' command to put " << com2 << " in your inventory before you can eat it." << endl;
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
					gameOver = false;
					break;
			}
					
			gameOver = false;
			break;
		}
				
	case 7: //use
		
		id = getIdFromItemVector(itemStorage, com2);

		if (id == -1)
		{
			cout << "I don't understand what you want to " << com1 << "." << endl;
			gameOver = false;
			break;
		}
		else
		{
			if (id == 5)
			{
				if (player.hasItem(5)) //flashlight
				{
					cout << "You can see a lot better now!" << endl;
					room.displayDesc();
					room.displayRoomItems(itemStorage);
					player.setHasLight(true);

					gameOver = false;
					break;
				}
			}
			else if (id == 209 || id == 210 || id == 214 || id == 217) //These are the 3 game keys + 210 is signet ring
			{
				bool locked = false;
				if (room.getNorth() != -1)
				{
					if (checkLock(roomStorage, room.getNorth()))
					{
						id = room.getNorth();
						locked = true;
					}
				}
				else if (room.getSouth() != -1)
				{
					if (checkLock(roomStorage, room.getSouth()))
					{
						id = room.getSouth();
						locked = true;
					}
				}
				else if (room.getEast() != -1)
				{
					if (checkLock(roomStorage, room.getEast()))
					{
						id = room.getEast();
						locked = true;
					}
				}
				else if (room.getWest() != -1)
				{
					if (checkLock(roomStorage, room.getWest()))
					{
						id = room.getWest();
						locked = true;
					}
				}

				if (locked)
				{
					
					if ((room.getRoomId() == 4 && player.hasItem(209)) || (room.getRoomId() == 15 && player.hasItem(210)) || (room.getRoomId() == 36 && player.hasItem(217)) || (room.getRoomId() == 32 && player.hasItem(214)))
					{
						unLock(roomStorage, id);
						cout << "The door is unlocked!" << endl;
						gameOver = false;
						break;
					}
					else
					{
						cout << "You need to find another key. The door is still locked" << endl;
						if (room.getRoomId() == 15)
						{
							cout << "There appears to be a depression that looks like a ring might fit into it." << endl;
						}
						gameOver = false;
						break;
					}
					
				}
				else
				{
					cout << "You don't need a key. All the doors are unlocked!" << endl;
					gameOver = false;
					break;
				}
			}
		}
	case 8:
		if (room.getCritter() == -1 || (room.getCritter() != 100 && room.getCritter() != 101 && room.getCritter() != 102))
		{
			cout << "I don't understand with whom you wish to " << com1 << endl;
			gameOver = false;
			break;
		}
		else
		{		
			for (int i = 0; i < critterStorage.size(); i++)
			{
				if (critterStorage[i].getId() == room.getCritter())
				{
					critterStorage[i].displayTalk();
				}
			}
			gameOver = false;
			break;
		}
	case 9:
		if (room.getCritter() == -1 || (room.getCritter() != 100 && room.getCritter() != 101 && room.getCritter() != 102))
		{
			cout << "I don't understand with whom you wish to " << com1 << endl;
			gameOver = false;
			break;
		}
		else
		{
			if (room.getCritter() == 100)
			{

			}
			else if (room.getCritter() == 101)
			{

			}
			else if (room.getCritter() == 102)
			{

			}

			for (int i = 0; i < critterStorage.size(); i++)
			{
				if (critterStorage[i].getId() == room.getCritter())
				{
					if (!accuseCondition)
					{
						critterStorage[i].displayAccuse1();
					}
					else
					{
						critterStorage[i].displayAccuse2();
					}
				}
			}
			gameOver = false;
			break;
		}
	case 9999: //quit
		gameOver = quit();
		break;
	default:
		gameOver = false;
		break;
	}
	return gameOver;
}

bool checkGameOver(vector<Room>& roomStorage, vector<Item>& itemStorage, Room & room, Player & player)
{
	if (player.getHealth() <= 0)
	{
		cout << "You are dead! Game Over!" << endl;
		return true;
	}
	else if (room.getRoomId() == 0 && player.hasItem(114) )
	{
		cout << "Congratulations! You have won the game!" << endl;
		return true;
	}
	else
	{
		return false;
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
		cout << "Cowardice does not become you. " << endl;
		break;

	case 2:
		cout << "Scared of the dark, are we? " << endl;
		break;

	case 3:
		cout << "Thou wish to quit? Thou hath lost an eigth! " << endl; // Ultima reference
		break;

	case 4:
		cout << "Oh, so now you want to work... " << endl;
		break;

	case 5:
		cout << "Don't worry. You'll come crawling back. " << endl;
		break;

	case 6:
		cout << "Why would you want to quit this great game? " << endl;
		break;

	default:
		cout << "My writer got bored and forgot to include a taunt here... " << endl;
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



