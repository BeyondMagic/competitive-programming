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

void solve()
{
	size_t n;
	cin >> n;
	cout << (n - 1) / 2 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t;
	cin >> t;
	while (t--)
		solve();
}
