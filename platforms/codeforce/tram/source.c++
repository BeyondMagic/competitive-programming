#include <iostream>
#include <cstdint>

using namespace std;

#define endl '\n'

int main()
{
	int64_t max = -1;
	scanf("%*d");
	int64_t l, e, c = 0;
	while (cin >> l >> e)
	{
		c -= l;
		c += e;
		if (c > max)
			max = c;
	}
	cout << max << endl;
}
