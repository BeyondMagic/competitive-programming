#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	char c, l;
	cin >> l;
	size_t r = 1;
	while (cin >> c)
		if (l != c)
		{
			r = 1;
			l = c;
		}
		else
		{
			++r;
			if (r == 7)
			{
				puts("YES");
				return 0;
			}
		}
	puts("NO");
}
