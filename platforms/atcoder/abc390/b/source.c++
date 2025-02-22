#include "library.hpp"

using namespace std;

int main ()
{
	long long a, last_a, next;
	long long n;
	cin >> n;
	double r;

	for (long long i = 1; i <= n; ++i)
	{
		cin >> a;
		if (i == 1)
		{
			last_a = a;
			continue;
		} else if (i == 2) {
			r = (double)a / (double)last_a;
			last_a = a;
		} else {
			next = r * last_a;
			last_a = a;

			if (next != a)
			{
				return print << "No" << endl, 0;
			}
		}
	}

	cout << "Yes" << endl;
}
