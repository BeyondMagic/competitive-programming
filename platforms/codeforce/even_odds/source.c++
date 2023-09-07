#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	int64_t n, k;

	cin >> n >> k;

	// real position
	n = k - (n + 1) / 2;

	if (n > 0)
		cout << 
	cout << (n > 0 ? 2 * n : 2 * k - 1);
}
