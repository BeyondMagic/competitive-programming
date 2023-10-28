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

long long greatest_prime_factor (long long n)
{
	long long r = -1;

	for (long long i = 2; i * i <= n; ++i)
		while (not (n % i))
			r = i, n /= i;

	return n > 1 ? n : r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;

	cout << greatest_prime_factor(n) << endl;
}
