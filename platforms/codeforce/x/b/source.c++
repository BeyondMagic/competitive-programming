#include "library.hpp"

using namespace std;

// position x = a
// position x = b
// position x = c

vector<int> moves = {
	0,
	1,
	-1
};

int main()
{
	fast_io();
	auto t = read<long long>();
	while (t--)
	{
		auto [A, B, C] = read<long long, long long, long long>();
		long long a, b, c;
		auto mx = LONG_LONG_MAX;
		for (auto &ax : moves)
		{
			a = A + ax;
			for (auto &bx : moves)
			{
				b = B + bx;
				for (auto &cx : moves)
				{
					c = C + cx;
					mx = min(mx, abs(a - b) + abs(a - c) + abs(b - c));
				}
			}
		}
		cout << mx << endl;
	}
}
