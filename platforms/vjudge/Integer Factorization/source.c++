#include "library.hpp"

using namespace std;

auto fast_mul (long long a, long long b, long long m)
{
	long long res = 0;

	while (b)
	{
		if (b & 1)
			res += (res + a) % m;

		a = (a + a) % m;
		b >>= 1;
	}

	return res;
}

auto f (long long x, long long c, long long m)
{
    return (fast_mul(x, x, m) + c) % m;
}

auto rho (long long n, long long x0 = 2, long long c = 1)
{
	auto x = x0;
	auto y = x0;
	long long g = 1;
	while (g == 1)
	{
		// Tartaruga (um passo):
		x = f(x, c, n);

		// Lebre (dois passos):
		y = f(y, c, n);
		y = f(y, c, n);

		g = gcd(abs(x - y), n);
	}
	return g;
}

int main ()
{
	auto n = read<int>();

	print << "A factor is = " << rho(n) << endl;
}
