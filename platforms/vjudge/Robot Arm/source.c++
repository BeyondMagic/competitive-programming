#include "library.hpp"

using namespace std;

const auto pi = 2 * acos(0.0);

int main ()
{
	auto [a, b, c] = read<float, float, float>();
	auto outer_r = a + b + c;
	auto inner_r = abs(a + b - c);
	inner_r = min(inner_r, abs(b + c - a));
	inner_r = min(inner_r, abs(c + a - b));
	debug(outer_r);
	debug(inner_r);

	auto outer = outer_r * outer_r * pi;
	auto inner = inner_r * inner_r * pi;

	print << fixed << setprecision(10);
	print << outer - inner << endl;
}
