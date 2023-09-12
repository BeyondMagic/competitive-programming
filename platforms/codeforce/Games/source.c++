/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;

#define endl '\n'

void solve()
{
	size_t n;
	cin >> n;

	vector<pair<int, int>> stadiums(n);
	for (auto &[home, guest] : stadiums)
		cin >> home >> guest;

	size_t ans = 0;
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			if (stadiums[i].first == stadiums[j].second and i != j)
				ans++;
	cout << ans << endl;
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
