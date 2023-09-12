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
	vector<pair<int, size_t>> odd, even;
	int b;
	for (size_t i = 1; cin >> b; ++i)
		if (b & 1)
			odd.emplace_back(b, i);
		else
			even.emplace_back(b, i);
	if (odd.size() == 1)
		cout << odd[0].second << endl;
	else
		cout << even[0].second << endl;
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
