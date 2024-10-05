#include "library.hpp"

using namespace std;

void weird (long long n)
{
	while (n)
	{
		print << n << (n == 1 ? endl : space);
		if (n == 1)
			--n;
		else if (n & 1)
			n = n * 3 + 1;
		else
			n = n / 2;
	}
}

int main ()
{
	auto n = read<long long>();

	weird(n);
}
