#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<int>();
	auto U = read<vector<int>>(n);
	auto M = map<int, int>();

	for (auto &u : U)
		++M[u];

	// fixed university from the one that apperas the most
	for (auto &[k, _] : M)
	{
		// fixed size of cover
		for (auto i = 1; i <= n; ++i)
		{
		}
	}
}
