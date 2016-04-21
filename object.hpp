#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Object
{
protected:

	std::string objectName;
	std::string objectDesc;
	int weight;
	int itemID;
	bool indestructable;

public:

	Object();
	~Object();
	void addItem(int itemID);   // add to inventory or room
	void removeItem(int itemID); // remove from inventory or room
	void destroyItem(int itemID); // remove from game world

};


#endif