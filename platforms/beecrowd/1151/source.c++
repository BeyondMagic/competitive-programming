#include <iostream>
#include <map>

using namespace std;

size_t fibonacci(size_t n)
{
	static std::map<size_t, size_t> cache{{0, 0}, {1, 1}};

	auto found = cache.find(n);

	if (found != std::end(cache))
		return found->second;

	size_t result = fibonacci(n - 1) + fibonacci(n - 2);
	cache[n] = result;
	return result;
}
int main ()
{
	size_t n;
	cin >> n;
	for (size_t i = 0; i < n; ++i)
		cout << fibonacci(i) << (i == n - 1 ? '\n' : ' ');
}
