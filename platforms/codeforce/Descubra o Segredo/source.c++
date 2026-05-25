#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();

	while (t--)
	{
		auto [A, B] = read<string, string>();
		auto n = int(A.length());

		for (int i = 0; i < n; ++i)
		{
			auto ok = true;

			for (int j = 0; j < n; ++j)
			{
				auto x = (i + j) mod n;

				if (A[j] != B[x])
				{
					ok = false;
					break;
				}
			}

			if (ok)
			{
				auto a = n - i;
				auto b = i;
				cout << min(a, b) << endl;
				break;
			}
		}
	}
}

// 12345
// 12 345

// 12345
// 5 1234

// 12345
// 12345
