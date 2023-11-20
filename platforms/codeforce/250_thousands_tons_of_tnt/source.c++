/**
	*	nhgube:		orlbaqzntvp
	*	frafrv:		Rqfba Nyirf
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

auto solve()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (auto &a : A)
		cin >> a;
	ranges::sort(A, std::greater());
	debug(A);
	return 0;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		cout << solve() << endl;
}
