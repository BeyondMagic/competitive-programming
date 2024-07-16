#include "library.hpp"

using namespace std;

int zeros_a_direita(int n)
{
	int zeros = 0;
	int p = 5;
	while (n / p)
		zeros += n / p,
		  p *= 5;
	return zeros;
}

int main ()
{
	print << zeros_a_direita(read<int>()) << endl;
}
