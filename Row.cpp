//Andrew Green
#include "Row.h"

Row::Row()
{
}

void Row::rewrite(string s)
{
	//changes the row's current vector into a new one
	//where each letter from the string is a spot in
	//the vector
	theRow.clear();
	for (int i = 0; i < 4; i++) {
		theRow.push_back(s[i]);
	}
}

bool Row::compareTo(Row r)
{
	//checks the similarity between two rows, outputting
	//a black for every matching color and position,
	//and a white for every matching color, but mismatching
	//postition
	int exactMatches = 0;
	int matchingColors = 0;
	vector<int> whitelist1;
	vector<int>whitelist2;
	for (int i = 0; i < 4; i++) {
		if (theRow[i] == r.getPos(i)) {
			exactMatches++;
			whitelist1.push_back(i);
			whitelist2.push_back(i);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (find(whitelist1.begin(), whitelist1.end(), i) == whitelist1.end()) {
			for (int k = 0; k < 4; k++) {
				if ((theRow[i] == r.getPos(k)) && (find(whitelist2.begin(), whitelist2.end(), k) == whitelist2.end())) {
					matchingColors++;
					whitelist1.push_back(i);
					whitelist2.push_back(k);
				}
				else {

				}
			}
		}
		else {
		}
	}
	cout << "        " << exactMatches << " blacks, " << matchingColors << " whites. ";
	
	if (exactMatches == 4) { return true; }
	return false;
}

char Row::getPos(int i)
{
	return theRow[i];
}

bool Row::isValid(string str)
{
	//checks if the row is valid (no outstanding colors,
	//no more/less than 4 characters)
	int temp = 0;
	if (str.size() != 4) { return false; }
	for (int i = 0; i < 4; i++) {
		if (str[i] == 'r' ||
			str[i] == 'g' ||
			str[i] == 'b' ||
			str[i] == 'y' ||
			str[i] == 'o' ||
			str[i] == 'p' ||
			str[i] == 'v' ||
			str[i] == 't') {
			temp++;
		}
	}
	if (temp == 4) { return true; }
	return false;
}
