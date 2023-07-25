#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
	size_t t;
	cin >> t;
	vector<char> s1(t);
	char l;
	for (size_t i = 0; i < t; ++i)
		cin >> s1[i];
	size_t s = t;
	for (size_t i = 0; i < t; ++i)
	{
		cin >> l;
		if (s1[i] != l)
			--s;
	}
	cout << fixed << setprecision(10) << double(s) / double(t) * 100. << endl;;
}
