#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	string s;
	cin >> s;
	while (true)
	{
		size_t i;
		for (i = 0; i < s.length(); ++i)
			if (s[i] == s[i+1])
			{
				s.erase(i,2);
				break;
			}
		if (i == s.length())
			break;
	}
	if (s.length())
		cout << "nao\n";
	else
		cout << "sim\n";
}
