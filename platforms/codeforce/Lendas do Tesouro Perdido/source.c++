#include "library.hpp"

using namespace std;

#define MAX 100001

array<int, MAX> V{};

int main()
{
	fast_io();
	auto n = read<int>();
	auto A = read<vector<int>>(n);
	for (auto &a : A)
	{
		auto best = 0;
		if (a == 1)
		{
			best = 1;
			if (V[2] > 0)
				best = max(best, V[2] + 1);
		} else {
			if (V[a + 1] > 0)
				best = max(best, V[a + 1] + 1);
			if (V[a - 1] > 0)
				best = max(best, V[a - 1] + 1);
		}
		V[a] = max(V[a], best);
	}
	cout << V[1] << endl;
}
