#include "helper.h"
#include<string>

using namespace std;

//Thanks for the helper function Andrew
string toUpperStr(string buffer)
{
	for (int i = 0; i<buffer.size(); i++)
		buffer.at(i) = toupper(buffer.at(i));
	return buffer;
}