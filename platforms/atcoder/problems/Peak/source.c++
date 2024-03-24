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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> A(n);
	for (auto &a : A)
		cin >> a;

	ranges::sort(A);

	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, int((lower_bound(begin(A), end(A), A[i] + m) - begin(A) - i)));
	cout << ans << endl;
}
