#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, d, s] = read<int, int, string>();
	int ans = 0;
	for (int i = 0; i < int(s.length()); ++i)
	{
		if (d)
		{
			if (s[i] == '@')
				--d;
			++ans;
		} else if (s[i] == '.')
			++ans;
	}
	print << ans << endl;
}
