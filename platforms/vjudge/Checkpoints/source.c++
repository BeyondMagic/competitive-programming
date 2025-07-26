#include "library.hpp"

using namespace std;

#define MAX 1'000'000'000

int main ()
{
	long long n, m;
	cin >> n >> m;
	vector<pair<long long, int>> S(n);
	for (auto &[a, b] : S)
		cin >> a >> b;
	vector<pair<long long, int>> X(m);
	for (auto &[c, d] : X)
		cin >> c >> d;

	for (auto &[a, b] : S)
	{
		long long ith = 0, dist = MAX;
		for (long long i = 0; i < m; ++i)
		{
			auto [c, d] = X[i];

			long long cur_dist = abs(a - c) + abs(b - d);

			if (cur_dist < dist)
				dist = cur_dist,
				ith = i;
		}

		print << ith + 1 << endl;
	}
}
