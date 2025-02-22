#include "library.hpp"

using namespace std;

int main ()
{
	string s;
	cin >> s;

	map<string, string> ans = {
		{"N", "S"},
		{"E", "W"},
		{"W", "E"},
		{"S", "N"},
		{"NE", "SW"},
		{"NW", "SE"},
		{"SE", "NW"},
		{"SW", "NE"},
	};

	print << ans[s] << endl;
}
