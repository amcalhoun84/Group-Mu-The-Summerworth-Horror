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
	ifstream roomDesc("demo.txt");
	//const string sentry = "%";
	
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
	
	while (getline(roomDesc,line))
	{
		itemLines.push_back(line);
	}
	
	for (int i = 0; i < roomLines.size(); i++)
		cout << roomLines[i] << endl;
	
	cout << "now for the items: " << endl;
	
	for (int i = 0; i < itemLines.size(); i++)
		cout << itemLines[i] << endl;
	
	cout << "Fin!" << endl;
	
	
	return 0;
}