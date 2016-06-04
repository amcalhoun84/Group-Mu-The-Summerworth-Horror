#include <stdio.h>
#include<string>
#include <iostream>
#include<sstream>
#include <vector>
#include "room.h"
#include "item.h"
#include "critter.h"
#include "parser.h"
#include "player.h"
#include "dataHandler.h"
#include "MuProject.h"

using namespace std;

int main()
{
	Room room;
	vector<Room> roomStorage;

	Item item;
	vector<Item> itemStorage;

	Critter critter;
	vector<Critter> critterStorage;

	Player player = Player();

	loadRoom(room, roomStorage);
	loadItem(item, itemStorage);
	loadCritter(critter, critterStorage);
	loadItemKeywords(itemStorage);
	loadCritterKeywords(critterStorage);
	loadRoomItems(roomStorage);

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

