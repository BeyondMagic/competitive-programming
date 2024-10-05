#include "library.hpp"

using namespace std;

long long f (long long n)
{
	long long s = 0;

	while (n > 0)
		n /= 5,
		s += n;

	return s;
}

int main ()
{
	long long n;
	cin >> n;

	long long
		inicio = 1,
	   fim = 1e17;

	while (inicio <= fim)
	{
		long long mid = (inicio + fim) / 2;

		if (f(mid) == n)
			return print << mid << endl, 0;

		else if (f(mid) > n)
			fim = mid - 1;

		else if (f(mid) < n)
			inicio = mid + 1;
	}

	print << -1 << endl;
}
