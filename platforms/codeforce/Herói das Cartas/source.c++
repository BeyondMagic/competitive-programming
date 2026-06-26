#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<int>();
	auto V = read<vector<long long>>(n);
	for (auto &v : V)
		v = abs(v);
	sort(rbegin(V), rend(V));
	cout << V[0] * V[1] * V[2] << endl;
}
