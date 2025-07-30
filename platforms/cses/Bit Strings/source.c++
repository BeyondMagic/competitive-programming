#include "library.hpp"

using namespace std;

auto M = 1'000'000'007uz;

int main ()
{
	auto n = read<size_t>();
	auto ans = power(2uz, n, M);
	cout << ans % M << endl;
}
