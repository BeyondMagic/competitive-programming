/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#define endl '\n'


constexpr static size_t MIN = 10;
constexpr static size_t MAX = 20000 + MIN;

//                        colour, edges
typedef vector<pair<size_t, vector<size_t>>> Graph;

bitset<MAX> visited;
void dfs (size_t u, size_t &colour, Graph &vertices)
{
	if (visited[u])
		return;

	visited[u] = true;
	vertices[u].first = colour;

	for (auto &vertex : vertices[u].second)
		dfs(vertex, colour, vertices);
}

/*
bitset<MAX> nei;
void color (size_t r, vector<size_t> &colours, Graph &vertices)
{
	if (nei[r] or (not vertices[r].second.size() and vertices[r].first == colours[r]))
		return;

	nei[r] = true;
	++g;
	dfs(r, colours[r], vertices);

	// verify if all vertices have correct colors.
	bool stop = true;

	for (size_t j = 1; j <= n and stop; ++j)
		stop = vertices[j].first == colours[j];

	if (stop)
		cout << g << endl, exit(0);

	visited.reset();

	for (auto &vertex : vertices[r].second)
	{
		debug(vertex, g);
		color(vertex, colours, vertices);
	}

}*/

/*vector<size_t> bfs (size_t root, Graph &vertices)
{
	vector<size_t> roots;

	priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> next;
	next.push({root, vertices[root].second.size()});

	while (not next.empty())
	{
		const auto [u, s] = next.top();
		next.pop();

		for (auto &n : vertices[u].second)
		{
			debug(n, vertices[n].second.size());
			next.push({n, vertices[n].second.size()});
		}

		roots.emplace_back(u);
		debug(roots);
	}

	return roots;
}*/

/*
int solve()
{
	size_t n;
	cin >> n;
	//          colour, edges
	Graph vertices(n + 1, {0, {}});
	vector<size_t> roots;
	vector<bool> vis(n + 1, false);
	size_t roots_n = 0;

	// read edges
	for (size_t i = 2, p; i <= n; ++i)
	{
		cin >> p;
		// vertices[i].second.emplace_back(p);
		vertices[p].second.emplace_back(i);
		roots.emplace_back(p);
		++roots_n;
	}

	// read colours
	vector<size_t> colours(n + 1);
	for (size_t i = 1, c; i <= n; ++i)
		cin >> c, colours[i] = c;

	size_t g = 0;
	for (size_t i = 0; i < roots_n; ++i)
	{
		const auto &r = roots[i];

		if (vis[r] or colours[r] == vertices[r].first)
			continue;

		// debug(r);
		vis[r] = true;
		++g;
		dfs(r, colours[r], vertices);

		bool stop = true;
		for (size_t j = 1; j <= n; ++j)
		{
			if (colours[j] != vertices[j].first)
			{
				stop = false;
				// magical trick
				if (i + 1 == roots_n)
				{
					// debug("extra", j);
					++g;
				}
				else
					break;
			}
		}
		// debug("run");
		//for (size_t x = 1; x <= n; ++x)
		//{
		//	debug(x, colours[x], vertices[x]);
		//}
		if (stop)
			break;
		visited.reset();
	}

	return cout << g << endl, 0;
}*/

int solve ()
{
	size_t n;
	cin >> n;

	vector<pair<size_t, vector<size_t>>> vertices(n + 1, {0, {}});
	for (size_t i = 2, p; i <= n; ++i)
		cin >> p, vertices[p].second.emplace_back(i);

	vector<size_t> colours(n + 1);
	for (size_t i = 1; i <= n; ++i)
		cin >> colours[i];

	vector<size_t> roots{1};
	for (size_t i = 1; i <= n; ++i)
		for (auto &root : vertices[i].second)
			roots.emplace_back(root);

	size_t a = 0;
	
	const auto &s = roots.size();
	for (size_t u = 0; u < s; ++u)
	{
		const auto &i = roots[u];

		// If root colour is correct, ignore.
		if (vertices[i].first == colours[i])
			continue;

		// Colour all below with the same colour.
		++a;
		debug(i);
		dfs(i, colours[i], vertices);
		visited.reset();

		// Verify all colours of all nodes.
		bool correct = true;
		// Continue loop if it is the last root node or if all nodes are correct.
		for (size_t k = 1; k <= n and (correct or i + 1 == s); ++k)
		{
			if (vertices[k].first != colours[k])
			{
				correct = false;
				if (u + 1 == s)
				{
					debug(k);
					++a;
				}
			}
		}
		if (correct)
			break;
	}

	return cout << a << endl, 0;
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
