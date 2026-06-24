#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [m, n] = read<int, int>();
	auto k = 'A';
	for (auto i = 0; i < n; ++i)
	{
		for (auto j = 0; j < m; ++j)
		{
			cout << k++;
			if (k == 'Z' + 1)
				k = 'A';
		}
		cout << endl;
	}
}
