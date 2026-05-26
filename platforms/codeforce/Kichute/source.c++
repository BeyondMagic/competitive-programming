#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto a = read<uint128>();
	auto b = read<uint128>();
	uint128 ans = 1;
	uint128 M = 1000000007;
	while (b--)
		ans = (ans * a) mod M;
	cout << ans << endl;
}
