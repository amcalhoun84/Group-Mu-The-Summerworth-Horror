#include <stdio.h>
#include<string>
#include <iostream>
#include<sstream>
#include <vector>
#include "room.h"
#include "item.h"
#include "parser.h"
#include "player.h"

using namespace std;


int main()
{
	Room room;
	vector<Room> roomStorage;

	Item item;
	vector<Item> itemStorage;

	//sample room created by constructor - Room(string name, string roomDescription, int id, int north, int south, int east, int west, bool indoor, bool dark)
	Room room1 = Room("Kitchen", "There's lots of food!", 1, 2, -1, -1, -1, true, false);  //-1 indicates that the player can't go that direction
	Room room2 = Room("Living Room", "There's a big leather couch!", 2, 3, 1, -1, -1, true, false);
	Room room3 = Room("Hall", "Nothing to see here!", 3, 4, 2, -1, -1, true, false);
	Room room4 = Room("Library", "Books, books, and more books!", 4, 5, 3, -1, -1, true, false);
	Room room5 = Room("Billiard Room", "There's a big pool table, duh!", 5, -1, 4, -1, -1, true, false);

	room1.addItem(1);
	room1.addItem(2);
	room2.addItem(3);
	room2.addItem(4);
	room3.addItem(5);
	room3.addItem(1);
	room4.addItem(2);
	room4.addItem(3);
	room5.addItem(4);
	room5.addItem(5);

	roomStorage.push_back(room1);
	roomStorage.push_back(room2);
	roomStorage.push_back(room3);
	roomStorage.push_back(room4);
	roomStorage.push_back(room5);
	
	Item item1 = Item("flashlight", "It's a flashlight stupid", "Thing that shines light", 1, 0, 1, true, false, true);
	Item item2 = Item("book", "It's a book stupid", "Thing that you read", 2, 0, 1, true, false, true);
	Item item3 = Item("candle", "It's a candle stupid", "Thing that has a wick", 3, 0, 1, true, false, true);
	Item item4 = Item("bloody robe", "It's a bloody robe stupid", "Thing that is bloody", 4, 10, 1, true, true, true);
	Item item5 = Item("brick", "It's a brick stupid", "Thing that bricks", 5, 0, 1, true, false, true);

	itemStorage.push_back(item1);
	itemStorage.push_back(item2);
	itemStorage.push_back(item3);
	itemStorage.push_back(item4);
	itemStorage.push_back(item5);

	Player player = Player();

	room = roomStorage[0];
	room.displayName();
	room.displayDesc();
	room.displayRoomItems(itemStorage);
	
	bool gameOver = false;
	string input;
	int filter;

	while (!gameOver)
	{		
		input = getPlayerInput();			
		filter = parseCommand(input);
		gameOver = callFunction(roomStorage, itemStorage, room, player, filter, input);
						
	}
		
	return 0;
}

