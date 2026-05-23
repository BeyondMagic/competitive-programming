#include "library.hpp"

using namespace std;

vector<string> G;

array<bool, 16> ldig, rdig, column;

int k = 0;

auto solve (int R = 0)
{
	if (R == 8)
	{
		++k;
		return;
	}

	for (int c = 0; c < 8; ++c)
	{
		auto l = R - c + 7;
		auto r = R + c;

		if (G[R][c] == '*' or column[c] or ldig[l] or rdig[r])
			continue;

		column[c] = ldig[l] = rdig[r] = true;
		solve(R + 1);
		column[c] = ldig[l] = rdig[r] = false;
	}
}

int main()
{
	fast_io();
	G.resize(8);
	for (auto i = 0; i < 8; ++i)
		cin >> G.at(i);
	solve();
	cout << k << endl;
}
