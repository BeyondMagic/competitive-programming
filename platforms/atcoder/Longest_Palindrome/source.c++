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
	string s, s2;
	cin >> s;
	size_t m = 0;
	string a, b;
	const auto T = s.length();
	for (size_t i = 0; i < T; ++i)
	{
		for (size_t j = i; j < T; ++j)
		{
			b.push_back(s[j]);
			a = b;
			reverse(begin(a), end(a));
			if (a == b)
			{
				if (m < a.size())
				{
					debug(b);
					m = max(m, a.size());
				}
			}
		}
		b.clear();
	}

	return cout << m << endl, 0;
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
