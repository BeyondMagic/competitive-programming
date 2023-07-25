#include <iostream>
#include <cstdint>

using namespace std;

#define endl '\n'

int main()
{
	size_t m;
	cin >> m;
	int64_t x = 0, y = 0, z = 0,
			n; // sum of vectors...
	for (size_t i = 1; i <= m; ++i)
	{
		cin >> n;
		x += n;
		cin >> n;
		y += n;
		cin >> n;
		z += n;
	}
	cout << (not x and not y and not z ? "YES" : "NO") << endl;
}
