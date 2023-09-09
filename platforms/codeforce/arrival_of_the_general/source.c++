#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
size_t seconds = 0;

void print_v (vector<size_t> &ss, const char m)
{
	cout << m << " - " << seconds << " =";
	for (auto &i : ss)
		cout << ' ' << i;
	putchar('\n');
}

int main()
{
	size_t n;
	cin >> n;
	vector<size_t > ss(n);
	size_t mini = 500, ni = 0,
		   maxi = 0, xi = 0;
	for (size_t i = 0; i < n; ++i)
	{
		cin >> ss[i];
		if (ss[i] <= mini)
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

	/*cout << "maior " << maxi << " esta em " << xi + 1 << endl;
	cout << "menor " << mini << " esta em " << ni + 1 << endl;

	print_v(ss, 'm');*/
	while (ss[0] != maxi or ss[n - 1] != mini)
	{
		// cout << "ni + 1 = " << ni << " xi = " << xi << endl;
		if (ni + 1 == xi)
		{
			swap(ss[ni], ss[xi]);
			++ni;
			--xi;
			++seconds;
			// print_v(ss, 'c');
			continue;
		}

		if (ss[n - 1] != mini and ni + 1 < n)
		{
			swap(ss[ni], ss[ni + 1]);
			++seconds;
			// print_v(ss, 'm');
			++ni;
			continue;
		}

		// make movement
		if (ss[0] != maxi and xi != 0)
		{
			swap(ss[xi], ss[xi - 1]);
			++seconds;
			// print_v(ss, 'r');
			--xi;
			continue;
		}

	}
	cout << seconds << endl;
}
