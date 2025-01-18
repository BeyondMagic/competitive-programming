#include "library.hpp"

using namespace std;

int main ()
{
	int n;
	cin >> n;

	long long q;
	long long c;

	// <pos, size>
	vector<pair<long long, long long>> positions;

	// <total, begin, end>
	//vector<tuple<int, int, int>> removed;

	int rm_i = 0;


	while (cin >> q)
	{
		if (q == 1 or q == 3)
			cin >> c;
		else
			c = -1;
		
		if (q == 1)
		{
			if (positions.empty())
			{
				positions.emplace_back(0, c);
			}
			else
			{
				auto last = positions.back();
				positions.emplace_back(last.second + last.first, c);
			}
		}
		else if (q == 2)
		{
			auto front = positions[rm_i];
			auto total = int(positions.size());
			//if (rm_i)
			//{
			//	auto [rm_l_size, rm_l_begin, rm_l_end] = removed.back();
			//	removed.emplace_back(front.first + front.second, rm_l_end + 1, positions.size());

			//	for (int i = rm_i; i < total; ++i)
			//		positions[i].first -= front.first + front.second;

			//} else {
			//	removed.emplace_back(front.first + front.second, 1, positions.size());
			//}
			for (int i = rm_i; i < total; ++i)
				positions[i].first -= front.first + front.second;
			positions[rm_i] = make_pair(0, 0);
			++rm_i;
		}
		else if (q == 3)
		{
			auto k = rm_i + c;
			//debug(k, c);
			auto mine = positions[k - 1];
			print << mine.first << endl;
			//for (auto &[size, begin, end] : removed)
			//{
			//	print << "here: " << size << space << begin << space << end << endl;
			//	if (c >= begin and c <= end)
			//	{
			//		mine.first -= size;
			//	}
			//}

			//debug(mine, removed);
		}
	}
	//debug("last", positions);
}
