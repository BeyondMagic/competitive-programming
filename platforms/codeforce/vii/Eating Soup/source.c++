#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [n, m] = read<int, int>();

	int ma = (n) / 2;

	if (not m)
		cout << 1 << endl;
	else if (m == n)
		cout << 0 << endl;
	else if (ma >= m)
		cout << m << endl;
	else
		cout << n - m << endl;
}
