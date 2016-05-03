// Room.hpp

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>
#include <fstream>
#include "worldEngine.hpp"

using namespace std;

class Room
{
private:
	string roomName;
	string roomDescription;

	int connections;
	int roomID; // should we pull rooms from an internal array?
	bool indoor; // is the room inside or outside?
	bool dark;	// is the room dark when you enter?
	bool roomVisited;

	vector<int> roomItems;
	vector<int> itemsRemoved;

public:
	Room();
	Room(string name, string roomDescription, int id, int north, int south, int east, int west, bool indoor, bool dark)
	~Room();
	void getDescription(int _roomID) { };
	void displayDesc(int _roomID);
	void displayName(int _room_ID);
	void setVisited(int _roomID);
	// void getMoves(); -- move to player

    // Getters
	bool isIndoors() { return this->indoor; }
    bool isDark() { return this->dark; }
    const bool getVisited() { return this->visited };
	vector<int> getItems();



};

#endif
