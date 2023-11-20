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
