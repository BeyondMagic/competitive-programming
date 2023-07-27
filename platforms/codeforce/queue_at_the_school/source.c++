#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	scanf("%*d ");

	size_t t;
	cin >> t;

	string s;
	cin >> s;

	while (t--)
		for (size_t i = 0; i < s.length() - 1; ++i)
			if (s[i] == 'B' and s[i + 1] == 'G')
			{
				swap(s[i], s[i + 1]);
				++i;
			}
	cout << s << endl;
}
