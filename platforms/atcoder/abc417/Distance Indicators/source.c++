#include "library.hpp"

using namespace std;

/*
 * $
 * j - A_j = i + A_i
 * $
 */

auto frequency_map = unordered_map<long long, size_t>();

auto cnt = 0uz;

int main ()
{
	auto n = read<size_t>();
	auto A = read<vector<long long>>(n);

	for (auto j = 0uz; j < n; ++j)
	{
		auto target = j - A[j];

		if (frequency_map.contains(target))
			cnt += frequency_map[target];

		auto key = j + A[j];
		frequency_map[key] += 1;
	}

	cout << cnt << endl;
}
