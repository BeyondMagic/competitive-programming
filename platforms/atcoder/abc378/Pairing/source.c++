#include "library.hpp"

using namespace std;

int main ()
{
	vector<int> count(4 + 1);
	for (int i = 1; i <= 4; ++i)
		++count[read<int>()];
	debug(count);
	auto ans = 0;
	for (int i = 1; i <= 4; ++i)
		ans += count[i] / 2;
	print << ans << endl;
}
