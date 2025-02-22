#include "library.hpp"

#define MAX 1000000000

using namespace std;

int n, w, x, y, q, t, a, time_to_disappear = 0;
int max_y = -1, min_y = MAX;

int main ()
{
	cin >> n >> w;

	//  id -> column
	map<int, int> blocks;

	// column -> set of blocks in that line ordered from the min line to max line
	map<int, set<pair<int, int>, less<pair<int, int>>>> bottom;

	/**
	 * Reading
	 */
	for (int i = 1; i <= n; ++i)
	{
		cin >> x >> y;

		blocks[i] = x;

		// If the column of the bottom is empty, initialize.
		bottom[x].emplace(y, i);

	}

	for (int j = 1; j <= w; ++j)
	{
		if (bottom[j].size())
		{
			auto lowest = *bottom[j].begin();
			max_y = max(max_y, lowest.first);
			min_y = min(min_y, lowest.first);
		}
	}

	//debug(max_y, min_y);
	time_to_disappear = max_y - min_y;

	//debug(time_to_disappear);

	/**
	 * Queries
	 */
	int last_time = -1;
	int time_passed = 0;

	cin >> q;
	while (q--)
	{
		cin >> t >> a;

		if (last_time == -1)
			last_time = t;
		else
		{
			time_passed += t - last_time;
			last_time = t;

			// To-do: clean loop through time.
		}

		debug(time_passed);
	}
}
