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

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M, D;
	cin >> M >> D;
	int y, m, d;
	cin >> y >> m >> d;

	++d;
	while (d - D > 0)
	{
		++m;
		d -= D;
	}
	while (m - M > 0)
	{
		++y;
		m -= M;
	}
	cout << y << ' ' << m << ' ' << d << endl;
}
