/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>
#include <array>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

inline int bit_set (int number, int at)
{
    return number | (1 << at);
}

int solve (vector<long long> &squares)
{
	int n, l;
	cin >> n >> l;

	vector<int> X(n);

	for (auto &x : X)
		cin >> x;

	int y = 0;

	for (int i = 0; i < l; ++i)
	{
		int k = 0;
		for (auto &x : X)
			k += x & squares[i] ? 1 : -1;
		if (k > 0)
			y = bit_set(y, i);
	}

	return cout << y << endl, 0;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> squares(32, 1);
	for (int i = 0; i < 32; ++i)
		squares[i] <<= i;

	int t;
	cin >> t;
	while (t--)
		solve(squares);
}
