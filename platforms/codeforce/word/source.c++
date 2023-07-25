#include <iostream>
#include <cctype>

using namespace std;

#define endl '\n'

int main()
{
	size_t iu = 0, il = 0;
	string s;
	{
		char c;
		while (cin >> c)
		{
			if (isupper(c))
				++iu;
			else
				++il;
			s.push_back(c);
		}
	}
	if (iu > il)
		for (const auto c : s)
			cout << char(toupper(c));
	else
		for (const auto c : s)
			cout << char(tolower(c));

	cout << endl;
}
