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

using Town = pair<size_t, size_t>;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t n;
	cin >> n;
	vector<Town> votes(n);
	size_t A = 0, // Votos de Aoki
		   T = 0; // Votos de Takaohki

	for (auto &[a, t] : votes)
		cin >> a >> t,
		A += a;

	sort(begin(votes), end(votes), [](Town &a, Town &b) {
			auto Asum = a.first + a.second;
			auto Bsum = b.first + b.second;
			if (Asum > Bsum)
				return true;
			else if (Asum == Bsum and a.second < b.second)
				return true;
			return false;
	});

	size_t towns = 0;
	for (auto &[a, t] : votes)
	{
		T += a + t;
		A -= a;
		debug(T, A);
		++towns;
		if (T > A)
			break;
	}
	cout << towns << endl;
}
