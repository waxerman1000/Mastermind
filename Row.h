//Andrew Green
#ifndef ROW_H
#define ROW_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Row {
private:
	vector<char> theRow;
public:
	Row();
	void rewrite(string);
	bool compareTo(Row);
	char getPos(int);
	bool isValid(string str);

	friend ostream& operator<<(ostream& out, const Row& rhs) {
		string temp;
		for (int i = 0; i < 4; i++) {
			temp += rhs.theRow[i];
		}
		out << temp;
		return out;
	}

};


#endif