#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [x, y] = read<long long, long long>();

	auto s = abs(x) + abs(y);

	auto x1 = 0,
		 y1 = 0,
		 x2 = 0,
		 y2 = 0;

	if (x > 0 and y > 0)
	{
		y1 = s;
		x2 = s;
	} else if (x < 0 and y > 0)
	{
		x1 = -s;
		y2 = s;
	} else if (x > 0 and y < 0)
	{
		y1 = -s;
		x2 = s;
	} else if (x < 0 and y < 0) {
		x1 = -s;
		y2 = -s;
	}

	cout << x1 << space << y1 << space << x2 << space << y2 << endl;

}
