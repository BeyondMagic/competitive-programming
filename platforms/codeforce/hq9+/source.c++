#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	char c;
	while (cin >> c)
		switch (c)
			case 'H': case 'Q': case '9':
				return puts("YES"), 0;
	puts("NO");
}
