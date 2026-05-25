#include "library.hpp"

using namespace std;

#define MAX 1000000

int main()
{
	fast_io();
	auto [l, r] = read<long long, long long>();

	if (r / 2 - l / 2 > 1)
		cout << 2 << endl;
	else
		cout << l << endl;
}
