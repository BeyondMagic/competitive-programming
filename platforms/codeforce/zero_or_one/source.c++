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
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b and b == c)
		puts("*");
	else if (a == b and c != b)
		puts("C");
	else if (a == c and b != c)
		puts("B");
	else
		puts("A");
}
