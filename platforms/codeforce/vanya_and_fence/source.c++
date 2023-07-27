#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	scanf("%*d");
	size_t h;
	cin >> h;
	size_t p;
	size_t t = 0;
	while (cin >> p)
	{
		if (p > h)
			t += 2;
		else
			++t;
	}
	cout << t << endl;
}
