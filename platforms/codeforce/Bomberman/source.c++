#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [n, x] = read<int, int>();
	do {
		cout << n << endl;
	} while (--n);
	for (int i = 0; i < x * 2 + 1; ++i)
	{
		for (int j = 0; j < x * 2 + 1; ++j)
			cout << (i == x or j == x ? '*' : space);
		cout << endl;
	}
}
