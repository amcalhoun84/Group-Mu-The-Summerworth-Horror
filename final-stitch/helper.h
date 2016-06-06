#ifndef HELER_H
#define HELPER_H

#include<string>
#include "item.h"
#include "room.h"
#include "player.h"
#include "critter.h"
#include "graphics.h"

using namespace std;

string toUpperStr(string buffer);
bool isEdible(vector<Item> &itemStorage, int id);
bool canCarry(vector<Item> &itemStorage, int id);
void displayRoom(vector<Room> &roomStorage, vector<Item> &itemStorage, vector<Critter> &critterStorage, Player &player, Room &room, int id);
string getItemName(vector<Item> &itemStorage, int itemId);
int getItemId(vector<Item> &itemStorage, Room &room, string item);
int getPlayerItemId(vector<Item>& itemStorage, Player & player, string item);
int getIdGet(vector<Item>& itemStorage, Room room, string keyword);
int getIdDrop(vector<Item>& itemStorage, Player player, string keyword);
string getItemDescription(vector<Item>& itemStorage, int id, Graphics &graphics);
int checkLock(vector<Room>& roomStorage, Room & room);
bool checkLock(vector<Room> &roomStorage, int id);
void unLock(vector<Room> &roomStorage, int id);
void setCritters(vector<Room>& roomStorage);
bool keyMatch(int lockedRoom, int key);
#endif
