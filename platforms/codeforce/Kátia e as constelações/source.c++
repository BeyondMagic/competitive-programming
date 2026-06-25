#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [n, d] = read<long long, double>();
	vector<pair<long long, long long>> P(n);
	for (auto &[x, y] : P)
		cin >> x >> y;

	UFDS U(n);

	for (auto i = 0; i < n; ++i)
	{
		auto &[ax, ay] = P[i];
		for (auto j = 0; j < n; ++j)
		{
			auto &[bx, by] = P[j];

			auto k = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);

			if (k <= d * d)
				U.union_set(i, j);
		}
	}

	vector<int> A(n, 0);
	auto mx = 0;
	for (int i = 0; i < n; ++i)
	{
		auto k = U.find_set(i);
		A[k]++;
		mx = max(mx, A[k]);
	}

	cout << mx << endl;
}
