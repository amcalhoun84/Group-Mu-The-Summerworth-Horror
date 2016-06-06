#include "parser.h"

using namespace std;

string getPlayerInput()
{
	vector<string> commands;
	string item="";
	string input="";
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
			if (len != 0)
			{
				if (commands[0] == "QUIT")
				{
					return input;
				}
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
					if (id == 43)
					{
						setCritters(roomStorage);
					}
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
			id = getIdGet(itemStorage, room, com2);
			if (id == -1)
			{
				cout << "I don't know what you want to " << com1 << endl;
				gameOver = false;
				break;
			}
			else
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

		}
	case 3: //look
		if (com2 == "ROOM")
		{
			id = room.getRoomId();
			displayRoom(roomStorage, itemStorage, critterStorage, player, room, id);
			gameOver = false;
			break;
		}
		else
		{
			id = getIdGet(itemStorage, room, com2);
			if (id == -1)
			{
				id = getIdDrop(itemStorage, player, com2);
				if (id == -1)
				{
					cout << "I don't know what you want to " << com1 <<  " (at)" << endl;
					gameOver = false;
					break;
				}
				else
				{
					cout << getItemDescription(itemStorage, id) << endl;
					gameOver = false;
					break;
				}
				
			}
			else
			{	
				if (getIdDrop(itemStorage, player, com2) != -1)
				{
					cout << "Please use a descriptive word with the noun, typed as one word. For example: ritualkey" << endl;
				}
				else
				{
					cout << getItemDescription(itemStorage, id) << endl;
					gameOver = false;
					break;
				}	
			}
		}
	case 4: //drop
		
		id = getIdDrop(itemStorage, player, com2);
		if (id == -1)
		{
			cout << "I don't know what you want to " << com1 << endl;
			gameOver = false;
			break;
		}
		else
		{	
				player.removeInventory(id);
				room.addItem(roomStorage, id);
				cout << "You dropped " << getItemName(itemStorage, id) << " from your inventory." << endl;
				gameOver = false;
				break;
		}
		
	case 5:  //equip
		
		id = getIdDrop(itemStorage, player, com2);

		if (id == -1)
		{
			cout << "I don't know what you want to " << com1 << endl;
			gameOver = false;
			break;
		}
		else
		{		
			if (id == 3 || id == 9 || id == 85)
			{
				player.setEquippedItem(id);
				cout << "You equipped " << getItemName(itemStorage, id) << endl;
				gameOver = false;
				break;
			}
			else
			{
				cout << "You can only equip weapons." << endl;
				gameOver = false;
				break;
			}
		}	
	case 6: //eat 
			
		id = getIdDrop(itemStorage, player, com2 );

		if (id == -1)
		{
			cout << "I don't understand what you want to " << com1 << "." << endl;
			gameOver = false;
			break;
		}
		else if (isEdible(itemStorage, id))
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

			cout << endl;
			cout << "You gained 10 points of health" << endl;
			int health = player.getHealth();
			health = health + 10;
			if (health > 100)
			{
				health = 100;
			}
			player.setHealth(health);
			cout << "Your health is " << health << "/100" << endl;

			cout << "You gained 5 points of sanity" << endl;
			int sanity = player.getSanity();
			sanity = sanity + 5;
			if (sanity > 25)
			{
				sanity = 25;
			}
			player.setSanity(sanity);
			cout << "Your sanity is " << sanity << "/25" << endl;
											
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
		
		id = getIdDrop(itemStorage, player, com2);

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
				int lockedRoom = checkLock(roomStorage, room);

				if (lockedRoom != -1)
				{
					bool match = keyMatch(lockedRoom, id);

					if (match)
					{
						unLock(roomStorage, lockedRoom);
						cout << "The door is unlocked!" << endl;
						gameOver = false;
						break;
					}
					else
					{
						cout << "That key(unlocking device) doesn't work. Please try another key(unlocking device)." << endl;
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
			else if (id == 213)
			{
				if (player.hasItem(205) || player.hasItem(211) || roomStorage[9].getVisited())
				{
					if (player.hasItem(205))
					{
						cout << "You use the note to decode the leather bound book from Mr. Brown's room. You learn..." << endl;
					}
					if (player.hasItem(211))
					{
						cout << "You use the note to decode the strange book from the hidden room. You learn..." << endl;
					}
					if (roomStorage[9].getVisited())
					{
						cout << "You use the note to decode the writing on the wall of that creepy bathroom. It loosely translates, THE ONE WHO SLEEPS COMETH" << endl;
					}
				}
				else
				{
					cout << "It looks like a cypher used for decoding. If only you had a book with strange writing in it!" << endl;
				}
				gameOver = false;
				break;
			}
			else if (id == 32)
			{
				cout << "You gained 25 health." << endl;
				int health = player.getHealth();
				health = health + 25;
				if (health > 100)
				{
					health = 100;
				}
				player.setHealth(health);
				cout << "Your health is " << health << "/100" << endl;
				player.removeInventory(id);

				gameOver = false;
				break;
			}
			else
			{
				cout << "You can't use " << com2 << endl;
				gameOver = false;
				break;
			}
		}
	case 8: //talk, question, interrogate, interogate, grill
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
				for (int i = 0; i < critterStorage.size(); i++)
				{
					if (critterStorage[i].getId() == 102)
					{
						if (critterStorage[i].getHealth() <= 0)
						{
							accuseCondition = true;
						}
					}
				}
				if (accuseCondition)
				{
					if (!player.hasItem(207) || !player.hasItem(216) || !player.hasItem(215))
					{
						accuseCondition = false;
					}
				}

			}
			else if (room.getCritter() == 102)
			{
				if (room.getRoomId() == 33)
				{
					accuseCondition = true;
				}
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
	else if(player.getSanity() <=0)
	{
		cout << "You have lost touch with reality! Game Over!" << endl;
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
		if (input.length() > 0)
		{
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
		else
		{
			cout << "Please just answer the question already!" << endl;
		}
	}
	return result;
}



