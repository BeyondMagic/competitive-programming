#include "library.hpp"

using namespace std;

int n, m;

vector<int> colours;
map<int, int> S;
vector<int> distinct;
vector<vector<int>> P;

void dfs (int i = 1)
{
	// ja calculou
	if (distinct[i] != -1)
		return;

	auto c = colours[i];

	if (not S.count(c))
		S[c] = 1,
		distinct[i] = S.size();
	else
		++S[c],
		distinct[i] = S.size();

	for (auto &b : P[i])
		dfs(b);

	--S[c];
	if (S[c] == 0)
		S.erase(c);
}

int main()
{
	fast_io();
	cin >> n >> m;
	colours.resize(n + 1, -1);
	for (auto i = 1; i <= n; ++i) cin >> colours[i];
	P.resize(n + 1);
	distinct.resize(n + 1, -1);

	for (int i = 1, a, b; i <= n - 1; ++i)
	{
		cin >> a >> b;
		P[a].emplace_back(b);
		P[b].emplace_back(a);
	}
	dfs();
	for (int q; m--;)
		cin >> q,
		cout << distinct[q] << endl;
}
