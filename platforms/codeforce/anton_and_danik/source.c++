#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t a = 0, d = 0;
	scanf("%*d");
	char c;
	while (cin >> c)
		if (c == 'A')
			++a;
		else
			++d;
	if (a == d)
		puts("Friendship");
	else if (a < d)
		puts("Danik");
	else
		puts("Anton");
}
