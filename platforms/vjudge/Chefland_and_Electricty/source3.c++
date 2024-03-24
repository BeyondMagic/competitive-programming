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

#define ENERGISED '1'

#define oo 1'000'000'000'000'000

struct UnionFind
{
	vector<int> parents, rank;

	UnionFind (int n) : parents(n), rank(n, 0)
	{
		iota(begin(parents), end(parents), 0);
	}

	bool same_set (int a, int b)
	{
		return find_set(a) == find_set(b);
	}

	void union_set (int a, int b)
	{
		if (same_set(a, b))
			return;

		int p = find_set(a),
			q = find_set(b);

		if (rank[p] > rank[q])
			parents[q] = p;
		else if (rank[q] > rank[p])
			parents[p] = q;
		else
			parents[q] = p,
			++rank[p];
	}

	int find_set (int a)
	{
		return parents[a] == a ? a : (parents[a] = find_set(parents[a]));
	}
};

int solve2 ()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<long long> dist(n);
	for (auto &d : dist)
		cin >> d;

	long long cost = 0;

	UnionFind ufds(n);

	// 00000000001...
	int l = 0;
	if (s[l] != ENERGISED)
	{
		for (; s[l + 1] != ENERGISED; ++l)
			ufds.union_set(l + 1, l),
			cost += dist[l + 1] - dist[l];
		++l;
		cost += dist[l] - dist[l - 1];
		ufds.union_set(l, l - 1);
	}

	// ...1000000000
	int r = n - 1;
	if (s[r] != ENERGISED)
	{
		for (; s[r - 1] != ENERGISED; --r)
			ufds.union_set(r, r - 1),
			cost += dist[r] - dist[r - 1];
		--r;
		cost += dist[r + 1] - dist[r];
		ufds.union_set(r + 1, r);
	}

	// ....100010000011110...
	for (int i = l; i <= r; ++i)
		if (s[i] != ENERGISED)
		{
			long long cl = oo,
					  cr = oo,
					  w = 0;
			int j;
			for (j = i; j <= r; ++j)
			{
				// first node
				if (j == i)
				{
					cl = dist[j] - dist[j - 1];
				}
				// last node
				else if (s[j] == ENERGISED)
				{
					cr = dist[j] - dist[j - 1];
					break;
				}
				// rest
				else
				{
					w += dist[j] - dist[j - 1];
					ufds.union_set(j, j - 1);
				}
			}
			debug(cl, cr, w);
			if (cl <= cr)
				ufds.union_set(i, i - 1),
				w += cl;
			else if (cr <= cl)
				ufds.union_set(j, j - 1),
				w += cr;
			else if (cr != oo)
				ufds.union_set(j, j - 1),
				w += cr;
			cost += w;
			i = j;
		}

	debug(l, r);
	debug(s[l], s[r]);

	for (int i = 0; i < n; ++i)
		ufds.find_set(i);

	debug(ufds.parents);
	debug(ufds.rank);
	return cost;
}

auto solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<long long> dist(n);
	for (auto &d : dist)
		cin >> d;

	long long cost = 0;

	// 000001........
	auto initial = int(s.find(ENERGISED));
	cost += dist[initial] - dist[0];

	// ........100000
	auto final = int(s.rfind(ENERGISED));
	cost += dist[n - 1] - dist[final];

	// 1....1
	for (int i = initial; i < final; ++i)
	{
		// right cost
		int l = i++;
		while (i <= final and s[i] != ENERGISED)
			++i;
		int r = i;

		// left cost find minimum
		long long w = oo;
		for (i = l; i < r; ++i)
			w = min(w, (dist[i] - dist[l]) + (dist[r] - dist[i+1]));

		cost += w;
		i = r - 1;
	}

	return cost;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		cout << solve() << endl;
}
