#include "helper.h"
#include "graphics.h"
#include <string>

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
	int id = -1;
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

int getIdGet(vector<Item>& itemStorage, Room room, string keyword)
{
	int id = -1;
	int counter = 0;

	for (int i = 0; i < itemStorage.size(); i++)
	{
		for (int j = 0; j < itemStorage[i].keywords.size(); j++)
		{

			if (toUpperStr(itemStorage[i].keywords[j]) == keyword)
			{
				id = itemStorage[i].getItemId();

				if (room.hasItem(id))
				{
					counter++;
				}
			}
		}
	}

	if (counter > 1)
	{
		cout << "Please use a descriptive word with your noun and type it as one word. For example: skeletonkey" << endl;
		return -1;
	}
	else
	{
		for (int i = 0; i < itemStorage.size(); i++)
		{
			for (int j = 0; j < itemStorage[i].keywords.size(); j++)
			{

				if (toUpperStr(itemStorage[i].keywords[j]) == keyword)
				{
					id = itemStorage[i].getItemId();

					if (room.hasItem(id))
					{
						return id;
					}
					else
					{
						id = -1;
					}
				}
			}
		}
		return id;
	}
	
}

int getIdDrop(vector<Item>& itemStorage, Player player, string keyword)
{
	int id = -1;
	int counter = 0;

	for (int i = 0; i < itemStorage.size(); i++)
	{
		for (int j = 0; j < itemStorage[i].keywords.size(); j++)
		{

			if (toUpperStr(itemStorage[i].keywords[j]) == keyword)
			{
				id = itemStorage[i].getItemId();

				if (player.hasItem(id))
				{
					counter++;
				}
			}
		}
	}

	if (counter > 1)
	{
		cout << "Please use a descriptive word with your noun and type it as one word. For example: skeletonkey" << endl;
		return -1;
	}
	else
	{
		for (int i = 0; i < itemStorage.size(); i++)
		{
			for (int j = 0; j < itemStorage[i].keywords.size(); j++)
			{

				if (toUpperStr(itemStorage[i].keywords[j]) == keyword)
				{
					id = itemStorage[i].getItemId();

					if (player.hasItem(id))
					{
						return id;
					}
					else
					{
						id = -1;
					}
				}
			}
		}
		return id;
	}
}


string getItemDescription(vector<Item> &itemStorage, int id)
{

	string description = "";
	for (int i = 0; i < itemStorage.size(); i++)
	{
		if (itemStorage[i].getItemId() == id)
		{
			if(id == 38)
			{
				Graphics g;
				g.wallText();
			}
			if(id == 205)
			{
				Graphics g;
				g.noncursialBook();
			}
			if(id == 215)
			{
				Graphics g;
				g.noncursialAmulet();
			}
			description = itemStorage[i].getDesc();
		}
	}
	return description;
}

int checkLock(vector<Room> &roomStorage, Room &room)
{
	int id = -1;
	if (room.getNorth() != -1)
	{
		if (checkLock(roomStorage, room.getNorth()))
		{
			return room.getNorth();
		}
	}
	if (room.getSouth() != -1)
	{
		if (checkLock(roomStorage, room.getSouth()))
		{
			return room.getSouth();
		}
	}
	if (room.getEast() != -1)
	{
		if (checkLock(roomStorage, room.getEast()))
		{
			return room.getEast();
		}
	}
	if (room.getWest() != -1)
	{
		if (checkLock(roomStorage, room.getWest()))
		{
			return room.getWest();
		}
	}
	return id;
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


void setCritters(vector<Room> &roomStorage)
{
	roomStorage[21].setCritter(-1);
	roomStorage[32].setCritter(102);
	roomStorage[37].setCritter(103);

}

bool keyMatch(int lockedRoom, int key)
{
	if (key == 209)
	{
		if (lockedRoom == 5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (key == 210)
	{
		if(lockedRoom == 16 || lockedRoom == 18)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (key == 214)
	{
		if (lockedRoom == 33 )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (key == 217)
	{
		if (lockedRoom == 37)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false; //just in no key id matches
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
	
	room.setVisited(true);
}