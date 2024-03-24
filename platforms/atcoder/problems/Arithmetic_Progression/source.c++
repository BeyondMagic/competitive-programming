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

	int a, b, d;
	cin >> a >> b >> d;

	do {
		cout << a << ' ';
		a += d;
	} while (a <= b);
	cout << endl;
}
