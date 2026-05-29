#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<long long>();
	auto square = (long long)sqrt(float(n));
	auto min_area = square * 4;
	auto rest_blocks = n - square * square;
	auto ans = 0ll;
	if (rest_blocks == 0)
	{
		ans = min_area;
	} else if (rest_blocks <= square)
	{
		ans = min_area + 2;
	} else {
		ans = min_area + 4;
	}
	cout << ans << endl;
	debug(square, min_area, rest_blocks);
}
