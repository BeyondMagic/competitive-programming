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
#define space ' '

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<pair<int, int>> C;
	for (int i = n; i >= 1; --i)
		C.emplace_back(i, 0);

	int x = 1, y = 0;
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 2)
		{
			int c;
			cin >> c;
			auto k = int(C.size()) - c;
			auto p = C[k];
			cout << p.first << space << p.second << endl;
		} else {
			char c;
			cin >> c;
			switch (c)
			{
				case 'U': ++y; break;
				case 'R': ++x; break;
				case 'D': --y; break;
				case 'L': --x; break;
			}
			C.emplace_back(x, y);
		}
	}
}
