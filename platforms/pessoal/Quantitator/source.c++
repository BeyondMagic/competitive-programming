#include "library.hpp"

using namespace std;

int main ()
{
	auto T = read<int>();
	string s;
	while (T-- and cin >> s)
		print << s.length() << endl;
}
