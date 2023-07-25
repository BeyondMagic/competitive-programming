#include <iostream>
#include <cstdint>
#include <locale>

using namespace std;

#define endl '\n'

int main()
{
	string s;
	cin >> s;
	char c;
	{
		int sl, cl;
		for (size_t i = 0; cin >> c; ++i)
		{
			sl = tolower(s[i]);
			cl = tolower(c);
			if (sl < cl)
			{
				puts("-1");
				return EXIT_SUCCESS;
			} else if (sl > cl)
			{
				puts("1");
				return EXIT_SUCCESS;
			}
		}
	}
	puts("0");

}
