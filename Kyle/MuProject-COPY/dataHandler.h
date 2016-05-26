#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include "room.h"
#include "critter.h"
#include "item.h"

using namespace std;

void loadRoom(Room &room, vector<Room> &roomStorage);
void loadCritter(Critter &critter, vector<Critter> &critterStorage);
void loadItem(Item &item, vector<Item> &itemStorage);

#endif
