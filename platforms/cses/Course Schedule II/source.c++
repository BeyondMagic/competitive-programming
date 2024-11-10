#include "library.hpp"

using namespace std;

vector<int> topological_sort(int N, vector<vector<int>> &graph, vector<int> &out)
{
	//priority_queue<int, vector<int>, less<int>> pq;
	priority_queue<int> pq;
	//vector<bool> mark(N + 1, false);

	for (int i = 1; i <= N; ++i)
		// vertex without dependencies
		if (not out[i])
			pq.emplace(i);

	vector<int> ans;
	while (not pq.empty())
	{
		auto k = pq.top();
		pq.pop();

		ans.emplace_back(k);

		for (auto &v : graph[k])
			// remove the dependency
			if (not --out[v])
				pq.emplace(v);
	}
	reverse(begin(ans), end(ans));

	return ans;
}

int main ()
{
	auto [n, m] = read<int, int>();

	vector<int> out(n + 1);
	vector<vector<int>> graph(n + 1);

	while (m--)
	{
		auto [a, b] = read<int, int>();
		graph[b].emplace_back(a);
		++out[a];
	}

	// debug(out);

	auto o = topological_sort(n, graph, out);

	for (int i = 0; i < n; ++i)
		print << o[i] << (i + 1 == n ? endl : space);
}
