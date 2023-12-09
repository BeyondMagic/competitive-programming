/**
	*	author:		mathbergsant, beyondmagic
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

using ll = long long;

inline ll expoent(ll a)
{
	ll t = 0;
	while (not (a & 1))
		++t,
		a >>= 1;
	return t;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;
	vector<ll> A(n);
	ll b = -1;
	ll lcmA = -1;
	for (auto &a : A)
	{
		cin >> a;
		ll o = expoent(a);

		if (b == -1)
			b = o,
			lcmA = a;
		else if (b != o)
			return puts("0"), 0;

		lcmA = lcm(lcmA, a);
	}
	cout << 2 * m / lcmA - m / lcmA << endl;
}
