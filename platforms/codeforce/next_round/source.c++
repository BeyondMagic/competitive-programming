#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t n, k;
	cin >> n >> k;
	size_t p, l, participans = 0;
	for (size_t i = 1; i <= n; ++i)
	{
		cin >> p;

		if (not p)
			continue;
		else
		{
			if (i <= k)
			{
				++participans;
				// cout << "1 i = " << i << " p = " << p << endl;
				l = p;
			}
			else if (p >= 1 and l == p)
			{
				++participans;
				// cout << "2 i = " << i << " p = " << p << endl;
			}
		}
	}
	cout << participans << endl;
}
