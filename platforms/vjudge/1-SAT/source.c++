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
	map<string, bool> S;
	set<string> V; // verify
	for (string s; cin >> s;)
	{
		S.emplace(s, true);
		if (s[0] != '!')
			V.emplace(s);
	}

	for (auto &v : V)
		if (S['!' + v])
			return cout << v << endl, 0;
	
	debug(V);
	puts("satisfiable");
}
