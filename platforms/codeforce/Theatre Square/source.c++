#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, m, a] = read<int, int, int>();
	auto w = (n + a - 1) / a;
	auto h = (n + a - 1) / a;
	print << w * h << endl;
}
