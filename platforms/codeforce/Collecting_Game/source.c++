/**
	*	author:		mathbergsant, beyondmagic
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

using pll = pair<long long, long long>;

auto solve()
{
	int n;
	cin >> n;
	vector<long long> A(n);
	for (auto &a : A)
		cin >> a;

	vector<pair<long long, long long>> B(n);
	for (long long i = 0; i < n; ++i)
		B[i] = make_pair(A[i], i);
	sort(begin(B), end(B));

	vector<long long> C(n);
	C[0] = B[0].first;

	for (int i = 1; i < n; ++i)
		C[i] = C[i - 1] + B[i].first;

	vector<long long> D(n);
	long long p = 0;

	for(int i = 0; i < n; i++) {
		if (p < n)
			while(C[i] >= B[p].first) {
				p++;
				if (p == n) break;
			}
		D[i] = p;
	}

	// sort(begin(B), end(B), [](pll &a, pll &b){
	// 		return a.second < b.second;
	// });

	for(int i = 0; i < n; i++)
		cout << D[B[i].second] - 1 << (i + 1 == n ? endl : ' ');

	debug(A);
	debug(B);
	debug(C);
	debug(p);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}
