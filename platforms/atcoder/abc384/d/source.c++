#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, s] = read<unsigned long long, unsigned long long>();
	vector<unsigned long long> A(n);
	for (auto &a : A)
		cin >> a;

	auto max = 8;
	for (int i = 1, k = 0; i <= max; ++i)
	{
		unsigned long long div = 0;

		for (auto j = 1; j <= i; ++j)
			div += A[k++];
			//print << 1 << space;
		for (auto j = 1; j <= max - i; ++j)
			++k;
			//print << 0 << space;

		if (s / div)
			return print << "Yes" << endl, 0;
	}

	for (int i = 1, k = 0; i <= max; ++i)
	{
		unsigned long long div = 0;

		for (auto j = 1; j <= i; ++j)
			++k;
			//print << 0 << space;
		for (auto j = 1; j <= max - i; ++j)
			div += A[k++];
			//print << 1 << space;

		if (s / div)
			return print << "Yes" << endl, 0;
	}

	print << "No" << endl;
}
