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

#define UTP_RADIUS 10000

int T = 0;

auto solve ()
{
	int n, r, w, u, v;
	cin >> n >> r >> w >> u >> v;
	vector<pair<int, int>> towns(n);
	for (auto &[x, y] : towns)
		cin >> x >> y;
	double UTP = 0, FO = 0;

	sort(begin(towns), end(towns));
	debug(towns);
	debug(towns[(n - 1) / 2]);

	cout << "Caso #" << ++T << ": " << UTP << ' ' << FO << endl;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	cout << fixed << setprecision(3);
	while (t--)
		solve();
}
