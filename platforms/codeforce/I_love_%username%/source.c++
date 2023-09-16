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
	size_t n;
	cin >> n;
	vector<size_t> contests(n);
	size_t a = 0;
	for (size_t i = 0; i < n; ++i)
	{
		cin >> contests[i];

		// coder's first contenst isn't considered amazing
		if (not i)
			continue;
		
		bool amazing1 = true, amazing2 = true;
		for (size_t j = 0; j < i and (amazing1 or amazing2); ++j)
		{
			// if for each past contest he earned more
			if (amazing1)
				amazing1 = contests[i] > contests[j];
			if (amazing2)
				amazing2 = contests[i] < contests[j];
		}
			
		if (amazing1 or amazing2)
		{
			debug(i + 1, amazing1, amazing2);
			++a;
		}

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
