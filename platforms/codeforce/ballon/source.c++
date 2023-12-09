/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

using point = tuple<int, int, int, int>;
using ii = pair<int, int>;

struct UFDS
{
	vector<int> size, ps;

	UFDS (int N) : size(N, 1), ps(N)
	{
		iota(ps.begin(), ps.end(), 0);
	}

	int find_set(int x)
	{
		return x == ps[x] ? x : (ps[x] = find_set(ps[x]));
		// return x == ps[x] ? x : find_set(ps[x]);
	}

	bool same_set(int x, int y)
	{
		return find_set(x) == find_set(y);
	}

	void union_set(int x, int y)
	{
		if (same_set(x, y))
			return;

		int p = find_set(x);
		int q = find_set(y);

		//if (size[p] < size[q])
		//	std::swap(p, q);

		ps[q] = p;
		size[p] += size[q];
	}
};

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c;
	cin >> n >> c;

	vector<point> lines(n);
	vector<pair<int, int>> lines_xs(n);
	map<pair<int, int>, pair<int, int>> M;

	for (int i = 0; i < n; ++i)
	{
		auto &[y1, y2, x1, x2] = lines[i];
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2)
			swap(x1, x2), swap(y1, y2);

		auto &[xi, xf] = lines_xs[i];
		xi = x1;
		xf = x2;
		M[make_pair(xi, xf)] = make_pair(x1, x2);
	}

	ranges::sort(lines);

	UFDS dsu(n);

	for (int i = 0; i < n; ++i)
	{
		auto &[y1, y2, x1, x2] = lines[i];
		
		int x, y;
		if (y1 == y2)
			continue;
		if (y1 > y2)
			x = x1,
			y = y1;
		else
			x = x2,
			y = y2;

		for (int j = i + 1; j < n; ++j)
		{
			auto [yi, yf, xi, xf] = lines[j];

			if (y > yf and y > yi)
				break;

			auto xmin = min(xi, xf),
				 xmax = max(xi, xf),
				 ymin = min(yi, yf),
				 ymax = max(yi, yf);

			auto xp = (x - xmin) * (ymax - ymin) - (y - ymin) * (xmax - xmin);
			if (xp > 0 and x >= xmin and x <= xmax)
			{
				// debug(i, make_pair(x, y), "point is below the line ", j);
				dsu.union_set(j, i);
				// debug(dsu.ps);
				break;
			}
		}
	}

	ranges::sort(lines_xs);
	debug(lines_xs);

	constexpr int x = 4;
	pair<int, int> p{x, x};

	auto r = lower_bound(begin(lines_xs), end(lines_xs), p);
	if (r == end(lines_xs))
		return puts("NOT FOUND"), 0;
	else
	{
		auto position = r - begin(lines_xs) - 1;
		debug(lines_xs);
		debug(p);
		debug(position);
	}

	// for (int d; cin >> d; )
	// {
	// 	auto R = (lines, point(d, d, 0, 0));
	// 	debug(d, R);
	// }
}
