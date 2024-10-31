#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, q] = read<int, int>();

	int total = 0;

	for (int h, t; n--;)
	{
		cin >> h >> t;
	}

	print << total << endl;
}
