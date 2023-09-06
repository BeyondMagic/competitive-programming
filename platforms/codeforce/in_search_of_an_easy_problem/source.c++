#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	scanf("%*d");
	bool n;
	while (cin >> n)
		if (n)
			return puts("HARD"), 0;
	puts("EASY");
}
