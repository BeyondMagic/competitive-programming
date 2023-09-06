#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;

	auto cmp = [](pair<size_t, size_t> a, pair<size_t, size_t> b) {
		if (a.second > b.second or
		   (a.first == b.first and a.second > b.second))
			return true;
		return false;
	};
	vector<size_t> ans(n);
	vector<pair<size_t, size_t>> cups(n);

	size_t f, s;
	for (size_t i = 0; i < n; ++i)
	{
		cin >> f >> s;
		cups.push_back({f, s});
	}
	sort(begin(cups), end(cups), cmp);

	pair<size_t, size_t> chosen = *cups.begin();
	for (size_t i = 1; i < n; ++i)
	{
		// cout << cups[i].first << ' ' << cups[i].second << endl;
		if (chosen.first == cups[i].first)
			ans[i] = chosen.second + cups[i].second / 2;
		else
			ans[i] = chosen.second + cups[i].second;
	}
	sort(rbegin(ans), rend(ans));
	cout << ans[0] << endl;
}
