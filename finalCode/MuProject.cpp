#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "graphics.h"
#include "room.h"
#include "item.h"
#include "critter.h"
#include "parser.h"
#include "player.h"
#include "dataHandler.h"
#include "helper.h"

using namespace std;

int main()
{	
	srand(time(NULL));

	Graphics graphics;
	Item item;
	Room room;
	Critter critter;
	Player player = Player();

	vector<Room> roomStorage;
	vector<Item> itemStorage;	
	vector<Critter> critterStorage;
	
	loadRoom(room, roomStorage);
	loadItem(item, itemStorage);
	loadCritter(critter, critterStorage);
	loadItemKeywords(itemStorage);
	loadCritterKeywords(critterStorage);
	loadRoomItems(roomStorage);
	loadCritterTalk(critterStorage);

	graphics.splashScreen();
	graphics.introScreen();

	displayRoom(roomStorage, itemStorage, critterStorage, player, room, 0);

	bool gameOver = false;
	string input;
	int filter;
	int counter;

	while (!gameOver)
	{		
		input = getPlayerInput();			
		filter = parseCommand(input);
		gameOver = callFunction(roomStorage, itemStorage, critterStorage, room, player, filter, input, graphics);
		if (!gameOver)
		{
			gameOver = checkGameOver(roomStorage, itemStorage, room, player, graphics);
		}
	}
	
	return 0;
}

