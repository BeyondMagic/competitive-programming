#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t n, t = 1;
	cin >> n;
	if (n == 1)
		return puts("1"), 0;
	string s, l;
	cin >> l;
	while (cin >> s)
	{
		if (s[0] != l[0])
			++t;
		l = s;
	}
	cout << t << endl;
}
