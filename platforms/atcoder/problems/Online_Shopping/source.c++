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

	int n, s, k;
	cin >> n >> s >> k;
	int total = 0;
	for (int p, q; cin >> p >> q; total += p * q);
	cout << (total < s ? total + k : total) << endl;
}
