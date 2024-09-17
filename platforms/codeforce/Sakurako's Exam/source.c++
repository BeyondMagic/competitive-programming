#include "library.hpp"

using namespace std;

int main ()
{
	auto N = read<int>();

	int b = 0;

	while (N--)
	{
		auto [ones, twos] = read<int, int>();

		int s = 0;

		for (int i = 0, c = b; i < min(ones + twos, 20) and c; ++i, c >>= 1)
				


		

		b += 1;
	}
}
