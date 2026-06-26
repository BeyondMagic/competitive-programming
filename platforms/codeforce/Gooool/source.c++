#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [T, G, D, X] = read<double, double, double, double>();
	debug(T, G, D, X);

	auto f = [&](long long n) -> double {
		auto N = double(n);
		return T * sqrt(N) + G * log2(N + 1) + D;
	};

	auto V = views::iota(0ll, 2'000'000'000'000'000'000ll);
	auto it = ranges::upper_bound(
		V,
		X,
		[&](double n, double target) {
			return n < target - EPSILON;
		},
		f
	);

	auto k = it == ranges::begin(V) ? 0 : *(--it);

	cout << k << endl;
}
