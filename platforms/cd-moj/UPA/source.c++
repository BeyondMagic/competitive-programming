#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<int>();
	vector<pair<int, int>> T;
	for (int i = 0, a, b; i < n; ++i)
	{
		cin >> a >> b,
		T.emplace_back(a, +1),
		T.emplace_back(b, -1);
	}
	sort(begin(T), end(T));
	auto k = 0;
	auto a = 0;
	for (auto &[t, p] : T)
		k += p,
		a = max(a, k);
	cout << a * 20 << endl;
}
