#include "library.hpp"

using namespace std;

// array a = of 2n positive integers
// compress a into an array b of size n - 1
// he discards exactly 2 (any two) elements from a
// he then performs the following operation until there are no elements left in a
// - remove any two elements from a and append their sum to b
// b must have gcd of all its elements greater than 1, no number should be co-prime, which means they must have at least one divisor that is not one

int main()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		auto n = read<int>();
		vector<int> A(n * 2);
		int o = 0, e = 0;
		for (auto &a : A)
		{
			cin >> a;
			if (even(a))
				++e;
			else
				++o;
		}
		debug(n, A);
		// the only case that the gcd MAY not be or 2 ror , is when n = 2
		if (n == 2)
		{
			cout << 1 << space << 2 << endl;
		}
		// the gcd is 2
		else if (o <= 2 or e <= 2)
		{
			debug("gcd 2");
			vector<int> ps;
			// only print out the evens
			if (o <= 2)
			{
				for (int i = 0; i < 2 * n; ++i)
					if (even(A[i]))
						ps.emplace_back(i);
			}
			else
			{
				for (int i = 0; i < 2 * n; ++i)
					if (odd(A[i]))
						ps.emplace_back(i);
			}
			auto sz = int(ps.size());
			for (int i = 0; i < sz; ++i)
			{
				cout << ps[i];
				if (even(i))
					cout << space;
				else
					cout << endl;
			}
			// auto endd = prev(end(ps));
			// for (auto it = begin(ps); it != endd; it = next(next(it)))
			// 	cout << *it << space << *next(it) << endl;

		// the gcd is 3
		} else {
			debug("gcd 3");
			vector<int> ps;
			set<int> marked;
			for (int i = 0, j; i < n; ++i)
			{
				j = i + 1;
				while (marked.count(j) == 1 or (A[i] + A[j]) mod 3 != 0)
					++j;
				marked.emplace(j);
			}

			auto sz = int(ps.size());
			for (int i = 0; i < sz; ++i)
			{
				cout << ps[i];
				if (even(i))
					cout << space;
				else
					cout << endl;
			}
		}
	}
}
