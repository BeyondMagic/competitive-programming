#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<int>();
	auto k = n - ((n / 3 + n / 5) - n / 15);
	cout << k << endl;
}
