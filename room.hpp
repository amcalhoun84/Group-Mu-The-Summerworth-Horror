// Room.hpp

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <fstream>

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
	Room(int id, WorldEngine *we);
	~Room();
	void getDescription(int id);
	void displayDesc(string roomDescription);
	void displayName(string roomName);
	void setVisited(bool roomVisited);
	void getMoves();

	const bool visited();
	const vector<int> items();



};

#endif