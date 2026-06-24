#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [n, q] = read<long long, long long>();
	auto X = read<vector<long long>>(n);

	BITree<long long> S(n);

	for (int i = 1; i < n; ++i)
		if (X[i] > X[i - 1])
			S.point_add(i, 1);

	while (q--)
	{
		auto [t, a, b] = read<long long, long long, long long>();
		if (t == 1)
		{
			--a;
			--b;
			auto k = S.range_query(a, b);
			if (S.value_at(a))
				--k;
			cout << k << endl;
		} else {
			--a;

			X[a] = b;
			auto pv = max(a - 1, 0ll);
			auto nx = min(a + 1, n - 1);

			if (not S.value_at(a))
			{
				if (X[a] > X[pv])
					S.point_add(a, 1);
			} else {
				if (X[a] < X[pv])
					S.point_add(a, -1);
			}
			if (not S.value_at(nx))
			{
				if (X[nx] > X[a])
					S.point_add(nx, 1);
			} else {
				if (X[nx] < X[a])
					S.point_add(nx, -1);
			}

		}
	}
}
