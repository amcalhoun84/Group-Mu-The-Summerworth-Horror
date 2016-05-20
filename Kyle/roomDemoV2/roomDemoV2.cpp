#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "room.h"

using namespace std;

void createObject(Room room, vector<Room> roomStorage);

int main()
{
	Room room;
	vector<Room> roomStorage;
	
	createObject(room, roomStorage);
	
	roomStorage[0].displayName();
}

void createObject(Room room, vector<Room> roomStorage)
{
	string line;
	stringstream ss;
	int strInt;
	
	vector<string> roomName;
	vector<string> roomDescr;
	vector<string> roomId;
	vector<string> north;
	vector<string> south;
	vector<string> east;
	vector<string> west;
	vector<string> indoor;
	vector<string> dark;
	vector<string> visited;
	
	vector<int> roomIdInt;
	vector<int> northInt;
	vector<int> southInt;
	vector<int> eastInt;
	vector<int> westInt;
	vector<int> indoorInt;
	vector<int> darkInt;
	vector<int> visitedInt;
	
	ifstream roomDesc("demoRoom.txt");
	
	if(!roomDesc)
	{
		cout << "Error opening output file" << endl;
	}

	while (roomDesc.good())
	{
		for (int i=0; i<10; i++)
		{
			//add room details to vectors
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() != 0)
				{
					roomName.push_back(line);
					line.clear();
					break;
				}
			}
			
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					roomDescr.push_back(line);
					line.clear();
					break;
				}
			}
		
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					roomId.push_back(line);
					line.clear();
					break;
				}
			}
			
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					north.push_back(line);
					line.clear();
					break;
				}
			}
			
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					south.push_back(line);
					line.clear();
					break;
				}
			}
			
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					east.push_back(line);
					line.clear();
					break;
				}
			}
			
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					west.push_back(line);
					line.clear();
					break;
				}
			}
			
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					indoor.push_back(line);
					line.clear();
					break;
				}
			}
			
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					dark.push_back(line);
					line.clear();
					break;
				}
			}
			
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					visited.push_back(line);
					line.clear();
					break;
				}
			}
		}
	}
	
	roomDesc.close();
	
	//convert string vectors to int
	for (int i = 0; i < roomId.size(); i++)
	{
		ss.str(roomId[i]);
		ss >> strInt;
		roomIdInt.push_back(strInt);
	}
	
	for (int i = 0; i < north.size(); i++)
	{
		ss.str(north[i]);
		ss >> strInt;
		northInt.push_back(strInt);
	}
	
	for (int i = 0; i < south.size(); i++)
	{
		ss.str(south[i]);
		ss >> strInt;
		southInt.push_back(strInt);
	}
	
	for (int i = 0; i < east.size(); i++)
	{
		ss.str(east[i]);
		ss >> strInt;
		eastInt.push_back(strInt);
	}
	
	for (int i = 0; i < west.size(); i++)
	{
		ss.str(west[i]);
		ss >> strInt;
		westInt.push_back(strInt);
	}
	
	for (int i = 0; i < indoor.size(); i++)
	{
		ss.str(indoor[i]);
		ss >> strInt;
		indoorInt.push_back(strInt);
	}
	
	for (int i = 0; i < dark.size(); i++)
	{
		ss.str(dark[i]);
		ss >> strInt;
		darkInt.push_back(strInt);
	}
	
	for (int i = 0; i < visited.size(); i++)
	{
		ss.str(visited[i]);
		ss >> strInt;
		visitedInt.push_back(strInt);
	}
	
	//set room object data
	for (int i = 0; i < roomName.size(); i++)
	{
		room.setName(roomName[i]);
		room.setRoomDescription(roomDescr[i]);
		room.setRoomId(roomIdInt[i]);
		room.setNorth(northInt[i]);
		room.setSouth(southInt[i]);
		room.setEast(eastInt[i]);
		room.setWest(westInt[i]);
		
		if(indoorInt[i] == 0)
			room.setIndoor(false);
		else 
			room.setIndoor(true);
		
		if(darkInt[i] == 0)
			room.setDark(false);
		else 
			room.setDark(true);
		
		if(visitedInt[i] == 1)
			room.setVisited();
		
		roomStorage.push_back(room);
	}
}