#include "library.hpp"

using namespace std;

int main()
{

	fast_io();
	auto t = read<long long>();

	while (t--)
	{
		auto [a, b, n] = read<long long, long long, long long>();

		auto ans = -1ll;

		n %= 3;

		if (not n)
			ans = a;
		else if (n == 1)
			ans = b;
		else if (n == 2)
			ans = b ^ a;

		cout << ans << endl;

	}
}
