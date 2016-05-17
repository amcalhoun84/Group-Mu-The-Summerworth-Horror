
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;


int main()
{
	string line;
	stringstream ss;
	vector<string> objNum;
	vector<string> critterNum;
	vector<string> strDesc;
	int strInt;
	vector<int> objInt;
	vector<int> critterInt;
	

	
	ifstream roomDesc("demoRoom.txt");
	
	if(!roomDesc)
	{
		cout << "Error opening output file" << endl;
	}
	//add lines to string vector until sentry % is reached

	while (roomDesc.good())
	{
		for (int i=0; i<3; i++)
		{
			//add object id to vector
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() != 0)
				{
					objNum.push_back(line);
					line.clear();
					break;
				}
			}
			
			//add creatures to vector
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					critterNum.push_back(line);
					line.clear();
					break;
				}
			}
			//add description to vector
			while (getline(roomDesc, line, '%'))
			{
				if(line.length() > 1)
				{
					strDesc.push_back(line);
					line.clear();
					break;
				}
			}
		}
	}
	
	//display for testing of vector contents
	
	cout << endl;
	
	for (int i = 0; i < objNum.size(); i++)
	{
		ss.str(objNum[i]);
		ss >> strInt;
		objInt.push_back(strInt);
	}
	
	for (int i = 0; i < objInt.size(); i++)
	{
		cout << objInt[i];
		cout << endl;
	}
	
	cout << endl;
	
	for (int i = 0; i < critterNum.size(); i++)
	{
		ss.str(critterNum[i]);
		ss >> strInt;
		critterInt.push_back(strInt);
	}
	
	//cout << endl;

	for (int i = 0; i < critterInt.size(); i++)
	{
		cout << critterInt[i];
		cout << endl;
	}
	
		//cout << endl;

	for (int i = 0; i < strDesc.size(); i++)
		cout << strDesc[i];
	
	
	return 0;
}