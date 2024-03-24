#include <iostream>
#include <cmath>

using namespace std;

#define endl '\n'

int main()
{
	int n, m, p;
	cin >> n >> m >> p;
	int see = n - m + 1;
	if (see <= 0)
		see = 0;
	else
		see = int(ceil(double(see) / double(p)));
	cout << see << endl;
}
