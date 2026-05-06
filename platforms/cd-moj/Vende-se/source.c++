#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [n, k] = read<long long, long long>();
	auto V = read<vector<long long>>(n);
	sort(begin(V), end(V));

	auto m = LONG_LONG_MAX,
		 size = n - k;

	for (long long i = n - 1, d, r, l; i >= 0; --i)
	{
		if (i - size + 1 < 0)
			break;

		r = V.at(i);
		l = V.at(i - size + 1);
		d = r - l;
		m = min(m, d);
	}

	cout << m << endl;
}
