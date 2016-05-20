#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <iostream>
#include "room.h"

void createObject(Room room, vector<Room> roomStorage);


int main()
{
	cout << "starting test!" << endl;
	
	Room room;
	vector<Room> roomStorage;
	
	
	createObject(room, roomStorage);
	
	for (int i = 0; i < 3; i++)
	{
		roomStorage[i].displayName();
		cout << "something should be above me.";
	}
	return 0;
}

void createObject(Room room, vector<Room> roomStorage)
{
    string roomData;
    
    ifstream roomFile("demoRoom.txt");

	if(!roomFile)
	{
		cout << "Error opening output file" << endl;
	}
	
	//This will keep track of the field number so you know which piece of room Data you are parsing
	int counter = 0;
	bool marker = false;
	
    while (getline(roomFile, roomData, ';'))
	{
		switch(counter)
		{
            //This is the room name
            case 0:
               room.setName(roomData);
               break;
            //This is the room description
            case 1:
                room.setRoomDescription(roomData);
            //This is the roomId
            case 2:
                room.setRoomId(atoi(roomData.c_str()));  //In C++11 this will convert a string to an integer. If C++11 does not work on flip use: atoi(roomData.c_str())
                break;
            case 3:
                room.setNorth(atoi(roomData.c_str()));
                break;
            case 4:
                room.setSouth(atoi(roomData.c_str()));
                break;
            case 5:
                room.setEast(atoi(roomData.c_str()));
                break;
            case 6:
                room.setWest(atoi(roomData.c_str()));
                break;
            case 7:
                if(roomData == "0")
                {
                    marker = false;
                }
                else
                {
                    marker = true;
                }
                room.setIndoor(marker);
                break;
            case 8:
                if(roomData == "0")
                {
                    marker = false;
                }
                else
                {
                    marker = true;
                }
                room.setDark(marker);
                break;
            //The roomVisited will always be 0 starting out but I put a field in there so you can use this function to 
            //saved files which will have different values in the rooms that have been visited.
            case 9:
                if(roomData == "0")
                {
                    marker = false;
                }
                else
                {
                    room.setVisited();
                }
                
                break;
		}
		counter++;
		//If the the counter is greater than 9, all the fields for a room object have been loaded. push_back room into the roomStorage vector and 
		//start over with the next room in the data file.
		if (counter > 9)
		{
            roomStorage.push_back(room); //This reads the Room object with all the values loaded from data file directly into the vector of Room objects
            counter = 0; //This starts you over so you can put data into the next Room object
		}
	}
}