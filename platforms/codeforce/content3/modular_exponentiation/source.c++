#include "library.hpp"

using namespace std;

int main ()
{
	auto n = read<long long>();
	auto m = read<long long>();

	// m mod 2^n

	auto ans = m % 2**n;
}
