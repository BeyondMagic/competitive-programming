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

		vector<vector<bool>> dp;
		for (auto i = 0; i < n; ++i)

		// ele quer sempre minimizar (y - x)
		// ou seja, escolher o menor x possível para que não importa o y que ele escolha, seja menor que k
	}
}
