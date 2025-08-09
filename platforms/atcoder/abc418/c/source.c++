#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, q] = read<long long, long long>();
	auto A = read<vector<long long>>(n);
	auto B = read<vector<long long>>(q);

	auto max_a = *max_element(A.begin(), A.end());

	auto counts = vector<long long>(max_a + 1, 0);
	for (auto &a : A)
		counts[a]++;

	auto bags = vector<long long>(max_a + 1, 0);
	auto flavours = vector<long long>(max_a + 1, 0);

	for (auto k = 1ll; k <= max_a; k++)
		bags[k] = bags[k - 1] + k * counts[k],
		flavours[k] = flavours[k - 1] + counts[k];

	for (auto &b : B)
	{
		if (b > max_a)
		{
			cout << -1 << endl;
			continue;
		}

		auto v = b - 1;
		auto d1 = bags[v];
		auto d2 = v * (n - flavours[v]);
		auto d = d1 + d2;

		cout << d + 1 << endl;
	}
}
