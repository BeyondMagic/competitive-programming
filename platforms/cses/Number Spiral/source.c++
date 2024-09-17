#include "library.hpp"

using namespace std;

// 1 2 9 10 25
// 1 2 -> 9 10 -> 25 26

// 1 4 5 16 17
// 1 -> 4 5 -> 16 17 -> 256 257 -> 

int main ()
{
	auto t = read<int>();

	for (int x, y; cin >> x >> y and t--;)
		print << x << y << endl;
}
