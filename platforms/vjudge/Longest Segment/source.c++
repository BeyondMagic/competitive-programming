#include "library.hpp"

using namespace std;

int main ()
{
	auto N = read<int>();
	vector<pair<int, int>> P(N);
	for (auto &[a, b] : P)
		cin >> a >> b;

	double greatest = 0;

	for (auto [a, b] : P)
		for (auto [c, d] : P)
			greatest = max(greatest, hypot(c - a, d - b));

	print << fixed << setprecision(10) << greatest << endl;

}
