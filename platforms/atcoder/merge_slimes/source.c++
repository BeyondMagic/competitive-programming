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

typedef long long ll;

int solve()
{
	size_t n; cin >> n;
	vector<pair<ll, ll>> slimes(n, make_pair(0, 0));
	{
		ll s, c;
		for (size_t i = 0; i < n; ++i)
		{
			cin >> s >> c;
			slimes[i].first = s,
			slimes[i].second = c;
		}
	}

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
