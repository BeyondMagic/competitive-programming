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
#define oo 1e9

int solve()
{
	size_t M;
	cin >> M;
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int ans = oo;
	for (size_t i = 0; i < 3 * M; ++i)
		for (size_t j = 0; j < 3 * M; ++j)
			for (size_t k = 0; k < 3 * M; ++k)
				if (i != j and i != k and j != k and s1[i % M] == s2[j % M] and s2[j % M] == s3[k % M])
				{
					ans = min(ans, int(max({i, j, k})));
				}
	debug(ans, oo);
	if (ans < oo)
		return cout << ans << endl, 0;
	return cout << -1 << endl, 0;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t T = 1;
	// cin >> t;
	while (T--)
		solve();
}
