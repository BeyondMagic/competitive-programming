/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#define endl '\n'

int solve()
{
	size_t n;
	double light;
	cin >> n >> light;
	vector<double> lanterns(n);
	for (auto &lantern : lanterns)
		cin >> lantern;
	sort(begin(lanterns), end(lanterns));

	double dist = 0;
	for (size_t i = 0; i + 1 < n; ++i)
		dist = double(max(size_t(dist), size_t(lanterns[i + 1] - lanterns[i])));

	// consider higher bound
	double ans = dist / 2.0;
	const double lower_bound = lanterns[0];
	const double higher_bound = light - lanterns[n - 1];

	if (lower_bound > ans)
		ans = lower_bound;
	if (higher_bound > ans)
		ans = higher_bound;

	return cout << ans << endl, 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(8);

	size_t t = 1;
	while (t--)
		solve();
}
