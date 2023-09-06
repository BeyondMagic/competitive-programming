#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	scanf("%*d");
	int s, p, t = 0;
	while (cin >> s >> p)
		if (p - s >= 2)
			++t;
	cout << t << endl;
}
