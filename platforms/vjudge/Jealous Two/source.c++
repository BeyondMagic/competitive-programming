#include "library.hpp"

using namespace std;

int main ()
{
	auto N = read<int>();
	vector<pair<int, int>> I(N);
	for (auto &[a, _] : I)
		cin >> a;
	for (auto &[_, b] : I)
		cin >> b;

	vector<pair<int, int>> T, A;
	for (auto &[a, b] : I)
		T.emplace_back(a, b),
		A.emplace_back(b, a);

	ranges::sort(T);
	ranges::sort(A);

	debug(T);
	debug(A);

	// No mínimo vai ter N: dar o mesmo presente para ambos.
	auto ans = N;

	// Algoritimo para descobrir o resto:
	// Escolhe uma e vai fazendo o resto enquanto poder.
	for (int i = 0; i < N; ++i)
	{
		auto [x, y] = T[i];
		for (int j = 0; j < N; ++j)
			if (
		auto [b, a] = A[i];

		debug(a, b);
		while (x > a and y < b)
		{
			++i;

			++ans;
		}
	}

	print << ans << endl;
}
