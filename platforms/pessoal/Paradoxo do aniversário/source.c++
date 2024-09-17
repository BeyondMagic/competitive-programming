#include "library.hpp"

using namespace std;

auto number_people(double d, double q)
{
	double p = 1,
		   s = 1;
	while ( q > (1.0 - p) )
	{
		p *= (d - s++) / d;
		debug(p, s);
	}
	return s;
}

int main ()
{
	print << number_people(365, 10) << endl;
	// auto t = read<int>();
	// while (t--)
	// 	print << number_people(365, read<double>()) << endl;
}
