#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	char c;
	while (cin >> c)
	{
		switch (c)
		{
			case 'a': case 'e': case 'i': case 'o': case 'u':
				break;
			default:
				putchar(c);
				break;
		}
	}
	putchar('\n');
}
