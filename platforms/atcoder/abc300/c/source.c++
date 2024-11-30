#include "library.hpp"

using namespace std;

vector<string> M;
vector<int> S;
int h, w;

int lu = 0, ld = 0, ru = 0, rd = 0;

set<pair<int, int>> pos;

void printm () {
	for (int i = 0; i < h; ++i)
		cout << M[i] << endl;
}

void dfs (int i, int j, int &size) {

	if (i < 0 or i >= h or j >= w or j < 0 or M[i][j] == '.')
		return;

	if (size != -1)
		++size;

	pos.emplace(i, j);
	M[i][j] = '.';

	dfs(i + 1, j + 1, ru);
	dfs(i + 1, j - 1, rd);
	dfs(i - 1, j + 1, lu);
	dfs(i - 1, j - 1, ld);
}

int main ()
{
	cin >> h >> w;
	auto n = min(h, w);
	S.resize(n);
	M.resize(h);
	for (auto &m : M)
		cin >> m;

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (M[i][j] == '#')
			{

				int k = -1;
				lu = 0, ld = 0, ru = 0, rd = 0;
				dfs(i, j, k);
				if (lu == ld and ld == ru and ru == rd)
				{
					++S[lu - 1];
				} else {
					for (auto &[ii, jj] : pos)
						M[ii][jj] = '#';
				}
				pos.clear();
			}

	for (auto i = 0; i < n; ++i)
		cout << S[i] << (i + 1 == n ? endl : space);
}
