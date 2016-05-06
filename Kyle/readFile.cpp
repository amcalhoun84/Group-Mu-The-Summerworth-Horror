#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


int main()
{
	string line;
	int item;
	vector<string> roomLines;
	vector<int> itemLines;
	ifstream roomDesc("demo.txt");
	
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
	
	while (roomDesc >> item)
	{
		itemLines.push_back(item);
	}
	
	for (int i = 0; i < roomLines.size(); i++)
		cout << roomLines[i] << endl;
	
	cout << "now for the items: " << endl;
	
	for (int i = 0; i < itemLines.size(); i++)
		cout << itemLines[i] << endl;
	
	cout << "Fin!" << endl;
	
	
	return 0;
}