#include "library.hpp"

using namespace std;

int main ()
{
	auto [a, b, c] = read<int, int, int>();

	if (
			(a == b and b == c) or
			(a + b == c) or
			(a + c == b) or
			(b + c == a)
		)
		print << "Yes" << endl;
	else
		print << "No" << endl;

}
