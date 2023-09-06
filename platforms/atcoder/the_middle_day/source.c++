#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
	size_t m;
	cin >> m;
	vector<size_t> d(m);
	size_t t = 0;
	for (size_t i = 0; i < m; ++i)
	{
		cin >> d[i];
		t += d[i];
	}
	size_t mid = (t + 1) / 2;
	size_t r_f = 0;
	for (size_t j = 0; j < m; ++j)
	{
		for (size_t i = 1; i <= d[j]; ++i)
		{
			++r_f;
			if (r_f == mid)
			{
				cout << j + 1 << ' ' << i << endl;
				return 0;
			}
		}
	}

}
