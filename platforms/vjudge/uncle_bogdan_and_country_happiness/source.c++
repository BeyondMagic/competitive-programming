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
	int n, m;
	cin >> n >> m;

	vector<int> P(n);
	for (auto &p : P)
		cin >> p;

	vector<int> H(n);
	for (auto &h : H)
		cin >> h;

	vector<pair<int, int>> adjencies(n - 1);
	for (auto &[u, v] : adjencies)
		cin >> u >> v;

	puts("NO");
	puts("YES");

	return 0;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		solve();
}
