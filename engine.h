// Engine Preliminaries and Structs
// baseClasses.h

#include <sys/types.h>
#include <sys/stat.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <curses.h>
#include <errno.h>
#include <string>
#include <vector>

 
#ifndef ENGINE_H
#define ENGINE_H

#define DESCBUFFER 1024 // limit descriptions to 1024 characters.
#define TOKENBUFFER 256 // limit the buffer to 256 characters. if Buffer is greater than, alert user to use simpler commands.
#define MAXWTLIMIT 60 // maximum weight you can carry
#define COMMANDHASHSIZE 26 * 26 + 1;


class Creature	// Base class for all creatures.
{
private:
	int hitPoints;
	int attackValue;
	int defensePoints;

	string name;
	string description;

	bool wanders;	// Does it wander the mansion
	bool essential; // can you attack or kill it? Y/N
	bool favorsDark; // If you are using a flashlight or cellphone light, does it run away?
	bool deadOrAlive;   // Dead or Alive. If Dead, remove from gamestate and place corpse object.
	bool immuneRegularAttack;	// Do you need a special item to hurt it?

public:	

	int attackPlayer();
	void talkPlayer();
	void actionResponses();
	char wander(); // randomized wandering algorithm

};


class Object  // we will break down some of these into the subclasses of object
{
private:

	string itemName; 
	string itemDescription;

	int weight;		  // You have a limited amount of weight you can carry.
	int attackDice;  // randomized on 1d4, 1d6, or 1d8... and so on.
	int pointValue; // How many points is it worth to have?

	bool holy;		// Does it banish the unspeakable horror?
	bool silver;	// can it harm the unspeakable horror?
	bool evidence; // Evidence doubles point value when put back into the
					// car. 
	bool weapon;   // relevant for attack dice
	bool canGet;	// can you get or pick up item?

	bool indestructible; // for things like benches, trees, etc. 

public:
	bool exist(string itemName); // does it exist or not? Is it placed in the evidence hold? (If so, does not exist);
	void getItem(string itemName); // places the item in player inventory;
	void dropItem(string itemName); // removes from the player inventory 
};

class Player
{
public:
	~Player()
	~Player();

private:
	string name;
	int genderMF; // male = 0, female = 1
	int currentCarryWeight;

	bool onQuest; 
}

class WorldEngine
{
private:
	
	pid_t pid; // process id... gotta have a process id!

	int score;
	int moves;
	int moveValue;

	string dirName;

	// game state.

	bool mysteryStarted;
	bool horrorDead;
	bool horrorBanished;
	bool dayOrNight;	// at some point, the game will turn to night.
	bool playerDead; // oops... game over! Display Death image.
	bool gameOver;
	bool gameWon;

	// Helper Functions

	string introduction[1]; // An array containing the title card, instructions, story.

	int roomItemCount;
	vector<int> inventory;
	vector<int> 

	int currentRoom;
	int startRoom;
	vector<int> movesMade; 

	CommandHash commandsHash[COMMANDHASHSIZE];
	vector<Room> rooms;
	vector<Creature> creatures;
	vector<Object> objects; // all rooms, creatures, and items



public:
	void accessRoom(char *dirName, int roomID);
	void playGame();
	void newGame();		// erases the game state, resets the game.
	void loadGame();	// loads the game state.
	void saveGame();	// reads the game state and writes it to savefile.
	readRoomFile(string dirName, int roomID); // reads the room file to the parser
	void interface(); // contains the primary interface functions
	void display();   // game display
	void displayArt(std::vector<int> art, int id);  // displays art based on the game state and room. -- find the art vector and load from there.

	void addObject(int id);
	void removeObject(int id);
	void addToInventory(int id);
	void showInventory();
	void setEquipped(int id;)





};

#endif