/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;

#define endl '\n'

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	bool only = true;
	for (auto &c : s)
		if (c != toupper(c))
			only = false;

	bool first = s[0] == tolower(s[0]);
	if (first)
		for (size_t i = 1; i < s.length(); ++i)
			if (s[i] != toupper(s[i]))
				first = false;

	if (only or first)
		for (auto &c : s)
			putchar(c == toupper(c) ? tolower(c) : toupper(c));
	else
		for (auto &c : s)
			putchar(c);
	putchar('\n');
}
