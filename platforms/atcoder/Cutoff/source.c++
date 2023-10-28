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
	int x;
	cin >> n >> x;
	vector<int> A(n - 1);
	for (auto &a : A)
		cin >> a;
	ranges::sort(A);
	debug(A);
	int sum = accumulate(begin(A) + 1, end(A) - 1, 0);
	debug(sum);
	int left = x - sum;
	debug(left);
	if (left > 100)
		return cout << -1 << endl, 0;
	else if (left == 100 and sum + A[n - 2] >= x)
		return cout << 0 << endl, 0;
	return cout << left << endl, 0;
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
