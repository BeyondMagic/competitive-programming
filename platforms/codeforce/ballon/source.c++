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
	for (auto &[y1, y2, x1, x2] : lines)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)
			swap(x1, x2), swap(y1, y2);
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

	debug(lines);
	auto compare_xs = [](point a, point b) -> bool {
		auto &[ay1, ay2, ax1, ax2] = a;
		auto &[by1, by2, bx1, bx2] = b;
		if (ax1 < bx1)
			return true;
		else if (ax1 > bx1)
			return false;
		else if (ax2 < bx2)
			return true;
		return false;
	};

	constexpr int x = 4;
	auto p = point(9999, 9999, x, x);
	auto r = lower_bound(begin(lines), end(lines), p, compare_xs) - begin(lines);
	debug(r);

	// for (int d; cin >> d; )
	// {
	// 	auto R = (lines, point(d, d, 0, 0));
	// 	debug(d, R);
	// }
}
