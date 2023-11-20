/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;
	vector<vector<int>> grid(h, vector<int>(w));
	int mn = INT_MAX / 2;
	for (auto &line : grid)
		for (auto &e : line)
		{
			cin >> e;
			mn = min(mn, e);
		}

	debug(mn);

	int t = 0;
	for (auto &line : grid)
		for (auto &e : line)
		{
			t += e - mn;
		}

	cout << t << endl;

}
