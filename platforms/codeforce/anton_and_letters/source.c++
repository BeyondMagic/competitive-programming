#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	set<char> u;
	char c;
	while (cin >> c)
		switch (c)
		{
			case '{': case '}': case ',': case ' ':
				continue;
			default:
				u.emplace(c);
		}
	cout << u.size() << endl;
}
