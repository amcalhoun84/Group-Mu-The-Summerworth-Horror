#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include "room.h"
#include "critter.h"

using namespace std;

void loadRoom(Room &room, vector<Room> &roomStorage);
void loadCritter(Critter &critter, vector<Critter> &critterStorage);

#endif
