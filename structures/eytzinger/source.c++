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

const int n = (1 << 20);
const int block_size = 16; // = 64 / 4 = cache_line_size / sizeof(int)
alignas(64) int a[n], b[n+1];

int eytzinger(int i = 0, int k = 1)
{
	if (k <= n)
	{
		i = eytzinger(i, 2 * k);
		b[k] = a[i++];
		i = eytzinger(i, 2 * k + 1);
	}
	return i;
}

int search(int x)
{
	int k = 1;
	while (k <= n)
		__builtin_prefetch(b + k * block_size),
		k = 2 * k + (b[k] < x);
	k >>= __builtin_ffs(~k);
	return k;
}

int solve()
{
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	// cin >> t;
	while (t--)
		solve();
}
