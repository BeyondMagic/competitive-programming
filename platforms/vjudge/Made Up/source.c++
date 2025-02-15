#include "library.hpp"

using namespace std;

int n;
vector<int> A, B, C, freq;

int main ()
{
	cin >> n;

	A.resize(n);
	B.resize(n);
	C.resize(n);
	freq.resize(n + 1);

	for (auto &a : A)
		cin >> a;

	for (auto &b : B)
		cin >> b;

	for (auto &c : C)
		cin >> c,
		--c;

	long long ans = 0;

	for (int i = 0; i < n; ++i)
		++freq[A[i]];

	for (int i = 0; i < n; ++i)
		ans += freq[B[C[i]]];

	print << ans << endl;
}
