#include "room.hpp"

using namespace std;

Room::Room(int id, WorldEngine *we)
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
Room::~Room()
{

}

void Room::getDescription(int _roomid)
{
	//create string object for description
	ifstream roomDesc;
	roomDesc.open("./rooms/" + _roomid);
	//get contents of room file description until sentry character % is found
	//not yet tested or compiled...very subject to change
	if(roomDesc.is_open())
	{
		string line;
		//set sentry character separating room description from items/characters
		char sentry = '%';
		while (roomData.peek() != sentry)
		{
			while (getline(roomData, line))
				roomDescription.append(line);
		}
	}
}
void addItem(string object)  //This would involve changing item vector to string vs int which might be simpler to parse data files
{
	roomItems.push_back(object);
	
}
void Room::displayDesc(string roomDescription)
{
	cout << roomDescription << '\n';
}

void Room::displayName(int _roomID)
{
	cout << rooms.at(_roomID)->roomName << endl << endl;
}

void Room::displayDesc(string roomDescription)
{
	
}

void Room::displayName(string roomName)
{
	
}

void Room::setVisited(int _roomID)
{
	for(int i=0; i<rooms.size(); i++)
	{
		if(rooms.at(r))
	}
}
void Room::getMoves()
{
	
}