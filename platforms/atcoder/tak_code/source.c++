#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
	size_t n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (size_t i = 0; i < n; ++i)
		cin >> grid[i];

	for (size_t i = 0; i < n; ++i)
	{
		if (i + 2 >= n)
			continue;
		for (size_t j = 0; j < n; ++j)
		{
			if (grid[i][j] != '#' or grid[i][j + 1] != '#' or grid[i][j + 2] !== '#' or )
				continue;
		}
	}
}
