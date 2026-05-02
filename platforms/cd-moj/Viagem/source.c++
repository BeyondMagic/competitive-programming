#include "library.hpp"

using namespace std;

// V (value)
long long v, n, m;

// T (time), P (cost), B (node)
typedef tuple<long long, long long, long long> bridge;
vector<vector<bridge>> I;

long long x, y;

long long dijkstra ()
{
	// Node X in 0..V => T
	auto dist = vector<vector<long long>>(n + 1, vector<long long>(v + 1, LONG_LONG_MAX));
	for (long long i = 0; i <= v; ++i)
		dist[x][i] = 0;

	auto B = priority_queue<bridge, vector<bridge>, greater<bridge>>();
	B.emplace(0, 0, x);

	while (not B.empty())
	{
		auto [at, ap, a] = B.top(); B.pop();
		
		if (at > dist[a][ap])
			continue;

		for (auto &[bt, bp, b] : I[a])
		{
			auto new_time = at + bt;
			auto new_cost = ap + bp;

			if (new_cost <= v and new_time < dist[b][new_cost])
			{
				dist[b][new_cost] = min(dist[b][new_cost], new_time);
				B.emplace(new_time, new_cost, b);
			}
		}
	}

	auto mi = LONG_LONG_MAX;

	for (int i = 0; i <= v; ++i)
		mi = min(dist[y][i], mi);

	return mi == LONG_LONG_MAX ? -1 : mi;
}

int main()
{
	fast_io();
	cin >> v >> n >> m;
	I.resize(n + 1);
	long long A, B, T, P;
	while (m--)
	{
		cin >> A >> B >> T >> P;
		I[A].emplace_back(T, P, B);
		I[B].emplace_back(T, P, A);
	}
	cin >> x >> y;

	cout << dijkstra() << endl;
}
