#include "room.hpp"

using namespace std;

Room::Room(int id, WorldEngine *we)
{
	
}

Room::~Room()
{

}

void Room::getDescription(int id)
{
	//create string object for description
	ifstream roomDesc;
	roomDesc.open("./rooms/" + id);
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

void Room::displayDesc(string roomDescription)
{
	cout << roomDescription << '\n';
}

void Room::displayName(string roomName)
{
	
}

void Room::displayDesc(string roomDescription)
{
	
}

void Room::displayName(string roomName)
{
	
}

void Room::setVisited(bool roomVisited)
{
	
}
void Room::getMoves()
{
	
}
