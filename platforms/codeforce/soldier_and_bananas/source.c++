#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t k, // first value of the first banana
		   n, // dollars
		   w; // bananas he wants to buy
	cin >> k >> n >> w;
	const auto M = k * (w * (w + 1)) / 2;
	if (M <= n)
		puts("0");
	else
		cout << M - n << endl;
}
