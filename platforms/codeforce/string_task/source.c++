#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
	const string vowels = "aeiouy";
	string s;
	cin >> s;
	erase_if(s, [&vowels] (const char c) {
		return vowels.find(char(tolower(c))) != string::npos;
	});
	for (const auto c : s)
		cout << '.' << char(tolower(c));
	cout << endl;
}
