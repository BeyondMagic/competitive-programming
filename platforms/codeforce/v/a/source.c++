#include "library.hpp"

using namespace std;


int main ()
{
	auto t = read<int>();

	while (t--)
	{
		auto [n, x] = read<int, int>();

		if (n <= 2)
		{
			cout << 1 << endl;
			continue;
		}

		auto k = (n - 3) / x + 2;

		cout << k << endl;
	}
}
