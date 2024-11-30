#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, d, s] = read<int, int, string>();
	for (int i = s.length(); i >= 0; --i)
	{
		if (d and s[i] == '@')
		{
			--d;
			s[i] = '.';
		}
	}
	print << s << endl;
}
