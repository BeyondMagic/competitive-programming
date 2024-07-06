#include "library.hpp"

using namespace std;

struct UnionFind {

	int largest = 0, components;

	vector<int> size, parent;

	UnionFind (int N) : size(N + 1, 1), parent(N + 1)
	{
		components = N;
		iota(parent.begin(), parent.end(), 0);
	}

	int find_set (int x)
	{
		return x == parent[x] ? x : (parent[x] = find_set(parent[x]));
	}

	bool same_set (int x, int y)
	{
		return find_set(x) == find_set(y);
	}

	void union_set (int x, int y)
	{
		if (same_set(x, y))
			return;

		auto P = find_set(x);
		auto Q = find_set(y);

		if (size[P] < size[Q])
			swap(P, Q);

		parent[Q] = P;
		size[P] += size[Q];

		// New processing to get the number of components every time there is a union between vertices.
		--components;

		// New processing for getting the quantity of vertices in the largest component:
		if (size[P] > largest)
			largest = size[P];
	}
};

int main ()
{
	auto [N, M] = read<int, int>();

	UnionFind graph(N);

	for (int a, b; cin >> a >> b;)
		graph.union_set(a, b),
		print << graph.components << space << graph.largest << endl;
}
