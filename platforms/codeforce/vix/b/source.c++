#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<long long>();
	while (t--)
	{
		auto [x, y] = read<long long, long long>();
		auto s = x - y;
		auto ans = s <= 1 ? "NO" : "YES" ;
		cout << ans << endl;
	}
}
