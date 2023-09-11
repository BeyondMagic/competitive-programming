#include <cmath>
#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;

	string s;
	for (size_t i = 0; i <= n; ++i)
	{
		char d = '-';
		cout << "divisors = {";
		for (size_t j = 1; j <= 9; ++j)
		{
			if (n % j == 0 and (n / j) % (i + 1) == 0)
				cout << ' ' << j << ',';
		}
		cout << " }\n";

		s.push_back(d);
	}

	cout << s << endl;
}
