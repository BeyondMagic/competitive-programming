#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, m] = read<long long, long long>();
	vector<pair<long long, long long>> P;
	vector<long long> got(m);

	bool has_first = false;

	for (long long i = 0; i < m; ++i)
	{
		cin >> got[i];
		if (got[i] == 1)
			has_first = true;
	}

	if (not has_first)
		return print << -1 << endl, 0;

	for (long long i = 0, k; i < m; ++i)
		cin >> k,
		P.emplace_back(got[i] - 1, k);

	sort(rbegin(P), rend(P));
	debug(P);

	long long
		ans = 0,
		needed = 0;

	int last = n - 1;
	for (auto p : P)
	{
		needed += last - p.first;
		debug(last, p.first);
		if (needed and p.second - 1 >= needed)
		{
			debug(last, p.first, p.second, needed);
			last = p.first - 1;
			ans += needed * (needed + 1) / 2;
			needed = 0;
		}
	}

	debug(ans);

	if (needed)
		return print << -1 << endl, 0;

	print << ans << endl;
}
