#include <iostream>
#include <array>

using namespace std;

#define endl '\n'

int main()
{
	scanf("%*d");
	array<int, 4 + 1> groups{0};
	int n;

	while (cin >> n)
		++groups[size_t(n)];

	int c = groups[4] + groups[3] + (groups[2] / 2);

	groups[1] -= groups[3];
	if (groups[2] % 2)
	{
		++c;
		groups[1] -= 2;
	}
	if (groups[1] > 0)
		c += groups[1] / 4;

	if (groups[1] % 4 and groups[1] > 0)
		++c;

	cout << c << endl;

}
