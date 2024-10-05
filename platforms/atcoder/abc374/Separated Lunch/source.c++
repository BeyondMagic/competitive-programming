#include "library.hpp"

using namespace std;

int main ()
{
	auto n = read<int>();
	vector<long long> people(n);
	for (auto &k : people)
		cin >> k;

	auto limit = (1 << n) - 1;
	// debug(limit);

	long long min_d = 1ll << 62ll;
	// debug(min_d);

	pair<long long, long long> good = {-1, -1};

	for (int i = 0; i <= limit; ++i)
	{
		long long
			a = 0,
			b = 0;

		for (int j = 0, k = i; j < min(n, 20); ++j, k >>= 1)
			if (k & 1)
				a += people[j];
			else
				b += people[j];

		if (abs(a - b) < min_d)
			good = {a, b},
			min_d = abs(a - b);

		// debug(a, b);
	}

	print << max(good.first, good.second) << endl;
}
