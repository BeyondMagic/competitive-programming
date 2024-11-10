#include "library.hpp"

using namespace std;

int main ()
{
	auto [a, b, c] = read<char, char, char>();
	print << b << c << a << space << c << a << b << endl;
}
