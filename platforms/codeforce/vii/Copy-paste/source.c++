#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		auto [n, k] = read<int, int>();
		auto A = read<vector<int>>(n);

		sort(begin(A), end(A));
		auto m = A.at(0);

		int r = 0;

		// debug(n, k, A);
		for (int i = n - 1; i > 0; --i)
		{
			auto q = (k - A.at(i)) / m;
			r += q;
			A[i] += m * q;
		}
		// debug(A);

		cout << r << endl;
	}
}
