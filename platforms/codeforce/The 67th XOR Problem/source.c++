#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		auto n = read<int>();
		auto V = read<vector<int>>(n);
		auto m = 0;

		for (auto &a : V)
			for (auto &b : V)
				m = max(m, a xor b);

		cout << m << endl;
	}
}
