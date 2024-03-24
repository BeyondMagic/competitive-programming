/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include <debug.hpp>
#else
	#define debug(...)
#endif

#define endl '\n'
#define space ' '

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, 0));

	int left = 0;
	int up = 1;
	int right = n - 1;
	int down = n - 1;
	const int mid = n / 2;

	const auto print_grid = [&](){
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (i == mid and j == mid)
					cout << 'T';
				else
					cout << grid[j][i];
				cout << (j + 1 == n ? endl : space);
			}
	};

	int k = 1,
		x = 0,
		y = 0;
	while (x != mid and y != mid)
	{
		while (x != right)
			grid[x][y] = k++,
			++x;
		--right;

		while (y != down)
			grid[x][y] = k++,
			++y;
		--down;

		while (x != left)
			grid[x][y] = k++,
			--x;
		++left;

		while (y != up)
			grid[x][y] = k++,
			--y;
		++up;
	}

	grid[x][y] = k;

	print_grid();
}
