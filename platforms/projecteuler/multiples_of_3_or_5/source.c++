#include <iostream>
#include <numeric>

using namespace std;

#define endl '\n'

constexpr auto sum_divisible (const size_t &n, const size_t &d)
{
	const size_t k = (n - 1) / d;
	return d * (k * (k + 1)) / 2;
}

constexpr auto lcm (const size_t &a, const size_t &b)
{
	return a * b / gcd(a, b);
}

int main ()
{
	size_t n, a, b;
	cin >> n >> a >> b;

	const auto n_a = sum_divisible(n, a);
	const auto n_b = sum_divisible(n, b);
	const auto lcm_ab = sum_divisible(n, lcm(a, b));

	cout << "sum n / a = " << n_a << endl;
	cout << "sum n / b = " << n_b << endl;
	cout << "sum n / lcm(a, b) = " << lcm_ab << endl;

	cout << n_a + n_b - lcm_ab << endl;
}
