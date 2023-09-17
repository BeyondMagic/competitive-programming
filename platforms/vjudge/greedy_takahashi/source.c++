#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	long long a, b, k;
	cin >> a >> b >> k;
	a -= k;
	if (a < 0)
	{
		b += a;
		a = 0;
		if (b < 0)
			b = 0;
	}
	cout << a << ' ' << b << endl;
}
