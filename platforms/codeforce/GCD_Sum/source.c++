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

long long sum_digits_number(long long n)
{
	long long s = 0;

	while (n)
		s += n % 10,
		n /= 10;

	return s;
}

int solve()
{
	long long a;
	cin >> a;
	auto b = sum_digits_number(a);

	while (gcd(a, b) == 1)
		++a,
		b = sum_digits_number(a);

	return cout << a << endl, 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		solve();
}
