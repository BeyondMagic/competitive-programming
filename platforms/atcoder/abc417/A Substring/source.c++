#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, a, b] = read<size_t, size_t, size_t>();
	auto s = read<string>();
	auto t = s.substr(a, n - a - b);
	cout << t << endl;
}
