#include "library.hpp"

using namespace std;

int main ()
{
	auto [q, pages, pickpage] = read<int, int, int>();

	deque<int> D;
	D.emplace_back(pickpage);

	int page_faults = 1;
	--pages;

	while (pages)
	{
		cin >> pickpage;

		auto search = find(begin(D), end(D), pickpage);

		if (search == D.end())
		{
			if (int(D.size()) != q)
				D.emplace_back(pickpage);
			else {
				D.pop_front();
				D.emplace_back(pickpage);
			}
			++page_faults;
		} else
			rotate(search, next(search), end(D));

		--pages;
	}
	print << page_faults << endl;
}