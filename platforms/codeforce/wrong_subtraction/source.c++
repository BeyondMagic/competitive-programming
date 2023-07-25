#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	string n;
	size_t t;
	cin >> n >> t;
	while (t--)
	{
		const auto c = size_t(n.back()) - '0';
		if (not c)
			n.pop_back();
		else if (c == t)
		{
			n.back() = 0;
			break;
		}
		else if (c < t)
		{
			cout << 1 << endl;
			n.back() = 0;
			t -= c;
		}
		else if (c > t)
		{
			n.back() = char(c - t) + '0';
			break;
		}
	}
	cout << n;
}
