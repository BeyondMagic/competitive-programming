#include "library.hpp"

using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

bool dfs_cycle(int u, int p = -1)
{
    if (visited[u])
        return false;

    visited[u] = true;

    for (auto v : adj[u])
    {
        if (visited[v] and v != p)
            return true;

        if (dfs_cycle(v, u))
            return true;
    }

    return false;
}

int main ()
{
	auto [n, m] = read<int, int>();

	adj.assign(n + 1, vector<int>());

	for (int a, b; cin >> a >> b;)
	{
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	
		// Caso base: se passar de dois já dá errado.
		if (adj[a].size() > 2 or adj[b].size() > 2)
			return print << "No" << endl, 0;
	}

	if (m == 0)
		return print << "Yes" << endl, 0;

	// Caso de ciclos: se algum componente tiver um circulo.
	for (int i = 1; i < n; ++i)
	{
		visited.assign(n + 1, false);

        if (not visited[i] and dfs_cycle(i))
            return print << "No" << endl, 0;
	}

	print << "Yes" << endl;
}
