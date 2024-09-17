#include "library.hpp"

using namespace std;



int main ()
{
	auto [N, M] = read<int, int>();
	vector<vector<pair<int, int>>> graph(N + 1);
	for (int i = 1, a, b, w; i <= N; ++i)
	{
		cin >> a >> b >> w;
		graph[a].emplace_back(b, w);
		graph[b].emplace_back(a, w);
	}



}
