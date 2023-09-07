#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		// cout << "teste " << t << endl;
		size_t n;
		cin >> n;
		vector<bool> visited(n, false);
		vector<pair<int, int>> traps(n), backup(n);
		for (size_t i = 0; i < n; ++i)
		{
			cin >> traps[i].first >> traps[i].second;
			backup[i] = traps[i];
			// printf("  trap %d with time %d\n", traps[i].first, traps[i].second);
		}

		int max = INT_MIN;
			
		bool dead = false;
		// new run
		for (int limit = 2;; ++limit)
		{
			// printf("NEW LIMIT %d\n", limit);
			
			int move = 1; // right, once per time
			for (size_t i = 0; i < n; ++i)
			{
				if (traps[i].first == 1)
				{
					// printf("activated at %d the %d trap with %d seconds\n", 1, traps[i].first, traps[i].second);
					--traps[i].second;
					visited[i] = true;
				}
			}
			// moving
			for (int p = 2; not dead and p != 1; p += move) {

				// printf("from %d moved to %d\n", p - move, p);
				// start moving left, back to room 1 when reaches limit
				if (p >= limit)
				{
					// printf("reached limit %d at %d\n", limit, p);
					move = -1;
				}

				// check traps
				for (size_t i = 0; i < n; ++i)
				{
					if (visited[i])
					{
						--traps[i].second;
						// printf("  trap %d time %d\n", traps[i].first, traps[i].second);
						if (traps[i].second < 0 and traps[i].first == p)
						{
							// printf("dead at %d with time %d\n", traps[i].first, traps[i].second);
							dead = true;
							break;
						}
					} else if (p == traps[i].first) {
						// printf("activated at %d the %d trap with %d seconds\n", p, traps[i].first, traps[i].second);
						--traps[i].second;
						visited[i] = true;
					}
				}
			}

				for (size_t i = 0; i < n; ++i)
				{
					if (visited[i])
					{
						--traps[i].second;
						// printf("  trap %d time %d\n", traps[i].first, traps[i].second);
						if (traps[i].second < 0 and traps[i].first == 1)
						{
							// printf("dead at %d with time %d\n", traps[i].first, traps[i].second);
							dead = true;
							break;
						}
					} else if (1 == traps[i].first) {
						// printf("activated at %d the %d trap with %d seconds\n", 1, traps[i].first, traps[i].second);
						--traps[i].second;
						visited[i] = true;
					}
				}
			if (dead)
			{
				// printf("finally dead at %d\n", limit);
				max = limit - 1;
				break;
			}

			for (size_t i = 0; i < n; ++i)
			{
				traps[i] = backup[i];
				visited[i] = false;
			}

		}
		cout << max << endl;


	}
}
