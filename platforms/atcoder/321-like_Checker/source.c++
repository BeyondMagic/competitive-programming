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
	const auto n = s.length();
	for (size_t i = 0; i < n; ++i)
		for (size_t j = i + 1; j < n; ++j)
			if (s[j] >= s[i])
				return puts("No"), 0;

	return puts("Yes"), 0;
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
