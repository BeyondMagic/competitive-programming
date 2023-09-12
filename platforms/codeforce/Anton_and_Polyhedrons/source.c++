/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#define endl '\n'

map<string, size_t> table{
	{"Tetrahedron", 4},
	{"Cube", 6},
	{"Octahedron", 8},
	{"Dodecahedron", 12},
	{"Icosahedron", 20},
};

void solve()
{
	size_t n;
	cin >> n;
	size_t t = 0;
	string s;
	while (cin >> s)
		t += table[s];
	cout << t << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	// cin >> t;
	while (t--)
		solve();
}
