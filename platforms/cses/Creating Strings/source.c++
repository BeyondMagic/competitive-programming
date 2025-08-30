#include "library.hpp"

using namespace std;

list<string> ans;

int main ()
{
	auto s = read<string>();
	sort(begin(s), end(s));
	ans.emplace_back(s);
	while (next_permutation(begin(s), end(s)))
		ans.emplace_back(s);

	cout << ans.size() << endl;

	while (not ans.empty())
		cout << ans.front() << endl,
		ans.pop_front();
}
