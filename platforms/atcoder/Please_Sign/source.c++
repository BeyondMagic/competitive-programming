#include <bits/stdc++.h>

using namespace std;

#ifdef local
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

void dfs (int u, vector<vector<long long>> &G, vector<long long> &A, vector<long long> &B, vector<long long> &D)
{
	B[D[u]] += A[u];

	for (int v : G[u])
		D[v] = D[u] + 1,
		dfs(v, G, A, B, D);
}

auto solve ()
{
	long long n;
	cin >> n;

	vector<long long> A(n + 2);
	for (int i = 1; i <= n; ++i)
		cin >> A[i];

	vector<vector<long long>> G(n + 3);
	for (int i = 2, p; i <= n; ++i)
		cin >> p,
		G[p].emplace_back(i);

	vector<long long> D(n + 3), B(n + 3);
	dfs(1, G, A, B, D);
	debug(B);

	for (int i = n; ~i; --i)
		if (B[i])
			return B[i] > 0 ? '+' : '-';
	return '0';
}

int main ()
{
	cout << solve() << endl;
}
