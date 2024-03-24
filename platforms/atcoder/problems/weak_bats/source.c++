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
	string s;
	cin >> s;
	for (size_t i = 0; i < s.length(); ++i)
		if (i & 1 and s[i] != '0')
			return cout << "No" << endl, 0;

	return cout << "Yes" << endl, 0;
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
