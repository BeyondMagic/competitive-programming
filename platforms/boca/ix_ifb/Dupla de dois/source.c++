#include "library.hpp"

using namespace std;

int main ()
{
	auto n = read<int>();

	vector<pair<int, string>> col;

	for (int i = 0; i < n; ++i)
	{
		auto [s, p] = read<string, int>();
		col.emplace_back(p, s);
	}

	sort(begin(col), end(col));

	debug(col);

	int b = 0, l = 0;

	for (int i = 0; i * 2 < n; ++i)
	{
		int k = col[i].first + col[n - i - 1].first;

		if (i)
			b = max(b, abs(k - l));
		l = k;
	}

	print << b << endl;

	for (int i = 0; i * 2 < n; ++i)
	{
		print << col[i].second << space << col[i].first <<
		space << col[n - i - 1].second << space << col[n - i - 1].first << endl;
	}
}
