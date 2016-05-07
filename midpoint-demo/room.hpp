#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>
#include "object.hpp"
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

	vector<Object> roomItems;

public:
	Room();
	Room(string name, string roomDescription, int id, int north, int south, int east, int west, bool indoor, bool dark);
	//~Room();

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

	void addItem(Object object) {roomItems.push_back(object);}
	void removeItem(Object object) { roomItems.pop_back(); } // just a test for now, we want to see if the inventory works

	void displayDesc();
	void displayName();
	void displayExits();
	void displayItems();
	void setVisited();
	int move(string direction);

};

#endif // ROOM_HPP
