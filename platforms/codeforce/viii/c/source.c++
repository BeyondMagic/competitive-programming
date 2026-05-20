#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [n, x] = read<long long, long long>();

	n %= 6;

	vector<tuple<long long, long long, long long>> Pos {
		{0, 1, 2},
		{1, 0, 2},
		{1, 2, 0},
		{2, 1, 0},
		{2, 0, 1},
		{0, 2, 1},
	};

	auto [X, Y, Z] = Pos[n];

	debug(Pos[n]);

	int ans = -1;

	if (x == 0)
		ans = X;
	else if (x == 1)
		ans = Y;
	else
		ans = Z;

	cout << ans << endl;
}
