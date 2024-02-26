/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include <debug.hpp>
#else
	#define debug(...)
#endif

#define endl '\n'

unordered_map<long long, long long> dp;

long long int total (long long int x)
{
	if (not dp[x])
		dp[x] = total(x / 2) + total((x + 1) / 2);

	return (dp[x] < 0 ? 0 : dp[x]) + x;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long int n;
	cin >> n;
	dp[0] = -1;
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = 2;

	cout << total(n) << endl;
}
