#include <iostream>
#include <cstdint>

using namespace std;

#define endl '\n'

int main()
{
	uint64_t n, m, a;
	cin >> n >> m >> a;

	if (m < n)
		swap(m, n);

	if (a >= m)
		cout << (n + a - 1) / a << endl;
	else
		cout << ((m + a - 1) / a) * ((n + a - 1) / a) << endl;
}
