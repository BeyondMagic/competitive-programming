#include <bits/stdc++.h>

using namespace std;

#ifdef local
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

	vector<long long> A(n);
	for (auto &a : A)
		cin >> a;

	vector<long long> P(n - 1);
	for (auto &p : P)
		cin >> p;

	// Rate of differnece of each cell...
	long long S = accumulate(begin(A), end(A), 0ll);
	if (S < 0)
		puts("-");
	else if (S > 0)
		puts("+");
	else
		puts("0");
}
