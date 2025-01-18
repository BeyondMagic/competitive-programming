#include "library.hpp"

using namespace std;

int main ()
{
	long long n;
	cin >> n;
	for (long long i = 2; i < n; ++i)
	{
		if (n % i == 0)
			n /= i;
		else
			break;
	}
	print << n << endl;
}
