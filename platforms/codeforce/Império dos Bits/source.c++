#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = -1uz;
	auto k = 0uz;

	while (cin >> n)
	{
		if (not n)
			break;
		k = 0;
		while (n != 1)
		{
			n = popcount(n);
			++k;
		}
		cout << k << endl;
	}
}
