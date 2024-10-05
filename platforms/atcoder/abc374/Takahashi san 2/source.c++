#include "library.hpp"

using namespace std;

int main ()
{
	auto s = read<string>();
	auto l = s.length();
	if (s[l - 1] == 'n' and s[l - 2] == 'a' and s[l - 3] == 's')
		print << "Yes";
	else
		print << "No";
	print << endl;
}
