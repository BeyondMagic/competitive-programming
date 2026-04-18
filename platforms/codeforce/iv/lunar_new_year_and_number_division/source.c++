#include "library.hpp"

using namespace std;

// n is always even
// groups must contain at least 2 numbers
// there are m groups
// sum of these numbers in the j-th group is s_j
// minimize the sum of the square of s_
// sum_(j = 1)^m s^2_j

int main ()
{
	auto n = read<long long>();
	auto v = read<vector<long long>>(n);
	sort(begin(v), end(v));

	long long s = 0;

	for (long long i = 0, j = n - 1; i * 2 != n; ++i, --j)
		s += (v[i] + v[j]) * (v[i] + v[j]);

	cout << s << endl;
}
