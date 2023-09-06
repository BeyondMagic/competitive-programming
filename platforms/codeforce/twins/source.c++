#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	vector<size_t> c(n);
	size_t a = 0;
	for (auto &m : c)
	{
		cin >> m;
		a += m;
	}
	sort(rbegin(c), rend(c));
	size_t w = 0, w_c = 0;
	for (auto &m : c)
	{
		a -= m;
		w += m;
		++w_c;
		if (w > a)
			break;
	}
	cout << w_c << endl;
}
