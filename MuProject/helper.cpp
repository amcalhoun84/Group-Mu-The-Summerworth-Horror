#include "helper.h"
#include<string>

using namespace std;

string toUpperStr(string buffer)
{
	for (int i = 0; i<buffer.size(); i++)
		buffer.at(i) = toupper(buffer.at(i));
	return buffer;
}

bool isEdible(vector<Item> &itemStorage, int id)
{
	for (int i = 0; i < itemStorage.size(); i++)
	{
		if (itemStorage[i].getItemId() == id)
		{
			return itemStorage[i].getEdible();
		}
	}
	return false;
}

bool canCarry(vector<Item> &itemStorage, int id)
{
	for (int i = 0; i < itemStorage.size(); i++)
	{
		if (itemStorage[i].getItemId() == id)
		{
			return itemStorage[i].getCanCarry();
		}
	}
	return false;
}

string getItemName(vector<Item> &itemStorage, int itemId)
{
	string itemName = "";
	for (int j = 0; j < itemStorage.size(); j++)
	{
		if (itemId == itemStorage[j].getItemId())
		{
			itemName = itemStorage[j].getName();
		}
	}
	return itemName;
}

int getItemId(vector<Item> &itemStorage, Room &room, string item)
{
	int id = 0;
	vector<int> items;

	bool endLoop = false;
	room.getItemsVector(items);


	for (int i = 0; i < itemStorage.size(); i++)
	{
		for (int j = 0; j < itemStorage[i].keywords.size(); j++)
		{

			if (toUpperStr(itemStorage[i].keywords[j]) == item)
			{
				id = itemStorage[i].getItemId();
				for (int k = 0; k < items.size(); k++)
				{
					if (id == items[k])
					{
						return id;
					}
				}
			}
		}
	}
	return id;
}

int getPlayerItemId(vector<Item> &itemStorage, Player &player, string item)
{
	int id = 0;
	vector<int> items;

	bool endLoop = false;
	player.getItemsVector(items);


	for (int i = 0; i < itemStorage.size(); i++)
	{
		for (int j = 0; j < itemStorage[i].keywords.size(); j++)
		{

			if (toUpperStr(itemStorage[i].keywords[j]) == item)
			{
				id = itemStorage[i].getItemId();
				for (int k = 0; k < items.size(); k++)
				{
					if (id == items[k])
					{
						return id;
					}
				}
			}
		}
	}
	return id;
}

int getIdFromItemVector(vector<Item> &itemStorage, string keyword)
{
	int id = -1;

	for (int i = 0; i < itemStorage.size(); i++)
	{
		for (int j = 0; j < itemStorage[i].keywords.size(); j++)
		{

			if (toUpperStr(itemStorage[i].keywords[j]) == keyword)
			{
				id = itemStorage[i].getItemId();
				//Makes sure knife is correct for get and drop commands
				if (id == 3 || id == 208)
				{
					for (int k = 0; k < itemStorage[i].keywords.size(); k++)
					{
						if (itemStorage[i].keywords[k] == "bowie")
						{
							return 3;
						}
						else if (itemStorage[i].keywords[k] == "dagger")
						{
							return 208;				
						}
					}
				}
				else if (id == 209 || id == 214 || id == 217) //Makes sure key is correct for get and drop commands
				{
					for (int k = 0; k < itemStorage[i].keywords.size(); k++)
					{
						if (itemStorage[i].keywords[k] == "skeleton")
						{
							return 209;
						}
						else if (itemStorage[i].keywords[k] == "ritual")
						{
							return 214;
						}
						else if (itemStorage[i].keywords[k] == "dagger")
						{
							return 217;
						}
					}
				}
				else if (id == 205 || id == 211 ) //Makes sure book is correct for get and drop commands
				{
					for (int k = 0; k < itemStorage[i].keywords.size(); k++)
					{
						if (itemStorage[i].keywords[k] == "leather")
						{
							return 205;
						}
						else if (itemStorage[i].keywords[k] == "strange")
						{
							return 211;
						}
					}
				}
			}
		}
	}
	return id;
}

string getItemDescription(vector<Item> &itemStorage, int id)
{
	string description = "";
	for (int i = 0; i < itemStorage.size(); i++)
	{
		if (itemStorage[i].getItemId() == id)
		{
			description = itemStorage[i].getDesc();
		}
	}
	return description;
}

bool checkLock(vector<Room> &roomStorage, int id)
{
	for (int i = 0; i < roomStorage.size(); i++)
	{
		if (roomStorage[i].getRoomId() == id)
		{
			return roomStorage[i].getLocked();
		}
	}
	return false; //If id doesn't match for some reason, this stops program from crashing (and gets rid of warning)
}
void unLock(vector<Room> &roomStorage, int id)
{
	for (int i = 0; i < roomStorage.size(); i++)
	{
		if (roomStorage[i].getRoomId() == id)
		{
			roomStorage[i].setLocked(false);
		}
	}
}

void setCritters(vector<Room>& roomStorage)
{
	for (int i = 0; i < roomStorage.size(); i++)
	{
		roomStorage[i].setCritter(-1);
	}
	roomStorage[12].setCritter(100);
	roomStorage[21].setCritter(102);
	roomStorage[25].setCritter(101);
	roomStorage[33].setCritter(104);
}
void setCritters2(vector<Room> &roomStorage)
{
	roomStorage[21].setCritter(-1);
	roomStorage[32].setCritter(102);
	roomStorage[37].setCritter(103);

}

void displayRoom(vector<Room> &roomStorage, vector<Item> &itemStorage, vector<Critter> &critterStorage, Player &player, Room &room, int id)
{
	for (int i = 0; i < roomStorage.size(); i++)
	{
		if (roomStorage[i].getRoomId() == id)
		{
			room = roomStorage[i];
		}
	}

	room.displayName();
	cout << endl;
	if (!room.getDark() || player.getHasLight())
	{
		room.displayDesc();
		cout << endl;
		room.displayRoomItems(itemStorage);
		room.displayCritter(critterStorage);
		cout << endl;
		room.displayDirections();
		cout << endl;
	}
	else
	{
		cout << "It's dark and you can't see anything!" << endl;
	}
	

}