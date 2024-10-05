#include "library.hpp"

using namespace std;

int main ()
{
	auto [s, t] = read<string, string>();
	int m = min(s.length(), t.length());

	for (int i = 0; i < m; ++i)
		if (s[i] != t[i])
			return print << i + 1 << endl, 0;

	if (s.length() != t.length())
		return print << m + 1 << endl, 0;

	print << 0 << endl;
}
