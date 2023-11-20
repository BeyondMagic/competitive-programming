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
	vector<pair<int, int>> points(n);
	for (auto &[x, y] : points)
		cin >> x >> y;
	ranges::sort(points);

	//vector<float> slopes;
	int t = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
		{
			auto [xi, yi] = points[i];
			auto [xf, yf] = points[j];
			auto r = float(yi - yf) / float(xi - xf);
			if (r >= -1.0 and r <= 1.0)
				++t;
			// slopes.emplace_back();
		}
	// debug(points);
	// debug(slopes);
	cout << t << endl;

}
