#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		auto n = read<int>();
		vector<pair<long long, long long>> P;
		for (long long i = 0, a, b; i < n; ++i)
			cin >> a >> b,
			P.emplace_back(a, b);

		if (P.size() == 1)
		{
			cout << 0 << endl;
			continue;
		}

		sort(begin(P), end(P));

		auto [Fs, Fe] = P.at(0);
		auto [Es, Ee] = P.at(n - 1);

		auto ans = Es - Fe;
		//if (ans < 0)
		//	ans = 0;

		debug(P);
		cout << ans << endl;
	}
}
