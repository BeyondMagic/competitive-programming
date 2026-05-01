#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<long long>();

	for (int I = 2; I <= n; ++I)
	{
		auto S1 = (long long)I;
		auto S2 = (n * n + n) / 2 - S1;
		if (gcd(S1, S2) != 1)
		{
			cout << "Yes" << endl;
			cout << 1 << space << S1 << endl;
			cout << n - 1 << space;
			for (auto i = 1; i <= n; ++i)
			{
				if (i != I)
					cout << i << (i == n ? endl : space);
			}
			return 0;
		}
	}

	cout << "No" << endl;
}
