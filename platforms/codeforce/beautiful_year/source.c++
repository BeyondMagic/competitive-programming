#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	string s;
	cin >> s;
	size_t n = size_t(stoi(s));
	auto M = size_t(s[0]) - '0';

	for (size_t m = 0; m <= 9; ++m)
		for (size_t c = 0; c <= 9; ++c)
		{
			if (c == m)
				continue;
			for (size_t d = 0; d <= 9; ++d)
			{
				if (d == c or d == m)
					continue;

				for (size_t u = 0; u <= 9; ++u)
				{
					if (u == d or u == c or u == m)
						continue;

					size_t n2 = m * 1'000 + c * 100 + d * 10 + u * 1;

					if (n2 > n)
					{
						cout << n2 << endl;
						return 0;
					}
				}
			}
}
