#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	string n;
	size_t t;
	cin >> n >> t;
	while (t--)
	{
		auto c = size_t(n.back()) - '0';
		if (not c)
			n.pop_back();
		else
		{
			--c;
			n.back() = char(c) + '0';
		}
		
	}
	cout << n;
}
