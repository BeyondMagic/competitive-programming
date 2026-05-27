#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [a, b] = read<uint128, uint128>();
	cout << a << space << b << endl;
	debug("Hello, World!");
}