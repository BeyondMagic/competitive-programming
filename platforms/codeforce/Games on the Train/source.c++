#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		auto n = read<int>();
		auto H = read<vector<int>>(n);
		auto mi = *min_element(begin(H), end(H));
		auto ma = *max_element(begin(H), end(H));
		cout << ma + 1 - mi << endl;
	}
}
