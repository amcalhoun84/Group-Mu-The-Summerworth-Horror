#include "room.hpp"
#include "object.hpp"
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

void Room::displayExits()
{
	cout << "You can go: " << endl;

	if(this->north >= 0) cout << "North" << endl;
	if(this->east >= 0) cout << "East" << endl;
	if(this->west >= 0) cout << "West" << endl;
	if(this->south >= 0) cout << "South" << endl;
	
}

void Room::displayItems()
{
	cout << "There is a ";
	for(int i=0; i<roomItems.size()-1; i++)
	{
		cout << roomItems.at(i).getObjName() << ", ";
	}

	cout << "and a " << roomItems.at(roomItems.size()-1).getObjName() << " here." << endl;

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