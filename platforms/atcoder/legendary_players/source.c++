#include <iostream>
#include <map>

using namespace std;

#define endl '\n'

int main()
{
	map<string, size_t> players {
		{ "tourist", 3858 },
		{ "ksun48", 3679 },
		{ "Benq", 3658 },
		{ "Um_nik", 3648 },
		{ "apiad", 3638 },
		{ "Stonefeang", 3630 },
		{ "ecnerwala", 3613 },
		{ "mnbvmar", 3555 },
		{ "newbiedmy", 3516 },
		{ "semiexp", 3481 },
	};

	string s;
	cin >> s;
	cout << players[s] << endl;

}
