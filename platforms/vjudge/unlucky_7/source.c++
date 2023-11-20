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

char octal[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	int t = 0;
	for (int a = 1; a <= n; ++a)
	{
		sprintf(octal, "%o%d", a, a);
		bool ok = true;
		for (int i = 0; octal[i] and ok; ++i)
			ok = octal[i] == '7';
		if (ok)
			++t;
	}
	cout << t << endl;
}
