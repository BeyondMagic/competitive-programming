#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	string s;

	string o;
	cin >> o;
	for (size_t i = 0; i < o.size(); ++i)
		if (o[i] == 'W' and o[i + 1] == 'U' and o[i + 2] == 'B')
		{
			i += 2; // + 1 from condition
			const auto n = s.size();
			if (n and s[n - 1] != ' ')
				s.push_back(' ');
		}
		else
			s.push_back(o[i]);


	cout << s << endl;
}
