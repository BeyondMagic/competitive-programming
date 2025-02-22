#include "library.hpp"

using namespace std;

long long h, w, p, q;
double X;
vector<vector<long long>> grid;
set<pair<int, int>> visited;

long long ans = 0;


#define PRECISION_CALC 1e-10
#define GREATER_DECIMAL_E(a, b, epsilon) (((a) - (b)) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))
#define GREATER_DECIMAL(a, b) GREATER_DECIMAL_E(a, b, PRECISION_CALC)

bool greater_p (long long size, long long s)
{
	double size_d = size, s_d = s;
	return GREATER_DECIMAL(size_d / X, s_d);
}

bool in_bounds (int y, int x)
{
	return x >= 0 and x < w and y >= 0 and y < h and not visited.contains(make_pair(y, x));
}

using tii = tuple<long long, int, int>;

int main ()
{
	cin >> h >> w >> X >> p >> q;
	grid.resize(h);
	for (int i = 0; i < h; ++i)
		for (int j = 0, k; j < w; ++j)
			cin >> k,
			grid[i].emplace_back(k);

	--p, --q;

	priority_queue<tii, vector<tii>, greater<tii>> pq;
	pq.emplace(grid[p][q], p, q);

	while (not pq.empty())
	{
		auto [s, y, x] = pq.top();
		pq.pop();
		visited.emplace(y, x);

		// not greater than one? it's over.
		// not the start posiiton?
		if (y == p and x == q)
		{
		} else if (not greater_p(ans, s)) {
			break;
		}

		debug(ans, s, y, x);
		ans += s;


		if (in_bounds(y, x + 1))
			pq.emplace(grid[y][x + 1], y, x + 1);
		if (in_bounds(y, x - 1))
			pq.emplace(grid[y][x - 1], y, x - 1);
		if (in_bounds(y + 1, x))
			pq.emplace(grid[y + 1][x], y + 1, x);
		if (in_bounds(y - 1, x))
			pq.emplace(grid[y - 1][x], y - 1, x);
	}

	print << ans << endl;
}
