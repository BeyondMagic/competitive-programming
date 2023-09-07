#include <iostream>
#include <set>

using namespace std;

#define endl '\n'

int main()
{
	set<size_t> ns;
	{
		size_t n;
		while (cin >> n)
			ns.emplace(n);
	}
	cout << 4 - ns.size() << endl;
}
