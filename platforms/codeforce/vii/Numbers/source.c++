#include "library.hpp"

using namespace std;

long long decimal_to_base (long long number, long long base)
{
	auto ans = 0ll;

	while (number)
		ans += number % base,
		number /= base;

	return ans;
}

int main()
{
	fast_io();
	auto A = read<long long>();

	auto s = 0ll;
	auto k = 0ll;

	for (auto i = 2ll; i <= A - 1; ++i)
		s += decimal_to_base(A, i),
		++k;

	auto g = gcd(s, k);

	cout << s / g << '/' << k / g << endl;
}
