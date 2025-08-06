#include "library.hpp"

using namespace std;

int main ()
{
	auto t = read<size_t>();
	while (t--)
	{
		auto [a, b] = read<size_t, size_t>();

		auto sum = a + b;

		if (not (sum % 3) and (a <= b * 2) and (b <= a * 2))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
