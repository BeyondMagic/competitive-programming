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

using ll = long long;

auto solve ()
{
	ll n, // academic term
	   P, // minimum quantity of points
	   l, // points for lessons
	   t; // points of practical task
	cin >> n >> P >> l >> t;

	ll n_tasks = n / 7 + 1;
	e = P - n_tasks * t;
	return e;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--)
		cout << solve() << endl;
}
