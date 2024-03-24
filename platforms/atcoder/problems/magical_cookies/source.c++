#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
	size_t h, w;
	cin >> h >> w;

	vector<string> grid(max(h, w));
	set<char> chars;
	char a;
	for (size_t i = 0; i < h; ++i)
	{
		for (size_t j = 0; j < w; ++j)
		{
			cin >> a;
			chars.emplace(a);
			grid[i].push_back(a);
		}
	}

	for (const char &c : chars)
	{
		for (size_t i = 0; i < h; ++i)
		{
			bool row_marked = false;
			size_t r = 0;

			for (size_t j = 0; j < w; ++j)
			{
				if (c == grid[i][j])
				{
					++r;
					if (r == 2)
						row_marked = true;
				}
				const auto hi = j < h ? j : h - 1;
				const auto wi = i < w ? i : w - 1;
				if (c == grid[hi][wi])
				{
					cout << "position " << wi + 1<< hi + 1<< endl;
				}
			}

			if (row_marked)
				for (size_t j = 0; j < w; ++j)
					if (grid[i][j] == c)
						grid[i][j] = '.';
		}
	}
	for (const auto &s : grid)
		cout << s << endl;
}
