#include "library.hpp"

using namespace std;

// 2 balls
// 40 is the product we want to make
// 40 => 2³ * 5
//
// 3 balls: (1) (2³) (2²)
// 2 balls: (2 * 5) (5)
//
// 2

int main ()
{
	auto [N, X] = read<long long, long long>();
	vector<vector<long long>> bags(N);

	for (auto &A : bags)
	{
		auto s = read<long long>();
		A.resize(s);

		for (auto &a : A)
			cin >> a;

		ranges::sort(A);
	}

	debug(bags);
}
