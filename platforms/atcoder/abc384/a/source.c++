#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, c1, c2] = read<int, char, char>();
	string s;
	cin >> s;

	for (auto &c : s)
		if (c != c1)
			c = c2;
	print << s << endl;
}
