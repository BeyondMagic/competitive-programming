#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	int64_t n;
	cin >> n;
	cout << (n & 1 ? - (n + 1) / 2 : n / 2) << endl;
}
