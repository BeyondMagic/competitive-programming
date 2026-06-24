#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<int>();
	int q = 0;
	string s;
	while (cin >> s)
	{
		if (s == "#")
		{
			cout << q << endl;
			break;
		}
		else
		{
			++q;
			debug(s, q);
			if (q == n + 1)
				q = 1;
		}
	}
}
