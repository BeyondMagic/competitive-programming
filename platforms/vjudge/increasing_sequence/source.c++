#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	scanf("%*d");
	int d;
	cin >> d;

	int times = 0;
	int last;
	cin >> last;
	int current;
	while (cin >> current)
	{
		if (current <= last)
		{
			int t = (last - current) / d + 1;
			times += t;
			current += t * d;
		}
		last = current;
	}
	cout << times << endl;
}
