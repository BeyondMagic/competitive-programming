#include <iostream>
#include <cmath>

using namespace std;

#define endl '\n'

int main()
{
	size_t t;
	cin >> t;
	while (t--)
	{
		size_t a, b;
		cin >> a >> b;
		size_t r = size_t(ceil(double(a) / double(b)));
		cout << r * b - a << endl;
	}
}
