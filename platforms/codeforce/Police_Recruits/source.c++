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
	int n;
	cin >> n;
	size_t p = 0, // agents
		   a = 0; // total of untreated crimes
	while (cin >> n)
	{
		if (n == -1)
		{
			if (not p)
				++a;
			else
				--p;
			continue;
		}
		p += size_t(n);
	}
	return cout << a << endl, 0;
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
