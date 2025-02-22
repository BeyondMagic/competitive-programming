#include "library.hpp"

using namespace std;

int n, q, c, p, h, pos;

int ans = 0;

int main ()
{
	cin >> n >> q;

	vector<bool> counted(n, false);

	vector<set<int>> nests(n);

	// map PIGEON id to NEST id;
	map<int, int> pigeons;

	for (int i = 1; i <= n; ++i)
		pigeons[i] = i,
		nests[i - 1].insert(i);

	while (q--)
	{
		cin >> c;

		// 1 P H: move pigeon P to nest H;
		if (c == 1)
		{
			cin >> p >> h;

			if (pigeons[p])
			{
				pos = pigeons[p] - 1;

				nests[pos].erase(p);

				if (counted[pos] and nests[pos].size() <= 1)
				{
					--ans;
					counted[pos] = false;
				}
			}

			pos = h - 1;
			nests[pos].insert(p);
			if (not counted[pos] and nests[pos].size() > 1)
				++ans,
				counted[pos] = true;

			pigeons[p] = h;

		// 2: output the number of nests that contain ore than one pigeon
		} else {
			print << ans << endl;
		}
	}

}
