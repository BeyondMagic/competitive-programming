#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	list<char> L;
	char c;
	while (cin >> c)
		L.emplace_back(c);
	for (auto it1 = begin(L), it2 = next(begin(L)); it2 != end(L);)
	{
		if (*it1 == *it2)
		{
			auto tmp1 = it1;
			auto tmp2 = it2;
			++it2;

			if (it1 != L.begin()) {
				--it1;
				L.erase(tmp1);
				L.erase(tmp2);
			} else {
				L.erase(tmp1);
				L.erase(tmp2);
				it1 = L.begin();
				it2 = (L.size() < 2) ? L.end() : next(it1);
			}
		} else {
			++it1;
			++it2;
		}
	}
	cout << (L.size() ? "nao" : "sim") << endl;
}
