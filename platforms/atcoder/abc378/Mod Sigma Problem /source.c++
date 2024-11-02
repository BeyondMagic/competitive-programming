#include "library.hpp"

using namespace std;

int ans = 0;
int n, m;

vector<int> A;

void dfs(int i = 0, bool enable = false, int k = 0)
{
	if (i == n)
	{
		ans += k mod m;
		return;
	}

	if (enable)
		k += A[i];

	dfs(i + 1, true, k);
	//dfs(i + 1, false, k);
}

int main ()
{
	n = read<int>();
	m = read<int>();
	A.resize(n);
	for (auto &a : A)
		a = read<int>();

	debug(A);

	dfs(0, true);
	dfs(0, false);

	print << ans << endl;
}
