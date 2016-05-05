#include "room.hpp"
#include <iostream>
#include <string>

using namespace std;

Room::Room()
{

}

Room::Room(string name, string roomDescription, int id, int north, int south, int east, int west, bool indoor, bool dark)
{
	this->roomName = name;
	this->roomDescription = roomDescription;
	this->roomID = id;
	this->north = north;
	this->south = south;
	this->east = east;
	this->west = west;
	this->indoor = indoor;
	this->dark = dark;
	this->roomVisited = false;
}

//Room::~Room()
//{
//}

void Room::displayDesc()
{
	cout << roomDescription << endl;
}

void Room::displayName()
{
	cout << roomName << endl;
}

void Room::setVisited()
{
	roomVisited = true;
}

int Room::move(string direction)
{
	int id;
	
	if (direction == "north")
	{
		id = this->north;
	}
	else if (direction == "south")
	{
		id = this->south;
	}
	else if (direction == "east")
	{
		id = this->east;
	}
	else if (direction == "west")
	{
		id = this->west;
	}
	
	return id;
}