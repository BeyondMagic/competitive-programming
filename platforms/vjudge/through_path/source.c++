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

	// tree algorithm // graph algorithm
	int n;
	cin >> n;

	// looks like an implementation problem.
	// can't see a direct algorithm here...
	// perhaps we need a strategy for each query, but forget that for now.
	vector<int> V(n);
	iota(begin(V), end(V), 1);

	vector<pair<int, int>> edges(n - 1);
	for (auto &[a, b] : edges)
		cin >> a >> b;

	// queries we need to act
	int q;
	cin >> q;
	while (q--)
	{
		
	}
}
