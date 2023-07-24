#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	string s;
	while (n--)
	{
		cin >> s;
		const auto length = s.length();
		if (length <= 10)
			cout << s << endl;
		else
			cout << s[0] << length - 2 << s[length - 1] << endl;
	}
}
