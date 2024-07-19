#include "library.hpp"

using namespace std;

int main ()
{
	auto T = read<int>();
	print << fixed << setprecision(2);
	const auto pi = 2 * acos(0.0);
	for (int i = 1; T--; ++i)
	{
		auto r = read<double>();
		auto circle = pi * r * r;
		auto square = 4 * r * r;
		print << "Case " << i << ": " << square - circle << endl;
	}
}
