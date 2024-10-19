#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, q] = read<int, int>();

	int total = 0;

	int l = 1,
		r = 2;

	for (int i = 1; i <= q; ++i)
	{
		auto [h, t] = read<string, int>();

		// print << h << space << t << endl;

		debug(h);

		if (h == "L")
		{
			debug(t, r, l);
			int b = total;
			if (t > r) {
				if (l < r)
				{
					total += n - r + l - 1;
				}
				else
					total += l - t;
			} else {
				if (l < r)
				{
					debug(t, l);
					total += t - l;
				}
				else
					total += n - l + t;
			}
			l = t;
			debug(total, total - b);
		} else {
			debug(t, r, l);
			int b = total;
			if (t > l) {
				if (r < l)
					total += r - (n - t);
				else
					total += t - r;
			} else {
				if (r < l)
					total += t - r;
				else
					total += n - r + t;
			}
			r = t;
			debug(total, total - b);
		}
	}

	print << total << endl;
}
