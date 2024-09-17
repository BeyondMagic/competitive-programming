#include "library.hpp"

using namespace std;

size_t f(size_t t)
{
	return t * t + 2 * t + 3;
}

int main ()
{
	auto t = read<size_t>();
	print << f(f(f(t) + t) + f(f(t))) << endl;
}
