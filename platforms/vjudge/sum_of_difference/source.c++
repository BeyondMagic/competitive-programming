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

	int n;
	cin >> n;
	vector<long long> A(n);
	for (auto &a : A)
		cin >> a;

	ranges::sort(A); // remove absolute

	// long long s = 0;

	/*
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			s += abs(A[i] - A[j]);*/
	
	long long Js = 0;
	for (int j = 0; j < n; ++j)
		Js += (j + 1) * A[j];
	debug(Js);

	long long Is = 0;
	for (int i = 0; i < n; ++i)
		Is += (n - i) * A[i];
	debug(Is);

	/*
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			debug(A[i], A[j], A[i] - A[j]);
			s += abs(A[i] - A[j]);
		}*/

	cout << Js - Is << endl;
}
