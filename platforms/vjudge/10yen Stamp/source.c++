#include "library.hpp"

using namespace std;

int main ()
{
	auto [x, y] = read<double, double>();
	if (x > y)
		print << 0 << endl;
	else
		print << ceil((y - x) / 10) << endl;
}
