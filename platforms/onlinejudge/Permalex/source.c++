#include <bits/stdc++.h>

using namespace std;

string s;

long long solve()
{
	string p0 = s;
	sort(begin(p0), end(p0));

	long long p = 1;

	do {
		if (p0 == s)
			break;
		++p;
	} while (next_permutation(begin(p0), end(p0)));

	return p;
}

int main ()
{
	while (cin >> s and s != "#")
	{
		auto ans = solve();
		auto digits = int(log10(ans)) + 1;
		for (int i = 0; i < 10 - digits; ++i)
			cout << ' ';
		cout << ans << endl;
	}
}
