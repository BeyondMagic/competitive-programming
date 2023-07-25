#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t l, // triples
		   b; // double
	cin >> l >> b;
	size_t y = 0;
	while (l <= b)
	{
		l *= 3;
		b *= 2;
		++y;
	}
	cout << y << endl;
}
