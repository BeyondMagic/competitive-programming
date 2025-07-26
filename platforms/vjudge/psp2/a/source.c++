#include "library.hpp"

using namespace std;

int main ()
{
	string s;
	cin >> s;
	ranges::sort(s);
	int n = 1;
	while (next_permutation(begin(s), end(s)))
		++n;
	cout << n << endl;
}
