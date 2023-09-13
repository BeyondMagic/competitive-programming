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

array<int, 5> groups{0};

int solve()
{
	size_t n, a;
	cin >> n;
	while (n--)
		cin >> a, ++groups[a];

	// 1 to 3
	int total = groups[4] + groups[3] + groups[2] / 2;
	groups[1] -= groups[3];

	// there is one two left
	if (groups[2] % 2 == 1)
		total += 1, groups[1] -= 2;

	if (groups[1] > 0)
		total += (groups[1] + 3) / 4;

	return cout << total << endl, 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	while (t--)
		solve();
}
