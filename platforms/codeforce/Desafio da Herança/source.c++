#include "library.hpp"
#include <assert.h>

using namespace std;

int main()
{
	fast_io();
	auto [n, m] = read<int, int>();
	map<int, int> M;
	for (int i = 0, x; i < m; ++i)
		cin >> x,
		++M[x];
	auto mi = -1, mk = -1;
	for (auto &[k, q] : M)
		if (q * k >= mi and k > mk)
		{
			mk = k;
			mi = q * k;
		}
	assert(mi != -1 and mk != -1);
	cout << mi << space << mk << endl;
}
