#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	while (n--)
	{
		size_t b, c, h;
		cin >> b >> c >> h;
		size_t w = 0;
		while (b and c and h)
		{
			for (size_t i = 1; i <= b; ++i)
			{
				--b;
				for (size_t j = 1; j <= c; ++j)
				{
					--c;
					for (size_t m = 1; m <= h; ++m)
					{
						++w;
						--h;
					}
				}
			}
		}

		cout << w << endl;
	}
}
