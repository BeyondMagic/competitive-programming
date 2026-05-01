#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<long long>();
	while (t--)
	{
		auto [n, m] = read<long long, long long>();
		auto A = read<vector<long long>>(n);
		auto S = accumulate(begin(A), end(A), 0);
		cout << (S == m ? "YES" : "NO") << endl;
	}
}
