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

inline bool is_active (int &n, int &k)
{
	return (n >> k) & 1;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> V(n);
	for (auto &v : V)
		cin >> v;

	int i = 0;
	do {
		int a = 0;
		for (int j = 0; j < n; ++j)
			a += is_active(i, j) ? V[j] : -V[j];

		if (a == m)
			return puts("SIM"), 0;
	} while (i < 1 << n and ++i);
	puts("NAO");
}
