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
	double n;
	cin >> n;
	double a = 0, b;
	while (cin >> b)
		a += b / n;
	return cout << a << endl, 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(6);

	size_t t = 1;
	// cin >> t;
	while (t--)
		solve();
}
