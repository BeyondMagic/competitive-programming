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

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s, m, l;
	cin >> n >> s >> m >> l;
	if (not (n % 6))
		return cout << (n / 6) * s << endl, 0;
	else if (not (n % 8))
		return cout << (n / 8) * m << endl, 0;
	else if (not (n % 12))
		return cout << (n / 12) * l << endl, 0;
	int mn = INT_MAX, cost = -1, k = INT_MAX;
	array<int, 3> ks{{6, 8, 12}};

	for (auto &K : ks)
		if (mn > K - n % K or (mn == K - n % K and s < k))
		{
			k = K;
			mn = n % K;
			cost = s;
		}
	cout << (n / k) * cost << endl;
}
