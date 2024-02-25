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

	B.emplace_back(A[0], 0);
	for (int i = 0, p = 0; i < n-1; ++i)
	{
		if(A[i]==A[i+1]){
			B[p].second++;
		}
		else {
			p++;
			B.emplace_back(A[i + 1], 0);
			if(A[i+1] - A[i] > 1) {
				C.emplace_back(A[i]+1, A[i+1] - A[i] - 1);
			}
		}
	}

	C.emplace_back(A[n-1]+1,-1);

	int S1 = 0, S2 = 0;

	//calcula S1;
	debug(B);
	
	for (auto [a,b] : B) {
		S1 += a*b;
	}

	debug(S1);
	
	//calcula S2;
	int p = 0, q = 0;
	int temp = C[p].first;
	for (auto [a,b] : B) {
		debug(a, b);
		while (B[q].second > 0)
		{
			if (C[p].second != 0) {
				C[p].second--;
				B[q].second--;
				S2 += temp;
				temp++;
			}
			else {
				p++;
				temp = C[p].first;
			}
		}
		q++;
	}

	debug(S2);

	cout << S2 - S1 << endl;
}
