// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,tune=native")

/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>
// #include "debug.h"

using namespace std;

#define endl '\n'

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);

	size_t t;
	cin >> t;

	while (t--)
	{
		size_t n;
		cin >> n;
		vector<pair<long long, long long>> a(n + 1);
		vector<long long> ans(n + 1);

		for (size_t i = 1; i <= n; ++i)
			cin >> a[i].first, a[i].second = (long long)i;

		sort(begin(a) + 1, end(a));

		for (size_t i = 1; i <= n; ++i)
			a[i].first = (long long) n - (long long) i + 1, ans[size_t(a[i].second)] = a[i].first;

		for (size_t i = 1; i <= n; ++i)
			cout << ans[i] << ' ';
		putchar('\n');
	}
}
