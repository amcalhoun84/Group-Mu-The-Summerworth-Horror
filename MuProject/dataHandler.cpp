#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "room.h"
#include "critter.h"
#include "item.h"

using namespace std;

void loadRoom(Room &room, vector<Room> &roomStorage)
{
	string roomData;

	ifstream roomFile;
	roomFile.open("C:\\Users\\Ganesh Venkatram\\Documents\\Visual Studio 2015\\Projects\\MuProject\\roomData.txt"); //This is the file path on my computer. On the flip server we 
	//will have the text file in the same directory as the exe, all you will need is "roomData.txt" I will try to fix this on my computer so the code remains constant

	if (!roomFile)
	{
		cout << "Error opening data file" << endl;
	}

	//This will keep track of the field number so you know which piece of room Data you are parsing
	int counter = 0;
	stringstream ss;
	int num;
	bool marker = false;

	while (getline(roomFile, roomData, ';'))
	{
		switch (counter)
		{
			//This is the room name
		case 0:
			ss.str(roomData);
			ss >> num;
			room.setRoomId(num);
			break;
		case 1:
			room.setName(roomData);
			break;
			
		case 2:
			room.setRoomDescription(roomData);
			break;
					
		case 3:
			ss.str(roomData);
			ss >> num;
			room.setNorth(num);
			break;
		case 4:
			ss.str(roomData);
			ss >> num;
			room.setSouth(num);
			break;
		case 5:
			ss.str(roomData);
			ss >> num;
			room.setEast(num);
			break;
		case 6:
			ss.str(roomData);
			ss >> num;
			room.setWest(num);
			break;
		case 7:
			ss.str(roomData);
			ss >> num;
			room.setUp(num);
			break;
		case 8:
			ss.str(roomData);
			ss >> num;
			room.setDown(num);
			break;
		case 9:
			if (roomData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			room.setIndoor(marker);
			break;
		case 10:
			if (roomData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			room.setDark(marker);
			break;
		case 11:
			if (roomData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			room.setLocked(marker);
			break;
			//The roomVisited will always be 0 starting out but I put a field in there so you can use this function to 
			//saved files which will have different values in the rooms that have been visited.
		case 12:
			if (roomData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			room.setVisited(marker);
			break;
		case 13:
			ss.str(roomData);
			ss >> num;
			room.setCritter(num);
		}
		counter++;
		//If the the counter is greater than 9, all the fields for a room object have been loaded. push_back room into the roomStorage vector and 
		//start over with the next room in the data file.
		if (counter > 13)
		{
			roomStorage.push_back(room); //This reads the Room object with all the values loaded from data file directly into the vector of Room objects
			counter = 0; //This starts you over so you can put data into the next Room object
		}
	}
}

/*********************************************
**loadCritter
*********************************************/

void loadCritter(Critter &critter, vector<Critter> &critterStorage)
{
	string critterData;
	
	ifstream critterFile;
	critterFile.open("critterData.txt"); //Placeholder until path of critter file is known.
	
	if (!critterFile)
	{
		cout << "Error opening data file" << endl;
	}
	
	int counter = 0;
	stringstream ss;
	int num;
	string temp;
	bool marker = false;
	
	while (getline(critterFile, critterData, ';'))
	{
		switch (counter)
		{
		case 0:
			ss.str(critterData);
			ss >> num;
			critter.setCritterID(num);
			break;
		case 1:
			critter.setName(critterData);
			break;
		case 2:
			critter.setCritterDescription(critterData);
			break;
		case 3:
			critter.setCritterShortDesc(critterData);
			break;
					
		//Unsure of keywords vector implementation
		case 4:
			ss.str(critterData);
			while (ss >> temp)
			{
				critter.keywords.push_back(temp);
			}
			break;
		case 5:
			ss.str(critterData);
			ss >> num;
			critter.setHealth(num);
			break;
		case 6:
			ss.str(critterData);
			ss >> num;
			critter.setDV(num);
			break;
		case 7:
			ss.str(critterData);
			ss >> num;
			critter.setSA(num);
			break;
		case 8:
			if (critterData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			critter.setEssential(marker);
			break;
		case 9:
			if (critterData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			critter.setInvincible(marker);
			break;
		case 10:
			if (critterData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			critter.setEvidence(marker);
			break;
		case 11:
			if (critterData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			critter.setAccused(marker);
			break;
		}
		counter++;
		
		if (counter > 11)
		{
			critterStorage.push_back(critter); 
			counter = 0;
		}
	}
}

/*********************************************
**loadItem
*********************************************/

void loadItem(Item &item, vector<Item> &itemStorage)
{
	string itemData;
	
	ifstream itemFile;
	itemFile.open("itemData.txt"); //Placeholder until path of item file is known.
	
	int counter = 0;
	stringstream ss;
	int num;
	bool marker = false;
	
	while (getline(itemFile, itemData, ';'))
	{
		switch (counter)
		{
			//starting with item id
		case 0:
			ss.str(itemData);
			ss >> num;
			item.setItemId(num);
			break;
		case 1:
			item.setName(itemData);
			break;
		case 2:
			item.setDesc(itemData);
			break;		
		case 3:
			item.setShort(itemData);
			break;
		case 4:
			ss.str(itemData);
			ss >> num;
			item.setScoreValue(num);
			break;
		case 5:
			if (itemData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			item.setCanCarry(marker);
			break;
		case 6:
			if (itemData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			item.setUsable(marker);
			break;
		case 7:
		if (itemData == "0")
			{
				marker = false;
			}
			else
			{
				marker = true;
			}
			item.setEdible(marker);
			break;
		}
		counter++;
		
		if (counter > 7)
		{
			itemStorage.push_back(item); 
			counter = 0;
		}
	}
}