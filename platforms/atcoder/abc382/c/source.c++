#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, m] = read<long long, long long>();
	vector<pair<long long, long long>> A(n), B(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i].first,
		A[i].second = i;
	}
	ranges::sort(A);
	ranges::sort(B);

	for (int i = 0, b; i < m; ++i)
	{
		cin >> b;
		auto pos_v = lower_bound(begin(A), end(A), make_pair(b, b));
		auto pos_i = lower_bound(begin(B), end(B), make_pair(pos->, b));
		debug(pos->first, pos->second);
		if (pos == end(A))
			print << -1 << endl;
		else
			print << pos->second + 1 << endl;
	}
}
