#include "library.hpp"

using namespace std;

int n, m;
string s;

int main ()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		for (int j = 0; j < m; ++j)
			if (s[j] == 'W')
				return cout << i + 1 << space << j + 1 << endl, 0;
	}
}
