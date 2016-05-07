#include <string>
#include <cstring>
#include <sstream>
#include <iostream>

#include "helperfuncs.hpp"


using namespace std;

int strToInt(string buffer)
{
	if(buffer.size() < 1) return 0;
	char b = buffer[0];
	int negative = 1, i = 0, t = 0;
	if(b=='-') { 
		negative = -1;
		if(buffer.size() == 1) 
			return 0;
		i=1;
	}

	for(i; i < buffer.size(); i++)
	{
		b = buffer[i];
		if(!isdigit(b)) break;
		t *= 10;
		t += b - '0';
	}

	return t * negative;
}

int findMax(int a, int b, int c, int d)
{
	if(a>=b && a>=c && a>=d) return a;
	if(b>=a && b>=c && b>=d) return b;
	if(c>=a && c>=b && c>=d) return c;
	if(d>=a && d>=b && d>=c) return d;
	return 0;
}

int replaceAll(string& buffer, char sub, char rep)
{
	int j=0;
	for(int i=0; i < buffer.size(); i++)
	{
		if(buffer[i] == sub) buffer[i] == rep;
			j++;
	}
	return j;
}

int replaceAllStr(string& buffer, string sub, string rep)
{
	int j=0;
	if(buffer.size() < sub.size()) return 0;
	for(int i=0; i < buffer.size(); i++)
	{
		if(buffer.substr(i, sub.size())==sub)
		{
			buffer = buffer.substr(0, i) + rep + buffer.substr(i+sub.size());
			i += rep.size() -1;
			j++;
		}
	}
	return j;
}

string toUpperStr(string buffer)
{
	for(int i=0; i<buffer.size(); i++)
		buffer.at(i) = toupper(buffer.at(i));
	return buffer;
}

string toLowerStr(string buffer)
{
	for(int i=0; i<buffer.size(); i++)
		buffer.at(i) = tolower(buffer.at(i));
	return buffer;
}

int removeFromVector(vector<int>& vec, int buffer)
{
	for(int i=0; i<vec.size(); i++)
		if(vec[i] == buffer)
		{
			for(int j=i; j<vec.size()-1; j++)
			{
				vec[j] = vec[j+1];
			}
			vec.pop_back();
			return 1;
		}
	return 0;
}

void pbIdx(vector<string> &vec, string buffer, int idx)
{
	if(vec.size() > idx + 1)
	{	
		vec[idx] = buffer;
		return;
	}

	while (vec.size() < idx)
		vec.push_back("");
	vec.push_back(buffer);
}

void pushstringIdx(vector<vector<string> > &vec, vector<string> buffer, int idx)
{
	if(vec.size() > idx) 
		return;
	while(vec.size() < idx)
		vec.push_back(vector<string> (16, ""));
	vec.push_back(buffer);
}

