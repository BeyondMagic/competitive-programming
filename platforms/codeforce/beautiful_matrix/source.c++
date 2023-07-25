#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	for (auto i = 1; i <= 5; ++i)
		for (auto j = 1; j <= 5; ++j)
		{
			cin >> n;
			if (n)
			{
				cout << abs(3 - i) + abs(3 - j) << endl;
				return 0;
			}

		}
}
