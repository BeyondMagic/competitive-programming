#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		auto n = read<int>();
		int one = 0, two = 0;
		for (int i = 0, c = -1; i < n; ++i)
		{
			cin >> c;
			if (c == 2)
				++two;
			else
				++one;
		}
		auto ans = false;
		if (not two)
		{
			ans = even(one);
		} else if (not one)
		{
			ans = even(two);
		// there's two and one
		} else {
			if (odd(one + two * 2))
				ans = false;
			else {
				debug(one, two, one + two * 2);
				ans = true;
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
}
