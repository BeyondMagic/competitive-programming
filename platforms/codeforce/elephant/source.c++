#include <iostream>
#include <array>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	size_t m = 0;
	for (size_t i = 5; i >= 1; --i)
	{
		m += n / i;
		n %= i;
	}
	cout << m << endl;
}
