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
	if (s == "abc" or s == "acb" or s == "bac" or s == "cba")
		return puts("YES"), 0;
	return puts("NO"), 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	cin >> t;
	while (t--)
		solve();
}
