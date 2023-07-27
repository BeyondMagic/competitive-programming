#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	string s;
	cin >> s;
	size_t n = 0;
	for (const auto &c : s)
		switch (c)
		{
			case '4': case '7': ++n; break;
			default: break;
		}

	const auto ns = to_string(n);
	for (const auto &c : ns)
		switch (c)
		{
			case '4': case '7': break;
			default:
				puts("NO");
				return 0;
		}

	puts("YES");

}
