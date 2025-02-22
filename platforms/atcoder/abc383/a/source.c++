#include "library.hpp"

using namespace std;

int main ()
{
	int n;
	cin >> n;
	int ans = 0, last = 0;

	int t, l;
	while (cin >> t >> l)
	{
		if (last)
		{
			ans -= t - last;
			if (ans < 0)
				ans = 0;
		}
		ans += l;
		last = t;
	}
	print << ans << endl;
}
