#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		auto V = read<vector<int>>(7);
		sort(begin(V), end(V));
		V.back() *= -1;
		cout << accumulate(begin(V), end(V), 0) * -1 << endl;
	}
}
