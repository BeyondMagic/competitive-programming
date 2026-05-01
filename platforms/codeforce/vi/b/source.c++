#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto T = read<int>();
	while (T--)
	{
		auto [n, s, t] = read<int, int, int>();
		auto k = abs(s - t) + n - max(s, t) + 1;
		cout << k << endl;
	}
}
