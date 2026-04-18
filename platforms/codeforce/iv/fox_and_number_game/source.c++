#include "library.hpp"

using namespace std;

int main ()
{
	auto n = read<long long>();
	auto V = read<vector<long long>>(n);

	long long mdc = V.front();

	for (auto v : V)
		mdc = gcd(mdc, v);

	cout << mdc * n << endl;
}
