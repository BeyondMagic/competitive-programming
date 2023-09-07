#include <iostream>
#include <cmath>

using namespace std;

#define endl '\n'

int main()
{
	size_t t;
	size_t a, // contains grams of water
		   b, // contains grams of water
		   c; // hold grams of water
	cin >> t;
	// What is the minimum number of moves required to make the masses of water in the vessels equal?
	while (t--)
	{
		cin >> a >> b >> c;
		size_t m = 0;
		if (max(a, b) - min(a, b))
			m += size_t( ceil((double(max(a, b)) - double(min(a, b))) / 2.0 / double(c)) );
		cout << m << endl;
	}
}
