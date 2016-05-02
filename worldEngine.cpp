#include <menu.h>
#include <unistd.h>
#include <ncurses.h>
#include "graphics.hpp"
#include "graphics.cpp"
#include <dirent.h>
#include <fstream>
#include "object.hpp"
#include "worldEngine.hpp"

using namespace std;

worldEngine::worldEngine()
{
	cout << "Instantiating game..." << endl;
	sleep(1);
	cout <<"Reticulating splines...." << endl;
	sleep(1);
	cout << "Loading game states..." << endl;
	sleep(1);
	cout <<"ZAAAALLLLGGGGOOOOOO!!!!!" << endl;

}

worldEngine::~worldEngine()
{
	cout << "Game is shutting down now!" << endl;
}

void worldEngine::display(int roomID, worldEngine wE)
{
	ifstream roomData;
	roomData.open("./rooms/" + roomID);

	if(roomData.is_open())
	{
		cout << "Yay room..." << endl;
	}

}

void worldEngine::manual()
{
	int lineCounter = 0;
	string line;
	ifstream manualFile;
	manualFile.open("manual.txt");

	if(manualFile.is_open())
	{
		while( getline (manualFile, line))
		{
			cout << line << endl;
		}

		getchar();

		manualFile.close();
	}

	else {
		cout << "Manual file not found." << endl;
		return;
	}

	return;
}


void worldEngine::playGame()
{

}

void worldEngine::loadGame(string gameName)
{
	DIR *dir;
	struct dirent *ent;

	ifstream gameState;
	gameState.open("saveState.txt");

	if(gameState.is_open())
		for(int i=0; i < GAMESIZE; i++)
		{
			cout << "Yea, loading a room..." << endl;
		}
	else
	{
		cout << "No game by that name exists." << endl;
		return;
	}


}

int main()
{
	int choice;
	DIR *dir;
	string dirName = "..";
	struct dirent *ent;

	string gameName;
	string choices[] = { "1. Start New Game",
						 "2. Load Game",
						 "3. Manual",
						 "4. Credits",
						 "// DEVS ONLY // ",
						 "5. Graphics Test",
						 "6. ZALGO!",
						 "// // // // //",
						 "0. Quit!"						 
						};

	Graphics grafix;
	worldEngine wE;
	// WINDOW *menu = newwin(0, 0, 0, 0);

	while(choice != 0)
	{

	cout << "----------------- GAME MENU ---------------------" << endl;
	for(int i=0; i < 9; i++)
	{
		cout << choices[i] << endl;
	}

	cout << "-------------------------------------------------" << endl;

	cout << "Make a choice >> " << endl;
	
	
		cin >> choice;

		switch(choice) {
			case 1:
				cout << "This doesn't do anything yet! But imagine a whole new game world spanning out before you." << endl;
				break;
			case 2: 
				cout << "Please type in the name of your game save." << endl;
				{
			/*	if((dir = opendir(dirName)) != NULL)
				{
					while((ent = readdir(dir)) != NULL)
					{
						cout << ent->d_name << endl;
					}

					closedir(dirName);*/

					cout << "Can't open games yet..." << endl;
				}

			/*	else 
				{
					cout << "Something went horrifically wrong." << endl;
					return 1;
				}*/

				cout << " >> " << endl;
				cin >> gameName;

				wE.loadGame(gameName);
				wE.display(0, wE);

				break;

			case 3:
				wE.manual();
				break;

			case 4:
				grafix.creditsScreen();
				break;

			case 0:
				cout << "Good bye." << endl;
				break;

			default:
				cout << "INVALID CHOICE" << endl;
				break;



		}
	}

	return 0;
}