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
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	string s4 = s1 + s2;

	sort(begin(s3), end(s3));
	sort(begin(s4), end(s4));

	if (s3 == s4)
		return puts("YES"), 0;
	return puts("NO"), 0;
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
