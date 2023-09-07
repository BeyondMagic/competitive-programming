#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t a, b, c, m = 0;
	cin >> a >> b >> c;
	m = max(m, a + b + c);
	m = max(m, a * b + c);
	m = max(m, a * (b + c));
	m = max(m, a * b * c);
	m = max(m, a + b * c);
	m = max(m, (a + b) * c);
	cout << m << endl;
}
