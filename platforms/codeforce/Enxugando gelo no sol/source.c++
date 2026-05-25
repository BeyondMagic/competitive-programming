#include "library.hpp"

using namespace std;

#define M 1000000007

int main()
{
	fast_io();
	auto n = read<uint128>();

	auto a = ( (n * (n - 1) / 2) mod M) * ( (n * (n - 1) / 2) mod M) mod M;
	auto b = ((2 * n - 1) * ((n * (n - 1)) mod M)) mod M;
	auto c = (11 * (n * (n - 1)) / 2) mod M;
	auto d = (6 * n) mod M;

	auto ans = (a + b) mod M;
	ans = (ans + c) mod M;
	ans = (ans + d) mod M;

	cout << ans << endl;
}
