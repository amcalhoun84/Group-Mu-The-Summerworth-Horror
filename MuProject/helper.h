#ifndef HELER_H
#define HELPER_H

#include<string>
#include "item.h"
#include "room.h"
#include "player.h"

using namespace std;

string toUpperStr(string buffer);
bool isEdible(vector<Item> &itemStorage, int id);
bool canCarry(vector<Item> &itemStorage, int id);
void displayRoom(vector<Room> &roomStorage, vector<Item> &itemStorage, Player &player, Room &room, int id);
string getItemName(vector<Item> &itemStorage, int itemId);
int getItemId(vector<Item> &itemStorage, Room &room, string item);
int getIdFromItemVector(vector<Item>& itemStorage, string keyword);
string getItemDescription(vector<Item>& itemStorage, int id);
bool checkLock(vector<Room> &roomStorage, int id);
void unLock(vector<Room> &roomStorage, int id);

#endif