#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	scanf("%*d");
	size_t n = 0;
	char b, c;
	cin >> b;
	while (cin >> c)
	{
		if (b == c)
			++n;
		b = c;
	}
	cout << n << endl;
}
