#include "library.hpp"

using namespace std;

long long n;
vector<long long> A;
map<long long, long long> freq;

int main ()
{
	cin >> n;
	A.resize(n);
	for (auto &a : A)
		cin >> a,
		++freq[a];

	long long ans = n * (n - 1) / 2;

	for (auto &[_, c] : freq)
		ans -= c * (c - 1) / 2;

	print << ans << endl;
}
