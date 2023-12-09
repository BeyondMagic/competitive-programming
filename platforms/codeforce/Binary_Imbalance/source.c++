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

auto solve ()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s.find('0') == string::npos)
		return "NO";
	return "YES";
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
		cout << solve() << endl;
}
