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
	vector<int> A(n);
	vector<pair<int, int>> B, C;
	for (auto &a : A)
		cin >> a;

	sort(begin(A), end(A));

	int ans = 0;
	for (int i = 1; i < n; ++i)
		if (A[i] == A[i - 1])
		{
			++A[i];
			++ans;
			sort(begin(A), end(A));
			i = 1;
		}
	cout << ans << endl;
}
