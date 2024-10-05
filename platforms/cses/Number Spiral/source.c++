#include "library.hpp"

using namespace std;

int main ()
{
	auto t = read<int>();

	for (unsigned long long i, j; cin >> i >> j and t--;)
	{
		if (max(i, j) mod 2) {
			if (i <= j)
				print << max(i, j) * max(i, j) - i + 1;
			else
				print << max(i - 1, j) * max(i - 1, j) + j;
		} else {
			if (i >= j)
				print << max(i, j) * max(i, j) - j + 1;
			else
				print << max(i, j - 1) * max(i, j - 1) + i;
		}
		print << endl;
	}
}
