#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "item.h"

using namespace std;

class Room
{
private:
	string roomName;
	string roomDescription;
	
	int roomID; 
	int north;
	int south;
	int east;
	int west;
	bool indoor; // is the room inside or outside?
	bool dark;	// is the room dark when you enter?
	bool roomVisited;

	vector<int> roomItems;

public:
	Room(){};
	Room::Room(string name, string roomDescription, int id, int north, int south, int east, int west, bool indoor, bool dark);
	~Room(){};

	void setName(string name) { roomName = name; }
	string getName() { return roomName; }

	void setRoomDescription(string description) { roomDescription = description; }
	string getRoomDescription() { return roomDescription; }

	void setRoomId(int room) { roomID = room;}
	int getRoomId() { return roomID; }

	void setNorth(int n) {north = n;}
	int getNorth() { return north;}

	void setSouth(int s) {south = s;}
	int getSouth() { return south; }

	void setEast(int e) {east = e;}
	int getEast() { return east; }

	void setWest(int w) {west = w;}
	int getWest() { return west; }

	void setIndoor(bool in) { indoor = in; }
	bool getIndoor() { return indoor; }

	void setDark(bool dk) { dark = dk; }
	bool getDark() { return dark; }

	void addItem(int object) {roomItems.push_back(object);}

	void removeItem(int item);
	void getItems(vector<Item> &itemStorage, vector<string> &roomItems);

	void displayDesc();
	void displayName();
	void setVisited();
	void displayRoomItems(vector<Item> &itemStorage);
	int move(string direction);

};

#endif