
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


int main()
{
	string line;
	vector<string> roomLines;
	vector<string> itemLines;
	vector<string> directLines;
	vector<string> roomName;
	
	ifstream roomDesc("demoRoom.txt");
	
	if(!roomDesc)
	{
		cout << "Error opening output file" << endl;
	}
	//add lines to string vector until sentry % is reached
	while (getline(roomDesc, line, '%'))
	{
		roomLines.push_back(line);
		break;
	}
	//add items
	while (getline(roomDesc, line, '%'))
	{
		itemLines.push_back(line);
		break;
	}
	//add directions
	while (getline(roomDesc, line, '%'))
	{
		directLines.push_back(line);
		break;
	}
	//add room name
	while (getline(roomDesc, line, '%'))
	{
		roomName.push_back(line);
		break;
	}
	
	//display
	cout << endl;
	
	for (int i = 0; i < roomLines.size(); i++)
		cout << roomLines[i];
	
	cout << "now for the items: ";
	
	for (int i = 0; i < itemLines.size(); i++)
		cout << itemLines[i];

	cout << "\nnow for the directions: ";
	
	for (int i = 0; i < directLines.size(); i++)
		cout << directLines[i];
	
	cout << "\nroom name: ";
	
	for (int i = 0; i < roomName.size(); i++)
		cout << roomName[i];
	

	cout << "\n\n"; 
	return 0;
}