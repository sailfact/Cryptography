#include <string>
#include <bitset>
#include <iostream>

using namespace std;

int main() 
{
	string myString;

	cout << "enter string for binary conversion\n>>";
	cin >> myString;	

	for (size_t i = 0; i < myString.size(); ++i)
	{
		cout << bitset<8>(myString.c_str()[i]) << endl;
	}
}
