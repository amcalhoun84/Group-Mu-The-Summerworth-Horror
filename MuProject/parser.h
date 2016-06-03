#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "room.h"
#include "item.h"
#include "player.h"

using namespace std;

string getPlayerInput();
int parseCommand(string command);
bool callFunction(vector<Room> &roomStorage, vector<Item> &itemStorage, Room &room, Player &player, int filter, string command);
void displayRoom(vector<Room> &roomStorage, vector<Item> &itemStorage, Player &player, Room &room, int id);
string getItemName(vector<Item> &itemStorage, int itemId);
int getItemId(vector<Item> &itemStorage, Room &room, string item);
bool isEdible(vector<Item>& itemStorage, string keyword);
bool canCarry(vector<Item>& itemStorage, int id);
bool checkLock(vector<Room> &roomStorage, int id);
void unLock(vector<Room> &roomStorage, int id);
bool quit();

#endif