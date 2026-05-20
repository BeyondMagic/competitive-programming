#include "library.hpp"

using namespace std;

long long solve(long long n)
{
	if (n <= 2)
		return n - 1;

	else if (odd(n))
		return 1 + solve(n - 1);

	else
		return 1 + solve(n / (n / 2));
}

int main()
{
	fast_io();
	auto t = read<long long>();

	while (t--)
	{
		auto n = read<long long>();

		cout << solve(n) << endl;
	}
}
