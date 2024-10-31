#include "library.hpp"

using namespace std;

long long ans = 0;

int main ()
{
	auto n = read<long long>();
	auto sum_first = (n * (n + 1ll)) / 2ll;
	if (sum_first & 1)
		return print << "NO" << endl, 0;
}
