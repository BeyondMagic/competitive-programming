#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<int>();
	auto PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater_second<pair<int, int>>>();
	auto M = map<int, int>();

	for (auto i = 0, x = -1; i < n; ++i)
		cin >> x,
		++M[x];

	for (auto &[k, v] : M)
		PQ.emplace(k, v);

	vector<int> X;

	while (not PQ.empty())
	{
		auto [k, v] = PQ.top(); PQ.pop();

		if (X.size() ? k == X.back() : false)
		{
			if (not PQ.empty())
			{
				auto [r, q] = PQ.top(); PQ.pop();
				PQ.emplace(k, v);
				k = r; v = q;
			} else {
				return cout << -1 << endl, 0;
			}
		}

		X.emplace_back(k);
		--v;

		if (v)
			PQ.emplace(k, v);
	}

	cout << X << endl;
}
