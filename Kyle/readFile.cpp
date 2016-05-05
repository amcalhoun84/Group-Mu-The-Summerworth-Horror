#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


int main()
{
	string line;
	vector<string> roomLines;
	ifstream roomDesc("./rooms/" + _roomid);
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
	
	
	for (int i = 0; i < roomLines.size(); i++)
		cout << roomLines[i] << endl;
	
	return 0;
}