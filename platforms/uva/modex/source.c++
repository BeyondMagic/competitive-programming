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

long long binpow(long long a, long long b, long long m)
{
	a %= m;
	long long r = 1;
	while (b > 0)
	{
		if (b & 1) // is even
			r = r * a % m;
		a = a * a % m;
		b >>= 1; // divide by two
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c;
	cin >> c;

	while (c--)
	{
		long long z;

		long long x, y, n;
		cin >> x >> y >> n;
		z = binpow(x, y, n);

		cout << z << endl;
	}
}
