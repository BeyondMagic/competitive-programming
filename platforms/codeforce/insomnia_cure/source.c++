#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	size_t u = 0;
	for (size_t i = 1; i <= d; ++i)
		if (not (i % k) or not (i % l) or not (i % m) or not (i % n))
			++u;
	cout << u << endl;
}
