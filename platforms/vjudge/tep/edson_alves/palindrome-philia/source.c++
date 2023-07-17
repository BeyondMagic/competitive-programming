#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

int main()
{
	string s;
	cin >> s;
	auto length = s.length();
	// if string is odd, we erase the center character.
	if (length & 1)
		// we also subtract one from the original length
		s.erase(length-- / 2, 1);
	// string even, we take half and reverse it
	auto half = s.substr(length / 2, length - 1);
	reverse(begin(half), end(half));
	// then we count how many characters are different from original
	size_t difference = 0;
	for (auto i = 0; i < length / 2; ++i)
		if (s[i] != half[i])
			++difference;
		
	cout << difference << endl;
}
