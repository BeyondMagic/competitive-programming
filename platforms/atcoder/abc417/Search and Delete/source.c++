#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, m] = read<size_t, size_t>();
	auto A = read<multiset<size_t>>(n);
	auto B = read<vector<size_t>>(m);
	for (auto &b : B)
		if (A.count(b))
			A.erase(A.find(b));
	cout << A << endl;
}
