/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

auto sieve (int n)
{
	vector<int> table(n + 1);

	iota(begin(table), end(table), 0);

	for (int i = 4; i <= n; i += 2)
		table[i] = 2;

	for (int i = 3; i * i <= n; ++i)
		if (table[i] == i)
			for (int j = i * i; j <= n; j += i)
				if (table[j] == j)
					table[j] = i;

	return table;
}

auto factor (int n, vector<int> &S)
{
	vector<int> table;
	while (n != 1) {
		table.emplace_back(S[n]);
		n /= S[n];
	}
	return table;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int L;
	cin >> L;

	auto S = sieve(L);
	unordered_map<int, int> M;

	for (int i = 1; i <= L; ++i)
	{
		unordered_map<int, int> N;
		for (auto &n : factor(i, S))
			++N[n];

		for (auto &[a, b] : N)
			M[a] = max(b, M[a]);
	}

	size_t r = 1;
	for (auto &[a, b] : M)
		if (b)
		{
			size_t i = a;
			for (int k = 1; k < b; ++k, i *= a);
			r *= i;
		}

	cout << r << endl;
}
