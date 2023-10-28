#include <iostream>
#include <cstdint>
#include <map>

using namespace std;

#define endl '\n'

uintmax_t fibonacci (uintmax_t n)
{
	static map<uintmax_t, uintmax_t> cache{{0, 0}, {1, 1}};

	auto found = cache.find(n);
	if (found != end(cache))
		return found->second;

	if (cache[n - 1] > 4'000'000)
	{
		cerr << "Exceeded cache limit value..." << endl;
		exit(1);
	}

	cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return cache[n];
}

int main()
{
	uintmax_t n;
	cin >> n;
	uintmax_t sum = 0;
	for (uintmax_t i = 1; i <= n; ++i)
	{
		const auto result = fibonacci(i);
		sum += result & 1 ? result : 0;
	}
	cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
	cout << "Sum of even until Fibonacci(" << n << ") = " << sum << endl;
}
