#include <iostream>

#define SHIFT 3

using namespace std;

string encrypt(string text);
string decrypt(string text); 

int main() {
	string e, d;
	
	cout << "enter text to encrypt\n>>>";
	cin >> e;
	
	cout << "encrypting...\n";

	e = encrypt(e);

	cout << e <<endl;

	cout << "decrypting..\n";

	d = decrypt(e);

	cout << d <<endl;

	return 0;
}

string encrypt(string text) {
	string output = "";
	
	for( int i=0; i <text.length(); i++) {
		if (isupper(text[i])) {
			output += char(int(text[i]+SHIFT-65)%26 +65);
		} else {
			output += char(int(text[i]+SHIFT-97)%26 +97);
		}
	}

	return output;
}

string decrypt(string text) {
	string output = "";
	
	for (int i = 0; i < text.length(); i++) {
		if (isupper(text[i])) {
			output += char(int(text[i]-SHIFT-65)%26 +65);
		} else {
		
		}	output += char(int(text[i]-SHIFT-97)%26 +97);
	}

	return output;
}
