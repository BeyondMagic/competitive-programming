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

int solve()
{
	size_t n, m;
	cin >> n >> m;
	vector<size_t> fs(m);
	for (auto &f : fs)
		cin >> f;
	sort(begin(fs), end(fs));

	size_t r = SIZE_MAX;
	vector<size_t> puzzles(n);
	for (size_t i = 0; i <= m - n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
			puzzles[j] = fs[i + j];
		r = min(r, *max_element(begin(puzzles), end(puzzles)) - *min_element(begin(puzzles), end(puzzles)));
	}
	cout << r << endl;
	return 0;
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
