#include "library.hpp"

using namespace std;

long long n, X, y, d;

set<long long> M;

long long dfs(long long x, long long k = 0)
{
	if (x < 1)
		x = 1;
	else if (x > n)
		x = n;

	debug(x, k);

	if (x == y)
		return k;

	if (M.count(x))
		return LONG_LONG_MAX;

	M.emplace(x);

	return min(dfs(x - d, k + 1), dfs(x + d, k + 1));
}

int main ()
{
	auto t = read<long long>();
	while (t--)
	{
		cin >> n >> X >> y >> d;
		auto ans = dfs(X);

		cout << (ans == LONG_LONG_MAX ? -1 : ans) << endl;
		M.clear();
	}
}
