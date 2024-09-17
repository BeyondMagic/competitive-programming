#include "library.hpp"

using namespace std;

int main ()
{
	auto N = read<long long>();

	auto ans = 0ll;

	for (int prev = 0, current; N-- and cin >> current; prev = current)
		if (prev > current)
			ans += prev - current,
			current += prev - current;

	print << ans << endl;
}
