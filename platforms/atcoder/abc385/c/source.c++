#include "library.hpp"

using namespace std;

int n;
vector<int> H;
multiset<int> M;
set<int> N;

int main ()
{
	cin >> n;
	H.resize(n);
	for (auto &h : H)
	{
		cin >> h;
		N.emplace(h);
		M.emplace(h);
	}

	set<pair<int, int>, greater<pair<int, int>>> order;

	for (auto &m : N)
		order.emplace(M.count(m), m);

	for (auto &o : order)
		cout << o.first << space << o.second << endl;
	
}
