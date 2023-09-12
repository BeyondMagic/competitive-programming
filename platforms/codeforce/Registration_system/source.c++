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

map<string, size_t> players;

int solve()
{
	string s;
	cin >> s;
	if (end(players) == players.find(s))
	{
		players.emplace(s, 0);
		return cout << "OK" << endl, 0;
	} else
		return cout << s + to_string(++players[s]) << endl, 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t;
	cin >> t;
	while (t--)
		solve();
}
