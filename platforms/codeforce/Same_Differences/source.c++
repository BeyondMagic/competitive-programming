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

#define MAX 100

// O(n + log(n) + n)
int solve ()
{
	int n;
	cin >> n;

	vector<int> A((size_t)n);
	for (auto &a : A) // n
		cin >> a;

	ranges::sort(A); // log(n)

	for (int i = 0; i + 1 < n; ++i) // n
		if (A[i + 1] - A[i] > 1)
			return puts("NO"), 0;
	return puts("YES"), 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	
	// O(t)
	while (t--)
		// O(2tn log n)
		solve();
}
