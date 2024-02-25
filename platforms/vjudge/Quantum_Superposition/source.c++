/**
	 *	author:		mathbergsant, beyondmagic
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

#define MAX 1000 * 2000

bitset<MAX> visited;

void dist(vector<vector<int>> &graph, set<int> &result, int u, int d, int k)
{
	// base case
	if (visited[u] or u == k)
	{
		result.insert(d);
		return;
	}

	// processing
	visited[u] = true;
	// result.insert(d);

	// keep recursiving (engrish)
	for (auto &v : graph[u])
		dist(graph, result, v, d + 1, k);
}

set<int> combine (set<int> &A, set<int> &B)
{
	set<int> C;
	for (auto &a : A)
		for (auto &b : B)
			C.insert(a + b);
	return C;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n1, n2, m1, m2;
	cin >> n1 >> n2 >> m1 >> m2;

	vector<vector<int>> A(n1 + 1, vector<int>());
	vector<vector<int>> B(n2 + 1, vector<int>());
	for (int i = 1, u, v; i <= m1; ++i)
		cin >> u >> v,
			A[v].emplace_back(u);

	for (int i = 1, u, v; i <= m2; ++i)
		cin >> u >> v,
			B[v].emplace_back(u);

	set<int> A_dist, B_dist;
	dist(A, A_dist, n1, 0, 1);
	visited.reset();
	dist(B, B_dist, n2, 0, 1);

	auto result = combine(A_dist, B_dist);

	int k;
	cin >> k;
	while (cin >> k)
		puts(result.find(k) != end(result) ? "Yes" : "No");
}
