#include "library.hpp"

using namespace std;

int main ()
{
	auto [a, b, c, d] = read<double, double, double, double>();
	auto ans = (a * d + b * c) / (b + d);
	print << setprecision(10) << fixed;
	print << ans << endl;
}
