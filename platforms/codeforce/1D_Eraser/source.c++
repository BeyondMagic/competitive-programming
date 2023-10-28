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
	size_t n, k;
	cin >> n >> k;
	string s; // length n, B a black cell, W a white cell
	cin >> s;
	size_t o = 0;
	for (size_t i = 0; i < n; ++i)
	{
		// start leftj
		if (s[i] == 'B')
		{
			debug(s);
			size_t left = i, right = i + k;
			for (size_t j = left; j < right and j < n; ++j)
				s[j] = 'W';
			i += k - 1;
			++o;
		}
	}

	return cout << o << endl, 0;
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
