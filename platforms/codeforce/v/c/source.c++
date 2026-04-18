#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, a, b] = read<int, int, int>();
	auto moves = a + b;
	auto k = moves mod n;
	if (k <= 0)
		k += n;
	cout << k << endl;
}
