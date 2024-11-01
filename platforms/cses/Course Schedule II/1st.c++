#include "library.hpp"

using namespace std;

using ii = pair<int, int>;

vector<int> topological_sort(int N, vector<set<int>> &in, vector<set<int>> &out)
{
	vector<int> o;
	queue<int> q;
	set<int> backup;
	vector<bool> mark(N + 1, false);

	for (int u = 1; u <= N; ++u)
		if (in[u].empty())
		{
			vector<int> rem;

			for (auto b : backup)
				if (b >= u)
					break;
				else
				{
					//debug(b, u);
					rem.emplace_back(b);

					// add
					if (o.back() == b)
						continue;

					//debug(o, b);
					o.emplace_back(b);
					mark[b] = true;
				}

			for (auto r : rem)
				backup.erase(r);

			q.push(u);

			while (not q.empty())
			{
				auto k = q.front();
				q.pop();

				if (mark[k])
					continue;

				//debug(o, k);
				mark[k] = true;
				o.emplace_back(k);

				for (auto v : out[k])
				{
					in[v].erase(k);

					if (in[v].empty())
						backup.emplace(v);
				}
			}
		}

	for (auto b : backup)
		o.emplace_back(b);

	//debug(backup);
	//debug(in);
	//debug(out);

	return o;
	//return (int) o.size() == N ? o : vector<int> { };
}

int main ()
{
	auto [n, m] = read<int, int>();

	vector<set<int>>
		in(n + 1),
		out(n + 1);

	while (m--)
	{
		auto [a, b] = read<int, int>();
		out[a].emplace(b);
		in[b].emplace(a);
	}

	// debug(out);
	// debug(in);

	auto o = topological_sort(n, in, out);
	//debug(o);

	for (int i = 0; i < n; ++i)
		print << o[i] << (i + 1 == n ? endl : space);
}
