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

	int n;
	cin >> n;
	for (int x = 0; x <= n; ++x)
		for (int y = 0; y <= n; ++y)
			for (int z = 0; z <= n; ++z)
				if (x + y + z <= n)
					cout << z << ' ' << y << ' ' << x << endl;
}
