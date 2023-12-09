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
	string s;
	cin >> n >> s;

	int t = 0;
	for (int i = 0; i < n - 2; ++i)
		if (s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C')
			++t;
	cout << t << endl;

}
