#ifndef PARSER_H
#define PARSER_H

#include "room.h"
#include "item.h"
#include "player.h"

using namespace std;

string getPlayerInput();
int parseCommand(string command);
bool callFunction(vector <Room> roomStorage, vector <Item> itemStorage, Room &room, Player &player, int filter,string command);
void displayRoom(vector<Room> roomStorage, Room &room, int id);
bool quit();

#endif