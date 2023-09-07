#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	vector<size_t > ss(n);
	size_t mini = 0, ni = 0,
		   maxi = 0, xi = 0;
	for (size_t i = 0; i < n; ++i)
	{
		cin >> ss[i];
		if (ss[i] < mini)
		{
			ni = i;
			mini = ss[i];
		}
		if (ss[i] > maxi)
		{
			xi = i;
			maxi = ss[i];
		}
	}
	size_t seconds = 0;
	while (ss[0] != maxi and ss[n - 1] != mini)
	{
		// make movement
		if (ss[0] != maxi)
		{
			swap(ss[xi], ss[xi - 1]);
			--xi;
			++seconds;
		}
		if (ss[n - 1] != mini)
		{
			swap(ss[ni], ss[ni + 1]);
			++ni;
			++seconds;
		}
	}
	cout << seconds << endl;
}
