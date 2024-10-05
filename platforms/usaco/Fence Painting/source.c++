#include "library.hpp"

using namespace std;

int main ()
{
	auto [a, b, c, d] = read<int, int, int, int>();
	if (a <= d and b >= c)
		print << max({a, b, c, d}) - min({a, b, c, d}) << endl;
	else
		print << b - a + d - c << endl;
}
