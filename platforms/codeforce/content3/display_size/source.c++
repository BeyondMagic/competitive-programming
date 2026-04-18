#include "library.hpp"

using namespace std;

// the support is 


int main ()
{
	int n;
	cin >> n;

	int k = INT_MAX,
		A = 1,
		B = n;

	set<int> div{1, n};

	for (int a = 1; a * 2 <= n; ++a)
	{
		if (n % a == 0)
		{
			div.insert(a);
		}
	}

	auto ite = div.rbegin();
	auto itb = div.begin();
	for (; itb != div.end(); ++itb, ++ite)
	{
		// cout << ": " << *itb << space << *ite << endl;
		int a = *itb, b = *ite;

		if (b - a < 0)
			break;

		if (a * b == n and b - a < k)
		{
			k = b - a;
			A = a;
			B = b;
		}
	}

	cout << A << space << B << endl;
}
