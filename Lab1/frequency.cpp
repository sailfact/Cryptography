#include <iostream>
#include <fstream>
#include <ctype.h>
#include <map>

using namespace std;

static map<char, int> m;

void catalouge(char c) {
	char key = tolower(c);
	int count = 1;

	if (m.count(key) > 0) {
		m.at(key) ++;
	} else {
		m.insert(pair<char,int>(key, count));
	}
}

void print_map() {
	map<char, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
		cout << it->first << " :: " << it->second << endl;
}

int main(int argc, const char **argv) {
	ifstream is(argv[1]);	// open file stream
	char c;

	while(is.get(c)) {
		if (isalpha(c))		// check if letter is in alphabet
			catalouge(c);	// catalouge the letter
	}

	print_map();	// print out map

	is.close();	// close file stream

	return 0;
}
