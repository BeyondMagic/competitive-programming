#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, q] = read<int, int>();
	vector<int> A(n);
	for (auto &a : A)
		cin >> a;

	ranges::sort(A);

	debug(n);
	for (int x; cin >> x and q--;)
	{
		auto result = lower_bound(begin(A), end(A), x);
		print << end(A) - result << endl;
	}
}
