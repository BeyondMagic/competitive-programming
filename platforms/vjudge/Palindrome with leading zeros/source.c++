#include "library.hpp"

using namespace std;

string s;

bool check_palindrome (string &a, int i, int j)
{
	for (; i < j; ++i, --j)
		if (a[i] != a[j])
			return false;
	return true;
}

int main ()
{
	cin >> s;

	auto n = int(s.size());

	int start = -1, end = -1;

	for (int i = 0; i < n; ++i)
		if (s[i] != '0')
		{
			start = i;
			break;
		}

	for (int j = n - 1; j >= 0; --j)
		if (s[j] != '0')
		{
			end = j;
			break;
		}

	print << (check_palindrome(s, start, end) ? "Yes" : "No") << endl;
}
