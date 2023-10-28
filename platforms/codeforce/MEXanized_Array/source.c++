/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#define endl '\n'

long long mex (vector<long long> &A)
{
	set<long long> next(begin(A), end(A));

	long long result = 0;
	while (next.count(result))
		++result;

	return result;
}

long long mex2(set<long long> &m)
{
	return *m.begin();
}

void comb(size_t N, size_t K)
{
	vector<long long> elements(N, 0);
	for (size_t i = 0; i < K; ++i)
	{
		debug(elements);
		++elements[i];
		for (size_t j = 0; j < N; ++j)
		{
			debug(elements);
			if (i != j)
				++elements[j];
		}
	}
	debug(elements);
}

int solve()
{
	size_t n;
	long long k, x;
	cin >> n >> k >> x;
	// { 0, 1, 2, 2, 2};
	// vector<long long> elements{ 0, 1, 2, 2, 2 };
	comb(5, 3);

	// generating the array...
	/*
	for (size_t i = 0; i <= n; ++i)
	{
		cout << "{ ";
		for (size_t j = 0; j <= n; ++j)
		{
			cout << i % (j) << ", ";
		}

		cout << "}" << endl;
	}*/


	return 0;
	//return cout << (mex(elements) == k ? "true" : "false") << endl, 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	cin >> t;
	t = 1;
	while (t--)
		solve();
}
