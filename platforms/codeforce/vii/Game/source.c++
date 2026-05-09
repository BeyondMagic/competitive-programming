#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto a = read<size_t>();
	if (odd(a))
		cout << 1 << endl;
	else
		cout << 2 << endl;
}
