#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include "room.h"
#include "item.h"
#include "critter.h"

using namespace std;

void loadRoom(Room &room, vector<Room> &roomStorage);

void loadItem(Item &item, vector<Item> &itemStorage);

void loadCritter(Critter &critter, vector<Critter> &critterStorage);

void loadItemKeywords(vector<Item> &itemStorage);

void loadCritterKeywords(vector<Critter> &critterStorage);

void loadRoomItems(vector<Room> &roomStorage);

#endif
