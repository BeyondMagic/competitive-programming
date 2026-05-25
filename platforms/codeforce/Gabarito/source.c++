#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<int>();
	auto A = read<vector<char>>(n);
	auto B = read<vector<char>>(n);
	double p = 0, q = n;
	for (auto i = 0; i < n; ++i)
		if (A[i] == B[i])
			++p;

	cout << fixed << setprecision(10);

	cout << (p / q) * 100.0l << endl;
}
