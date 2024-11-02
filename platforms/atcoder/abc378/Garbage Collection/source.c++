#include "library.hpp"

using namespace std;

int main ()
{
	auto n = read<int>();
	vector<tuple<int, int>> trash(n + 1);
	for (int i = 1; i <= n; ++i)
		trash[i] = read<int, int>();

	auto Q = read<int>();
	while (Q--)
	{
		auto [t, d] = read<int, int>();
		auto [q, r] = trash[t];
		auto ans = r - (d mod q);
		if (ans < 0)
			ans += q;
		ans += d;
		print << ans << endl;
	}
}
