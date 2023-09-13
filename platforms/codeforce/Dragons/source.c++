/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>
#include <ranges>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#define endl '\n'

int solve()
{
	size_t s, n;
	cin >> s >> n;
	vector<pair<size_t, size_t>> monsters(n);
	for (auto &m : monsters)
		cin >> m.first >> m.second;
	/*ranges::sort(monsters, [](const auto &a, const auto &b) {
		if (a.first <= b.first)
			return a.second < b.second;
		else
			return false;
	});*/
	ranges::sort(monsters);

	for (const auto &m : monsters)
		if (s > m.first)
			s += m.second;
		else
			return puts("NO"), 0;

	return puts("YES"), 0;
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
