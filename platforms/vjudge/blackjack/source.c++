#include <iostream>

int main()
{
	using namespace std;
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c >= 22)
		cout << "bust\n";
	else
		cout << "win\n";
}
