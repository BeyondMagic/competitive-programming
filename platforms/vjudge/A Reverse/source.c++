#include "library.hpp"

using namespace std;

int main ()
{
	auto [l, r] = read<int, int>();
	auto s = read<string>();

	--l;
	--r;

	string s2;
	for (int i = l; i <= r; ++i)
		s2.push_back(s[i]);

	ranges::reverse(s2);
	debug(s2);

	auto ln = int(s.length());
	for (int i = 0; i < ln; ++i)
		if (i < l)
			print << s[i];
		else if (i == l)
			print << s2;
		else if (i > r)
			print << s[i];
	print << endl;
}
