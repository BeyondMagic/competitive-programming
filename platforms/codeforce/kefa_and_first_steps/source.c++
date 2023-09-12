#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	scanf("%*d");
	size_t a, l, t = 1, m = 1;
	cin >> l;
	while (cin >> a)
	{
		if (l <= a)
		{
			++t;
			if (m < t)
				m = t;
		}
		else
			t = 1;
		l = a;
	}
	cout << m << endl;
}
