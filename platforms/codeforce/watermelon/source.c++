#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	for (size_t i = 1; i <= n/2; ++i)
		if (not (i & 1) and not ((n - i) & 1))
		{
			// cout << i << ' ' << n - i << endl;
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;
}
