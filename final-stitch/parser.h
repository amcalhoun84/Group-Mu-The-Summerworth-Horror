#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "room.h"
#include "item.h"
#include "player.h"
#include "helper.h"
#include "critter.h"
#include "graphics.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

string getPlayerInput();
int parseCommand(string command);
bool callFunction(vector<Room> &roomStorage, vector<Item> &itemStorage, vector<Critter> &critterStorage, Room &room, Player &player, int filter, string command, Graphics &graphics);
bool checkGameOver(vector<Room> &roomStorage, vector<Item> &itemStorage, Room &room, Player &player, Graphics &graphics);
bool quit();

#endif
