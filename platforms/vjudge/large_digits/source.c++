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

	string s;
	int m = 0;
	while (cin >> s)
	{
		int d = 0;
		for (auto &c : s)
			d += c - '0';
		m = max(m, d);
	}
	cout << m << endl;
}
