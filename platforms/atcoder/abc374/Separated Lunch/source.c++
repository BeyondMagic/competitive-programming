#include "library.hpp"

using namespace std;

long long a, b, ans = 1ll << 62ll;
int n;
vector<long long> people;

void solve_dfs (int pos)
{
	if (pos == n)
	{
		ans = min(ans, max(a, b));
		return;
	}

	a += people[pos];
	solve_dfs(pos + 1);
	a -= people[pos];

	b += people[pos];
	solve_dfs(pos + 1);
	b -= people[pos];
}

long long solve_permutation ()
{
	auto limit = (1 << n) - 1;
	// debug(limit);

	// debug(ans);

	pair<long long, long long> good = {-1, -1};

	for (int i = 0; i <= limit; ++i)
	{
		a = 0;
		b = 0;

		for (int j = 0, k = i; j < min(n, 20); ++j, k >>= 1)
			if (k & 1)
				a += people[j];
			else
				b += people[j];

		if (abs(a - b) < ans)
			good = {a, b},
			ans = abs(a - b);

		// debug(a, b);
	}

	return max(good.first, good.second);
}

int main ()
{
	n = read<int>();
	people.resize(n);
	for (auto &k : people)
		cin >> k;

	//print << solve_permutation() << endl;
	print << (solve_dfs(0), ans) << endl;
}
