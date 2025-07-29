#include "library.hpp"

using namespace std;

int main ()
{
	string s;
	cin >> s;

	auto n = int(s.size());

	bool has_o = false;

	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '#')
		{
			has_o = false;
			continue;
		}
		else if (s[i] == '.' and not has_o)
		{
			s[i] = 'o';
			has_o = true;
		}
	}

	print << s << endl;
}
