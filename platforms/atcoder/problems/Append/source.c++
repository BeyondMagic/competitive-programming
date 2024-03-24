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

	vector<int> A{-1};
	int q;
	cin >> q;
	while (q--)
	{
		int t, xk;
		cin >> t >> xk;
		// append
		if (t == 1)
		{
			A.emplace_back(xk);
		// find
		} else {
			cout << A[int(A.size()) - xk] << endl;
		}
	}
}
