/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n'

int solve ()
{
	double n, s, k;
	cin >> n >> s >> k;

	long long R = (long long)(n - s);

	int l = 0, r = INT_MAX;
	while (l < r)
	{
		long long m = (l + r) / 2;
		long long a = (long long)(n / k * double(m));
		if (a == R)
			return cout << "TEM" << endl, 0;
		else if (a < l)
			l = m + 1;
		else
			r = m;
	}

	return cout << -1 << endl, 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		solve();
}
