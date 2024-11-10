#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, m, s] = read<int, int, string>();

	int k = 0, ans = 0;

	for (int i = 0; i < n; ++i)
		if (s[i] == 'O')
		{
			if (++k == m)
			{
				++ans;
				k = 0;
			}
		} else
			k = 0;

	print << ans << endl;
}
