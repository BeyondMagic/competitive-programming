#include "library.hpp"

using namespace std;

int main ()
{
	int m = -1;
	int s = 0;
	int ms = 0;

	for (int i = 1; i <= 5; ++i)
	{
		int a;
		cin >> a;
		if (a != i)
		{
			++s;
			if (s == 2)
				++ms;
			m = max(m, s);
		} else {
			s = 0;
		}
	}

	print << (m == 2 and ms == 1 ? "Yes" : "No") << endl;
}
