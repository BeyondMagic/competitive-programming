#include "library.hpp"

using namespace std;

vector<vector<int>> G;

int main()
{
	fast_io();
	auto [n, d] = read<int, int>();
	d = d mod 4;
	G.resize(n);
	for (auto i = 0; i < n; ++i)
	{
		G.at(i).resize(n);
		for (auto j = 0; j < n; ++j)
			cin >> G[i][j];
	}
	vector<int> A, B;
	for (int i = 0; i < n; ++i)
		A.emplace_back(G[i][i]),
		B.emplace_back(G[i][n - i - 1]);

	for (int i = 0; d and i < n; ++i)
		if (d == 1)
			G[n - i - 1][n - i - 1] = B[i],
			G[i][n - i- 1] = A[i];
		else if (d == 2)
			G[n - i - 1][n - i - 1] = A[i],
			G[n - i - 1][i] = B[i];
		else if (d == 3)
			G[i][n - i - 1] = A[n - i - 1],
			G[i][i] = B[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cout << G[i][j] << (j == n - 1 ? endl : space);
}
