#include "library.hpp"

using namespace std;

int t = 0;

vector<string> graph;

int w, h;

void dfs(int i, int j) {
	if (graph[i][j] == '#')
		return;

	graph[i][j] = '#';

	if (i)
		dfs(i - 1, j);
	if (j)
		dfs(i, j - 1);
	if (i < h - 1)
		dfs(i + 1, j);
	if (j < w - 1)
		dfs(i, j + 1);
}
 
int main ()
{
	cin >> h >> w;
	string s;
	for (int i = 0; i < h; ++i)
		cin >> s,
		graph.emplace_back(s);

	debug(graph);

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (graph[i][j] == 'F')
				++t,
				dfs(i, j);

	print << t << endl;
}
