#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
	string s;
	cin >> s;
	// ACE, BDF, CEG, DFA, EGB, FAC, and GBD
	const array<string, 7> equals{"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
	for (const auto &i : equals)
		if (i == s)
		{
			puts("Yes");
			return 0;
		}
	puts("No");
}
