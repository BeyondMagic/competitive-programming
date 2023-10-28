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

/*int solve()
{
	size_t n; // number of columns
	long long x; // maximum amount of water I can use
	cin >> n >> x;
	vector<long long> coral(n);
	// size_t s = 0;
	for (auto &e : coral)
	{
		cin >> e;
		// s += e;
	}
	// maybe binary search
	// sort(begin(coral), end(coral));

	long long left = 1, right = LONG_MAX;
	// debug(right);
	long long ans = LONG_MAX; // oo
	while (left <= right)
	{
		long long normaliser = 0;
		// forget maximu, try fixing middle point
		long long m = (right - left) / 2 + left;
		for (auto &e : coral)
		{
			// passed the height of our fence
			if (m > e)
			{
				debug(e);
				normaliser += (m - e);
				break;
			}
		}

		// debug(amount_w);

		// passed the amount of water we can use
		if (normaliser <= x)
		{
			debug(ans);
			ans = m;
			left = m + 1;
		} else {
			debug(normaliser);
			// saves the new height
			// break;
			right = m - 1;
		}
	}

	return cout << ans << endl, 0;
}*/

int solve ()
{
	size_t n;
	long long x;
	cin >> n >> x;
	vector<long long> ans(n);
	for (size_t i = 0; i < n; ++i)
		cin >> ans[i];
	long long left = 1, right = INT_MAX;
	long long answer = INT_MAX;
	while (left <= right)
	{
		long long mid = (right - left) / 2 + left;
		long long res = 0;
		for (long long &e : ans)
			if (mid > e)
				res += mid - e;
		if (res <= x)
		{
			answer = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}

	}

	return cout << answer << endl, 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t;
	cin >> t;
	// t = 4;
	while (t--)
		solve();
}
