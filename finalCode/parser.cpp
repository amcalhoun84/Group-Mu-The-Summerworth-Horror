#include "parser.h"
#include "item.h"

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
	else if (com == "GET" || com == "TAKE" || com == "GRAB")
	{
		filter = 2;
	}
	else if (com == "LOOK" || com == "EXAMINE")
	{
		filter = 3;
	}
	else if (com == "DROP" || com == "DISCARD" || com == "TOSS")
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
	else if (com == "DEVCHECK")
	{
		filter = 10; 
		
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

bool callFunction(vector<Room> &roomStorage,vector<Item> &itemStorage, vector<Critter> &critterStorage, Room &room, Player &player, int filter, string command, Graphics &graphics)
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
			if (com2 == "NORTH" || com2 == "N")
			{
				id = room.getNorth();
			}
			else if (com2 == "SOUTH" || com2 == "S")
			{
				id = room.getSouth();
			}
			else if (com2 == "EAST" || com2 == "E")
			{
				id = room.getEast();
			}
			else if (com2 == "WEST" || com2 == "W")
			{
				id = room.getWest();
			}
			else if (com2 == "UP" || com2 == "U")
			{
				id = room.getUp();
			}
			else if (com2 == "DOWN" || com2 == "D")
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
					//if (room.getDark() && !player.getHasLight())	// the darkness was game breaking. If you don't grab the flashlight, you can't progress or leave.
				//{
					//cout << "You can't see to go anywhere!" << endl;
					//gameOver = false;
					//break;
				//}
				//else
				//{
					//gameOver = false;
					//break;
				//}
				//else
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

		else if (com2 == "RECORD")
		{
			cout << "Health: " << player.getHealth() << " / 100" << endl;
			cout << "Sanity: " << player.getSanity() << " / 50" << endl;
			cout << "You currently do " << player.getDamageValue() << " (up to) per attack." << endl;
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
		else if (com2 == "ALFRED" || com2 == "CALEB" || com2 == "BROWN" || com2 == "MIST" || com2 == "ONE")
		{
			if (room.getCritter() > 0)
			{	
				if (room.getCritter() == 100 && com2 == "ALFRED")
				{
					room.displayCritter(critterStorage);
					gameOver = false;
					break;
				}
				else if (room.getCritter() == 101 && com2 == "CALEB")
				{
					room.displayCritter(critterStorage);
					gameOver = false;
					break;
				}
				else if (room.getCritter() == 102 && com2 == "BROWN")
				{
					room.displayCritter(critterStorage);
					gameOver = false;
					break;
				}
				else if (room.getCritter() == 103 && com2 == "MIST")
				{
					room.displayCritter(critterStorage);
					gameOver = false;
					break;
				}
				else if (room.getCritter() == 104 && com2 == "ONE")
				{
					room.displayCritter(critterStorage);
					gameOver = false;
					break;
				}
				else
				{
					cout << "I don't know what you want to " << com1 <<  " (at)" << endl;
					gameOver = false;
					break;
				}
			}
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
				
				else if(id == 38)
				{
					for(int i = 0; i < roomStorage.size(); i++)
					cout << getItemDescription(itemStorage, id, graphics) << endl;
					gameOver = false;
					break;
				}

				else if(id == 205)
				{
					cout << getItemDescription(itemStorage, id, graphics) << endl;
					gameOver = false;
					break;
				}

				else if(id == 215)
				{
					cout << getItemDescription(itemStorage, id, graphics) << endl;
					gameOver = false;
					break;
				}

				else
				{
					cout << getItemDescription(itemStorage, id, graphics) << endl;
					gameOver = false;
					break;
				}
				
			}
			else
			{	
				if (getIdDrop(itemStorage, player, com2) != -1)
				{
					cout << "Please use a descriptive word with the noun, typed as one word. For example: ritualkey" << endl;
					break;
				}
				else
				{
					cout << getItemDescription(itemStorage, id, graphics) << endl;
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
				if(id==3)
					player.setDamageValue(6);
				if(id==9)
					player.setDamageValue(10);
				if(id==99)
					player.setDamageValue(4);
				if(id==208)
					player.setDamageValue(6);
				gameOver = false;
				break;
			}
			else
			{
				cout << "You can only equip a weapon." << endl;
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
			if (sanity > 50)
			{
				sanity = 50;
			}
			player.setSanity(sanity);
			cout << "Your sanity is " << sanity << "/50" << endl;
											
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
			else if (id == 210 && room.getRoomId() == 14)
			{
				room.setNorth(18);
				unLock(roomStorage, 18);

				cout << "Inspecting the odd fixture, you notice that there is an indentation that fits the signet ring. When you place the ring in and twist it, you hear a click and the odd panel moves to the side." << endl;
				break;
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
						cout << "You use the note to decode the leather bound book from Mr. Brown's room. You learn about the history of the Summerworth Estate and the cult to a being known as the One Who Sleeps that had a gathering here nearly a century ago and the methods that were used to summon the entity." << endl << endl;
					}
					if (player.hasItem(211))
					{
						cout << "You use the note to decode the strange book from the hidden room. You learn how the One Who Sleeps was banished from the world, and see notes implicating Alfred the Gardner in the murders. Also, there is discussions of how to summon and how to banish the being. Words about the family's famous blue roses, a holy artifact of silver to dispel the mists, a warding amulet, and the remains of an extradimensional being are mentioned." << endl << endl;
					}
					if (roomStorage[9].getVisited())
					{
						cout << "You use the note to decode the writing on the wall of that creepy bathroom. It loosely translates, THE ONE WHO SLEEPS COMETH" << endl;
					}

					if (player.hasItem(205) && player.hasItem(211) && roomStorage[9].getVisited() == true)
					{

						for(int i=0; i < critterStorage.size(); i++)
						{
							if(critterStorage[i].getId() == 100)
							{
								critterStorage[i].setAccused(true);
								critterStorage[i].setEvidence(true);
								cout << "You feel like it might be a good time to talk to Alfred..." << endl;
							}
						}
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

			else if (id == 113)
			{
				if(room.getRoomId() != 33)
				{
					cout << "You're not quite sure what do to with the gossamer film..." << endl;
				}
				else
				{
					for(int i = 0; i < critterStorage.size(); i++)
					{
						int playerSanity, playerHealth;
						int OWShealth;
						
						if(critterStorage[i].getId() == 104 && room.getRoomId() == 33)
						{

							OWShealth = critterStorage[i].getHealth();
							OWShealth--; 
							critterStorage[i].setHealth(OWShealth);
							cout << "The One Who Sleeps seems to be out of phase in this reality before attempting to re-assert itself." << endl;
							player.removeInventory(113);
							cout << "The mist essence fades from existence..." << endl;

							playerHealth = player.getHealth();
							playerHealth -= critterStorage[i].attackCritter();
							playerSanity = player.getSanity();
							playerSanity -= critterStorage[i].attackSanity();
							player.setHealth(playerHealth);
							player.setSanity(playerSanity);

							cout << "You feel some of your life-force and sanity slip away as you attempt to abjure the One Who Sleeps." << endl;

							//checkGameOver(roomStorage, itemStorage, room, player, graphics);
												

							if(critterStorage[i].getHealth() <= 0)
							{
								cout << "The One Who Sleeps recoils and fades from existence, banished once again to the realm beyond the stars..." << endl;
								cout << "A small vial of ectoplasm falls to the floor with a soft tinkling noise." << endl;
								roomStorage[33].setCritter(0);
								room.addItem(roomStorage, 114);

							}

							if(player.getHealth() <= 0)
							{
								cout << "You feel your body disintegrate around you and the last thing you see is the horrid dimension of the One Who Sleeps. It is beyond description, and you die from shock and horror." << endl;
								checkGameOver(roomStorage, itemStorage, room, player, graphics);
								break;
							}

							if(player.getSanity() <= 0)
							{
								cout << "The last vestiges of your mind and self fade away as you are made into a thrall of the One Who Sleeps, carrying out it's foul will throughout the world." << endl;
								checkGameOver(roomStorage, itemStorage, room, player, graphics);
								break;
							}
						}
					}
				}
				break;
			}

			else if (id == 203)
			{
				if(room.getRoomId() != 33)
				{
					cout << "You fiddle with the rose, but nothing happens." << endl;
					break;
				}
				else
				{
					for(int i = 0; i < critterStorage.size(); i++)
					{
						int playerSanity, playerHealth;
						int OWShealth;
						
						if(critterStorage[i].getId() == 104 && room.getRoomId() == 33)
						{

							OWShealth = critterStorage[i].getHealth();
							OWShealth--; 
							critterStorage[i].setHealth(OWShealth);

							playerHealth = player.getHealth();
							playerHealth -= critterStorage[i].attackCritter();
							playerSanity = player.getSanity();
							playerSanity -= critterStorage[i].attackSanity();
							player.setHealth(playerHealth);
							player.setSanity(playerSanity);


							cout << "You feel some of your life-force and sanity slip away as you attempt to abjure the One Who Sleeps." << endl;

							cout << "The One Who Sleeps shrieks in anger as it is presented the blue rose." << endl;
							player.removeInventory(203);
							cout << "The rose wilts and falls away to ash and stardust." << endl;
						

							//checkGameOver(roomStorage, itemStorage, room, player, graphics);
												

							if(critterStorage[i].getHealth() <= 0)
							{
								cout << "The One Who Sleeps recoils and fades from existence, banished once again to the realm beyond the stars..." << endl;
								cout << "A small vial of ectoplasm falls to the floor with a soft tinkling noise." << endl;
								roomStorage[33].setCritter(0);
								room.addItem(roomStorage, 114);
							}

							if(player.getHealth() <= 0)
							{
								cout << "You feel your body disintegrate around you and the last thing you see is the horrid dimension of the One Who Sleeps. It is beyond description, and you die from shock and horror." << endl;
								checkGameOver(roomStorage, itemStorage, room, player, graphics);
								break;
							}

							if(player.getSanity() <= 0)
							{
								cout << "The last vestiges of your mind and self fade away as you are made into a thrall of the One Who Sleeps, carrying out it's foul will throughout the world." << endl;
								checkGameOver(roomStorage, itemStorage, room, player, graphics);
								break;
							}

						}
					}
				}
				break;
			}

			else if(id == 212) 
			{
				int coinflip; 
				int attackResults, sanity, playerHealth, critterHealth;

				for(int i = 0; i < critterStorage.size(); i++)
				{

					if(room.getRoomId() == 37 && critterStorage[i].getId() == 103)
					{
							cout << "The mist corporealizes into a vaguely humanoid form!" << endl;

							player.setInCombat(true);

							while(player.getInCombat() == true)
							{
								
								if(player.getHealth() <= 0)
								{
									cout << "The mist fills your nose and mouth and you cannot breathe... your vision turns red and then black as you slowly drown and suffocate." << endl;
								}

								if(player.getSanity() <= 0)
								{
									cout << "You become lost in the mists between worlds, forever doomed to wander in a fugue state." << endl;
								}
								
								checkGameOver(roomStorage, itemStorage, room, player, graphics);

								if(critterStorage[i].getHealth() <= 0)								
								{
									roomStorage[37].setCritter(0);
									cout << "The form of the mist shatters and falls to tatters at your feet, leaving a fine film on the ground." << endl;
									room.addItem(roomStorage, 113);
									player.setInCombat(false);
									break;
								}

								coinflip = rand() % 2;

								if(coinflip == 0)
								{
									critterHealth = critterStorage[i].getHealth();
									attackResults = player.playerAttack();
									critterHealth -= attackResults;
									critterStorage[i].setHealth(critterHealth);
									cout << "You hit the form for " << attackResults << " damage!" << endl;
									cout << "The Mists have " << critterHealth << " / 20 health left!" << endl << endl; 

									playerHealth = player.getHealth();
									attackResults = critterStorage[i].attackCritter();
									playerHealth -= attackResults;
									player.setHealth(playerHealth);
									cout << "The form slams into you for " << attackResults << " damage!" << endl;
									cout << "You have " << playerHealth << " / 100 health left!" << endl;
									if(attackResults >= 3)
									{	
										sanity = player.getSanity();
										attackResults = critterStorage[i].attackSanity();
										sanity -= attackResults;
										player.setSanity(sanity);
										cout << "You feel a bit of your sanity slipping." << endl;
									}
								}

								else if(coinflip == 1)
								{
									playerHealth = player.getHealth();
									attackResults = critterStorage[i].attackCritter();
									playerHealth -= attackResults;
									player.setHealth(playerHealth);
									cout << "The form slams into you for " << attackResults << " damage!" << endl;
									cout << "You have " << critterHealth << " / 100 left!" << endl << endl;
									
									if(attackResults >= 3)
									{	
										sanity = player.getSanity();
										attackResults = critterStorage[i].attackSanity();
										sanity -= attackResults;
										player.setSanity(sanity);
										cout << "You feel a bit of your sanity slipping." << endl;

									}

									critterHealth = critterStorage[i].getHealth();
									attackResults = player.playerAttack();
									critterHealth -= attackResults;
									critterStorage[i].setHealth(critterHealth);
									cout << "You hit the form for " << attackResults << " damage!" << endl;
									cout << "The Mists have " << critterHealth << " / 20 health left!" << endl << endl;

								}

							}

						}
					
					}

				if(room.getRoomId() != 37)
				{
					cout << "You fiddle with the cross, but nothing happens." << endl;
				}
				gameOver = false;
				break;
			}
				
				
			else if (id == 215)
			{
				if(room.getRoomId() == 33)
				{
					for(int i = 0; i < critterStorage.size(); i++)
					{
						int playerSanity, playerHealth;
						int OWShealth;
						
						if(critterStorage[i].getId() == 104 && room.getRoomId() == 33)
						{

							OWShealth = critterStorage[i].getHealth();
							OWShealth--; 
							critterStorage[i].setHealth(OWShealth);
							cout << "The One Who Sleeps hisses in terror from the sight of the binding amulet, before destroying it." << endl;
							player.removeInventory(212);
							cout << "The amulet falls away into a fine powder." << endl;

							playerHealth = player.getHealth();
							playerHealth -= critterStorage[i].attackCritter();
							playerSanity = player.getSanity();
							playerSanity -= critterStorage[i].attackSanity();
							player.setHealth(playerHealth);
							player.setSanity(playerSanity);

							cout << "You feel some of your life force and sanity slip away as you attempt to abjure the One Who Sleeps." << endl;

							//checkGameOver(roomStorage, itemStorage, room, player, graphics);

							if(critterStorage[i].getHealth() <= 0)
							{
								cout << "The One Who Sleeps recoils and fades from existence, banished once again to the realm beyond the stars..." << endl;
								cout << "A small vial of ectoplasm falls to the floor with a soft tinkling noise." << endl;
								roomStorage[33].setCritter(0);
								room.addItem(roomStorage, 114);
								break;
							}

							if(player.getHealth() <= 0)
							{
								cout << "You feel your body disintegrate around you and the last thing you see is the horrid dimension of the One Who Sleeps. It is beyond description, and you die from shock and horror." << endl;
								checkGameOver(roomStorage, itemStorage, room, player, graphics);
								break;
							}

							if(player.getSanity() <= 0)
							{
								cout << "The last vestiges of your mind and self fade away as you are made into a thrall of the One Who Sleeps, carrying out it's foul will throughout the world." << endl;
								checkGameOver(roomStorage, itemStorage, room, player, graphics);
								break;
							}

						}
					}
				}
				else 
				{
					cout << "You play with the amulet, but nothing seems to happen." << endl;
				}
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
	case 9: // accuse
		if (room.getCritter() == -1 || (room.getCritter() != 100 && room.getCritter() != 101 && room.getCritter() != 102))
		{
			cout << "I don't understand with whom you wish to " << com1 << endl;
			gameOver = false;
			break;
		}

		if (room.getCritter() == 100)
		{
			if(player.hasItem(205) && player.hasItem(211) && player.hasItem(213))
			{
				accuseCondition = true;
				for(int i = 0; i < critterStorage.size(); i++)
				{
					if(critterStorage[i].getId() == 100 && (player.hasItem(205) && player.hasItem(211) && player.hasItem(213)))
					{
							critterStorage[i].displayAccuse2();
							player.setInCombat(true);
							cout << "Alfred lunges at you, brandishing deadly shears!" << endl;
							while(player.getInCombat() == true)
							{					
								checkGameOver(roomStorage, itemStorage, room, player, graphics);

								int attackResults = 0;
								int critterHealth = 0;
								int sanityAttack = 0;
								int playerHealth = 0, playerSanity = 0;
								int randomTaunt = 0;

								int coinFlip = rand() % 2;
								if(coinFlip==0)
								{
									attackResults = player.playerAttack();
									critterHealth = critterStorage[i].getHealth();
									critterHealth -= attackResults;
									critterStorage[i].setHealth(critterHealth);
									cout << "You hit Alfred for " << attackResults << "!" << endl;
									cout << "He has " << critterHealth  << " / 60 health left!" << endl;

									if(critterStorage[i].getHealth() <= 0)
									{	
										roomStorage[12].setCritter(0);
										// cout << "Room Check: " << room.getCritter() << endl;
										room.addItem(roomStorage, 110);
										room.addItem(roomStorage, 217);
										cout << "Alfred lets out a wheezing gasp about the blue rose as you put him down. You stop for a moment to collect yourself, sweat dripping from your brow." << endl;
										cout << "You notice he has dropped a key to the gate in the garden..." << endl;
										
										player.setInCombat(false);
										break;
									}

									attackResults = critterStorage[i].attackCritter();
									playerHealth = player.getHealth();
									playerHealth -= attackResults;
									player.setHealth(playerHealth);
									cout << "Alfred hits you for " << attackResults << " damage!" << endl;
									cout << "You have " << playerHealth << " / 100 health left." << endl;
								}
								else if(coinFlip==1)
								{
									attackResults = critterStorage[i].attackCritter();
									playerHealth = player.getHealth();
									playerHealth -= attackResults;
									player.setHealth(playerHealth);
									cout << "Alfred hits you for " << attackResults << " damage!" << endl;
									cout << "You have " << playerHealth << " / 100 health left." << endl;
									attackResults = player.playerAttack();
									critterHealth = critterStorage[i].getHealth();
									critterHealth -= attackResults;
									critterStorage[i].setHealth(critterHealth);
									cout << "You hit Alfred for " << attackResults << "!" << endl;
									cout << "He has " << critterHealth  << " / 60 health left!" << endl;

									if(critterStorage[i].getHealth() <= 0)
									{	
										roomStorage[12].setCritter(0);
										// cout << "Room Check: " << room.getCritter() << endl;
										room.addItem(roomStorage, 110);
										room.addItem(roomStorage, 217);
										cout << "Alfred lets out a wheezing gasp about the blue rose as you put him down. You stop for a moment to collect yourself, sweat dripping from your brow." << endl;
										cout << "You notice he has dropped a key to the gate in the garden..." << endl;
										player.setInCombat(false);
										break;
									}
									if(player.getHealth() <= 0)
									{
										cout << "You gurgle in pain and choke on your own blood as Alfred slams his shears into your throat... the world goes black." << endl;
										player.setInCombat(false);
										checkGameOver(roomStorage, itemStorage, room, player, graphics);
									}
								}
							}
						}
					}
				}
				gameOver = false;
				break;
			}

			// We decided not to have Caleb actually be complicit, as it was too cliche and there were difficulties with the fact we couldn't justify it until
			// very late in the game. 

			if (room.getCritter() == 101)
			{

				for (int i = 0; i < critterStorage.size(); i++)
				{
					if (critterStorage[i].getId() == 101 && critterStorage[i].getAccused() ==  false)
					{
						critterStorage[i].displayAccuse1();
						break;
					}
					else if(critterStorage[i].getId() == 101 && critterStorage[i].getAccused() == true && (player.hasItem(207) && player.hasItem(216) && player.hasItem(215)))
					{
							int attackResults = 0;
							int critterHealth = 0;
							int sanityAttack = 0;
							int playerHealth = 0, playerSanity = 0;
							int randomTaunt = 0;
							int coinFlip = 0;
									
							critterStorage[i].displayAccuse2();
							player.setInCombat(true);
							cout << "Caleb takes a swing at you, his strong fists flying at unbelievable speed!" << endl;
							while(player.getInCombat() == true)
							{					
								if(critterStorage[i].getHealth() <= 0)
								{	
									roomStorage[12].setCritter(0);
									// cout << "Room Check: " << room.getCritter() << endl;
									room.addItem(roomStorage, 111);
									room.addItem(roomStorage, 215);
									cout << "Caleb crumples at your feet, the last suspect in this gruesome murder taken down. A tragic waste." << endl;
									player.setInCombat(false);
									break;
								}	

								if(player.getHealth() <= 0)
								{
										cout << "Your vision fades to black as Caleb pounces you and chokes the life from your body." << endl;
										player.setInCombat(false);
								}
	
								checkGameOver(roomStorage, itemStorage, room, player, graphics);

								int coinFlip = rand() % 2;
								if(coinFlip==0)
								{
									attackResults = player.playerAttack();
									critterHealth = critterStorage[i].getHealth();
									critterHealth -= attackResults;
									critterStorage[i].setHealth(critterHealth);
									cout << "You hit Caleb for " << attackResults << "!" << endl;
									cout << "He has " << critterHealth  << " / 60 health left!" << endl;					

									attackResults = critterStorage[i].attackCritter();
									playerHealth = player.getHealth();
									playerHealth -= attackResults;
									player.setHealth(playerHealth);
									cout << "Caleb slams you for " << attackResults << " damage!" << endl;
									cout << "You have " << playerHealth << " / 100 health left." << endl;

								}	
								else if(coinFlip==1)
								{
									attackResults = critterStorage[i].attackCritter();
									playerHealth = player.getHealth();
									playerHealth -= attackResults;
									player.setHealth(playerHealth);
									cout << "Caleb slams you for " << attackResults << " damage!" << endl;
									cout << "You have " << playerHealth << " / 100 health left." << endl;
								
									attackResults = player.playerAttack();
									critterHealth = critterStorage[i].getHealth();
									critterHealth -= attackResults;
									critterStorage[i].setHealth(critterHealth);
									cout << "You hit Caleb for " << attackResults << "!" << endl;
									cout << "He has " << critterHealth  << " / 60 health left!" << endl;

									if(critterStorage[i].getHealth() <= 0)
									{	
										roomStorage[12].setCritter(0);
										// cout << "Room Check: " << room.getCritter() << endl;
										room.addItem(roomStorage, 111);
										room.addItem(roomStorage, 215);
										cout << "Caleb crumples at your feet, the last suspect in this gruesome murder taken down. A tragic waste." << endl;
										player.setInCombat(false);
										break;
									}				

								}
							}
						}
					}
					gameOver = false;
					break;
				}
			
		if (room.getCritter() == 102)
		{		
			int critterHealth, playerHealth, playerSanity;
					int attackResults, coinFlip;

			for(int i = 0; i < critterStorage.size(); i++)
			{
				if(room.getRoomId() == 32 && critterStorage[i].getId() == 102)
				{
					
					critterStorage[i].setAccused(true);
					critterStorage[i].displayAccuse2();

					player.setInCombat(true);
					while(player.getInCombat() == true)
					{
						coinFlip = rand() % 2;
						if(coinFlip == 0)
						{
							// player goes first
							attackResults = player.playerAttack();
							critterHealth = critterStorage[i].getHealth();
							critterHealth -= attackResults;
							critterStorage[i].setHealth(critterHealth);
							cout << "You hit Mr. Brown for " << attackResults << " damage!" << endl;
							cout << "He has " << critterHealth << " / 60 health left." << endl;

							// now brown goes, same as all other combats
							attackResults = critterStorage[i].attackCritter();
							playerHealth = player.getHealth();
							playerHealth -= attackResults;
							critterStorage[i].setHealth(critterHealth);

							cout << "Mr. Brown hits you for " << attackResults << " damage!" << endl;
							cout << "You have " << playerHealth << " / 100 health left." << endl;
							if(attackResults >= 5)
							{
								playerSanity = player.getSanity();
								attackResults = critterStorage[i].attackSanity();
								playerSanity -= attackResults;
								player.setSanity(playerSanity);
							}

						}
						else if(coinFlip == 1)
						{
								// brown goes first
							attackResults = critterStorage[i].attackCritter();
							playerHealth = player.getHealth();
							playerHealth -= attackResults;
							critterStorage[i].setHealth(critterHealth);

							cout << "Mr. Brown hits you for " << attackResults << " damage!" << endl;
							cout << "You have " << playerHealth << " / 100 health left." << endl;

							if(attackResults >= 5)
							{
								playerSanity = player.getSanity();
								attackResults = critterStorage[i].attackSanity();
								playerSanity -= attackResults;
								player.setSanity(playerSanity);
							}

								// player goes
							attackResults = player.playerAttack();
							critterHealth = critterStorage[i].getHealth();
							critterHealth -= attackResults;
							critterStorage[i].setHealth(critterHealth);
							cout << "You hit Mr. Brown for " << attackResults << " damage!" << endl;
							cout << "He has " << critterHealth << " / 60 health left." << endl;
						}


						if(player.getHealth() <= 0)
						{
							cout << "As you feel your throat being slit, you see horrific visions of the world falling to the One Who Sleeps..." << endl;
							checkGameOver(roomStorage, itemStorage, room, player, graphics);
						}

						if(player.getSanity() <= 0)
						{
							cout << "You feel your mind shatter, and you prostrate yourself before Mr. Brown, swearing allegience to the One Who Sleeps..." << endl;
							checkGameOver(roomStorage, itemStorage, room, player, graphics);
						}

						if(critterStorage[i].getHealth() <= 0)
						{
							cout << "Mr. Brown shrieks obscenities at you as he is defeated, screaming his defiance. After he breathes his last, it's time to finish this job..." << endl;
							for(int j; j < critterStorage.size(); j++)
							{
								if(critterStorage[j].getId() == 101)
								{
									critterStorage[j].setAccused(true);
								}
								roomStorage[32].setCritter(0);
								room.addItem(roomStorage, 214);
								room.addItem(roomStorage, 112);
								player.setInCombat(false);
								break;
							}
						}
						}

					}
			
					else if(critterStorage[i].getId() == 102)
					{
						critterStorage[i].displayAccuse1();
					}
				}
					gameOver = false;
					break;
			}

		





	case 10: // devcheck (disable before release)
		if(com2 == "XKCD")
		{
			cout << "Critter Stats" << endl;
			for(int i=0; i < critterStorage.size(); i++)
			{
				cout << "Critter Name: " << critterStorage[i].getName() << endl;
				cout << "Critter Damage: " << critterStorage[i].getDV() << endl;
				cout << "Critter Health: " << critterStorage[i].getHealth() << endl;
				cout << "Critter ID: " << critterStorage[i].getId() << endl;
				gameOver = false;
				break;
			}
		}
		else if(com2 == "ROOM")
		{
			cout << "Room ID: " << room.getRoomId() << endl;
			cout << "Room Visited? " << room.getVisited() << endl;
			gameOver = false;
			break;
		}

		else if(com2 == "PLOTKIT")
		{
			cout << "You suddenly have a lot of stuff..." << endl;
	player.addInventory(itemStorage, 214);
	player.addInventory(itemStorage, 217);
	player.addInventory(itemStorage, 211);
	player.addInventory(itemStorage, 212);
	player.addInventory(itemStorage, 209);
	player.addInventory(itemStorage, 113);
	player.addInventory(itemStorage, 203);
	player.addInventory(itemStorage, 210);
	player.addInventory(itemStorage, 205);
	player.addInventory(itemStorage, 213);
	player.addInventory(itemStorage, 9);
	player.addInventory(itemStorage, 12);
	player.addInventory(itemStorage, 12);
	player.addInventory(itemStorage, 32);
	player.addInventory(itemStorage, 5);

		}

		else if(com2 == "HEAL")
		{
			cout << "You feel much better..." << endl;
			player.setHealth(200);
			player.setSanity(200);
		}

		else if(com2 == "RSTOR")
		{
			for(int i = 0; i < roomStorage.size(); i++)
			{
				cout << "Room Idx:" << i << endl;
				cout << "Room ID:" << roomStorage[i].getRoomId() << endl;
				cout << "Room Name" << roomStorage[i].getRoomDescription() << endl;
				cout << "Room Visited: " << roomStorage[i].getVisited() << endl;
				cout << "Room Critter:" << roomStorage[i].getCritter() << endl << endl;
				gameOver = false;
				break;
			}
		}
		else if(com2 == "DEATH")
		{
		cout << "YOU DIE!" << endl;
		player.setHealth(-100);
		checkGameOver(roomStorage, itemStorage, room, player, graphics);
		exit(1);
		break;
		}

		else if(com2 == "INSANE")
		{
		cout << "YOU GO MAD!" << endl;
		player.setSanity(-100);
		checkGameOver(roomStorage, itemStorage, room, player, graphics);
		exit(1);
		break;
		}

		else
		{
			cout << "No dev command like that..." << endl;

		}

		gameOver = false;
		break;


	case 9999: //quit
		gameOver = quit();
		break;

	default:
		gameOver = false;
		break;

	
	}
	return gameOver;
}


bool checkGameOver(vector<Room>& roomStorage, vector<Item>& itemStorage, Room & room, Player & player, Graphics &graphics)
{
	if (player.getHealth() <= 0)
	{
		cout << "You are dead! Game Over!" << endl;
		usleep(2500000);
		graphics.deathScreen();
		player.setInCombat(false); // minor reduncancies, we need to make sure it turns off the combat and leave the game.
		
		return true;
		exit(1);
	}
	else if(player.getSanity() <=0)
	{
		cout << "You have lost touch with reality! Game Over!" << endl;
		usleep(2500000);
		graphics.insanityScreen();
		player.setInCombat(false); // minor reduncancies, we need to make sure it turns off the combat and leave the game.
		
		return true;
		exit(1);

	}
	else if (room.getRoomId() == 0 && player.hasItem(114) )
	{
		cout << "Congratulations! You have solved the Summerworth Horror and closed the case. You are left wondering; however, if this is only the beginning of something darker." << endl;
		cout << "You are certain the chief and others down back at the Precinct won't believe a word of this tale, but surely enough, it happened to you..." << endl;
		
		cout << "As you pull your car back out of the driveway, you are left wondering what would make people turn to dark entities that are inimical to this world." << endl;
		cout << "And whether or not what happened, actually is how you remember it... there is just an empty feeling in your stomach, and like part of your soul is gone." << endl;
		cout << "But it was honestly, just another day on the job... and you are sure, you will see stranger things yet, supernatural or not." << endl;
		cout << "But now, it's time for a well earned cigarette and scotch..." << endl;

		cout << endl << endl << endl;

		cout << "The end..." << endl;

		usleep(10000000);
		graphics.creditsScreen();


		cout << "Group MU Presents - The Summerworth Horror! - Thank you for playing." << endl << endl;

		return true;
		exit(1);


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
		cout << "Do you really want to quit? Please enter Y or N: ";
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
