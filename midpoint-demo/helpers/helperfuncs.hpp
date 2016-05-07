#ifndef _HELPERFUNCS_HPP
#define _HELPERFUNCS_HPP

#include <string>
#include <sstream>
#include <fstream>
#include <queue>
#include <vector>
#include <iostream>
#define CONSOLEWIDTH 80

using namespace std;

int strToInt(string buffer);
int findMax(int a, int b, int c, int d);
string toUpperStr(string buffer);
string toLowerStr(string buffer);	// Make life easier. All inputs will be lower cased
// void fillVector(vector<string>& vec, string str);

int removeFromVector(vector<int> &vec, int buffer);
// int removeStringVector(vector <string> &vs, string buffer);

void pbIdx(vector<string> &vec, string buffer, int idx);
void pushstringIdx(vector<vector<string> > &vec, vector<string> buffer, int idx);


#endif // helperfuncs.hpp
