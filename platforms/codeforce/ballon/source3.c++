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

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<pair<int, int>> points{{
		{1, 4},
		{3, 5},
		{5, 8},
		{8, 2},
	}};

	auto p = pair<int, int>(0, 1);
	auto R = lower_bound(begin(points), end(points), p) - begin(points);
	int r = R == int(points.size()) or R < 0 ? -1 : R;
	debug(p, r);
}
