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
	long long n;
	cin >> n;
	long long b = 0;
	static const long long p[5] = { 100, 20, 10, 5, 1};
	for (auto &i : p)
		b += n / i, n = n % i;

	cout << b << endl;
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
