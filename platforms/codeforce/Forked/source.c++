#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

auto solve ()
{
	int a, b;
	cin >> a >> b;
	pair<long long, long long> K, Q;
	cin >> K.first >> K.second;
	cin >> Q.first >> Q.second;

	array<pair<long long, long long>, 8> horse{{
		{-a, -b},
		{-a, b},
		{a, -b},
		{a, b},
		{b, a},
		{-b, a},
		{b, -a},
		{-b, -a},
	}};

	set<pair<long long, long long>> positions_K;
	for (auto &[x, y] : horse)
		positions_K.emplace(K.first - x, K.second - y);

	set<pair<long long, long long>> positions_Q;
	for (auto &[x, y] : horse)
		positions_Q.emplace(Q.first - x, Q.second - y);

	long long P = 0;

	for (auto &q : positions_Q)
		P += positions_K.find(q) == end(positions_K) ? 0 : 1;

	return P;
}
	// return - (int(positions.size()) - int(positions_K.size()) - int(positions_Q.size()));

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		cout << solve() << endl;
}
