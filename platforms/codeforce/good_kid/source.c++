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
	vector<size_t> A(n);
	for (size_t i = 0; i < n; ++i)
		cin >> A[i];
	const auto m = min_element(begin(A), end(A));
	size_t M = *m;
	A.erase(m);
	size_t a = M + 1;
	for (auto &e : A)
		a *= e;

	return cout << a << endl,  0;
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
