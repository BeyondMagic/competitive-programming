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

inline long long powerto(long long a, long long b, long long n)
{
	while (--n)
		a *= b;
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a;
	cin >> a;

	long long n = powerto(10, 10, a) - 1;
	
	debug(n);

	long long gr = -1,
			  gi = -1,
			  gj = -1;

	long long b;
	for (auto i = n; i >= 0; --i)
		for (auto j = n; j >= 0; --j)
		{
			b = i * j;
			string s = to_string(b), r = s;
			reverse(begin(r), end(r));
			if (s != r)
				continue;
			if (b > gr)
			{
				gr = b;
				gi = i;
				gj = j;
			}
		}
	cout << gi << " * " << gj << " = " << gr << endl;
}
