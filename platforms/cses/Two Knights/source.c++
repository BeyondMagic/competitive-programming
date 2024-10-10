#include "library.hpp"

using namespace std;

int main ()
{
	auto k = read<int>();

	for (int i = 1; i <= k; ++i)
	{
		long long k1 = i * i;
		long long k2 = i * i - 1;
		long long attacked = 4 * (i - 2) * (i - 1);

		print << k1 * k2 / 2 - attacked << endl;
	}
}
