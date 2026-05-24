#include "library.hpp"

using namespace std;

vector<string> G;
vector<vector<int>> M;

// row, column
array<pair<int, int>, 8> P{
	make_pair(-1, -1),
	make_pair(-1, 0),
	make_pair(-1, 1),
	make_pair(0, -1),
	make_pair(0, 1),
	make_pair(1, -1),
	make_pair(1, 0),
	make_pair(1, 1),
};

int main()
{
	fast_io();
	auto [n, m, k] = read<int, int, int>();
	G.resize(n);
	for (auto &s: G)
		cin >> s;

	for (auto i = 0; i < n and k; ++i)
		for (auto j = 0; j < m and k; ++j)
			if (G[i][j] == '*')
				G[i][j] = '.',
				--k;

	M.resize(n);
	for (auto i = 0; i < n; ++i)
		M.at(i).resize(m, 0);

	for (auto i = 0; i < n; ++i)
		for (auto j = 0; j < m; ++j)
			if (G.at(i).at(j) == '*')
				for (auto &[x, y] : P)
					if (x + i >= 0 and x + i < n and y + j >= 0 and y + j < m)
						++M.at(x + i).at(y + j);

	for (auto i = 0; i < n; ++i)
		for (auto j = 0; j < m; ++j)
		{
			if (G.at(i).at(j) == '*')
				cout << '*';
			else
				cout << M.at(i).at(j);
			cout << (j == m - 1 ? endl : space);
		}
}
