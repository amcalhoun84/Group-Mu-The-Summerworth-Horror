#include "room.h"
#include "parser.h"
#include <iostream>
#include <string>

using std::cout;

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
	this->visited = false;
}


void Room::addItem(vector<Room> &roomStorage, int itemId)
{
	roomItems.push_back(itemId);
	for (int i = 0; i < roomStorage.size(); i++)
	{
		if (this->roomID == roomStorage[i].roomID)
		{
			roomStorage[i].roomItems.push_back(itemId);
		}
	}
}

void Room::removeItem(vector<Room> &roomStorage, int item)
{
	roomItems.erase(find(roomItems.begin(), roomItems.end(), item));
	for (int i = 0; i < roomStorage.size(); i++)
	{
		if (this->roomID == roomStorage[i].roomID)
		{
			for (int j = 0; j < roomStorage[i].roomItems.size(); j++)
			{
				if (item == roomStorage[i].roomItems[j])
				{
					swap(roomStorage[i].roomItems[j], roomStorage[i].roomItems.back());
					roomStorage[i].roomItems.pop_back();
				}
			}
			
		}
	}
}

void Room::getItems(vector<Item>& itemStorage, vector<string>& items)
{
	for (int i = 0; i < roomItems.size(); i++)
	{
		items.push_back(getItemName(itemStorage, roomItems[i]));
	}
}

void Room::displayDesc()
{
	cout << roomDescription << endl;
}

void Room::displayName()
{
	cout << roomName << endl;
}


void Room::displayRoomItems(vector<Item>& itemStorage)
{
	cout << "You see the following items in the room:" << endl;
	int id;
	for (int i = 0; i < roomItems.size(); i++)
	{
		id = roomItems[i];
		cout << getItemName(itemStorage,id) << endl;
	}
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
