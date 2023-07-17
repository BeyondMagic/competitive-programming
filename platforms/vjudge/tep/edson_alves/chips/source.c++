#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	int n, m;
	cin >> n >> m;
	int iteration_sum = n * (n + 1) / 2;
	int sum = iteration_sum;
	while (sum + iteration_sum <= m)
		sum += iteration_sum;
	if (sum <= m)
		m -= sum;
	// cout << "sum = " << sum << endl;
	// cout << "1 m = " << m << endl;
	// last loop
	for (int i = 1; i <= n; ++i)
		if (m - i < 0)
			break;
		else
			m -= i;
	cout << m << endl;
	//cout << "2 m = " << m << endl;
}
