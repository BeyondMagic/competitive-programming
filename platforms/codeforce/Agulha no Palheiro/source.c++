#include "library.hpp"

using namespace std;

#define MOD 1000000007

int n, m;
vector<string> G;
string S;

int main()
{
	fast_io();
	cin >> n >> m;
	G.resize(n);
	for (auto &S : G)
		cin >> S;
	auto q = read<int>();

	while (cin >> S)
	{
		auto k = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				if (S[k] == G[i][j])
					k = (k + 1) mod MOD;
			}
		cout << k << endl;
	}
}
