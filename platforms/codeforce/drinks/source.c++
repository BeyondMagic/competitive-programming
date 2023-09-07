#include <iostream>
#include <iomanip>

using namespace std;

#define endl '\n'

int main()
{
	cout << fixed << setprecision(12);
	double n, v, t = 0;
	cin >> n;
	while (cin >> v)
		t += v;
	cout << t / n << endl;
	printf("%d", int(t));
}
