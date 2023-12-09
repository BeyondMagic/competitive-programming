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
	int t, a;
	cin >> t;
	while (t--)
		cin >> a,
		puts(a >= 111 * (a % 11) ? "YES" : "NO");
}
