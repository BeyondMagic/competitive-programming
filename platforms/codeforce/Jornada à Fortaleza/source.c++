/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define space ' '
#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<

static constexpr auto &print = cout;

inline auto
fast_io (void)
-> void {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

#ifdef LOCAL
	#include <debug.hpp>
#else
	#define debug(...)
#endif

/*
 * Read number or string from standard input and return it.
 */
template<
	typename T,
	enable_if_t<(is_arithmetic<T>::value or is_same_v<T, string>), bool> = true
>
inline auto
read ()
-> T
{
	T number;
	cin >> number;
	return number;
}

/*
 * Read tuple of (possible) diferent types from standard input and return it.
 */
template<
	typename... types,
	enable_if_t<(sizeof...(types) > 1), bool> = true
>
inline auto
read ()
-> tuple<types...>
{
	auto some_function = [](auto&& x)
	{
		cin >> x;
	};

	tuple<types...> T;
	apply(
		[&](auto &...x) {
			(..., some_function(x));
		}, T
	);

	return T;
}

/*
 * Print a vector of key data structures separated by a character and ended by a special character.
 */
template<
	typename T
>
ostream& operator<<(ostream& out, const vector<T>& vec)
{
	const auto vec_end = vec.end();
	const auto before = prev(vec_end);

	for (auto it = vec.begin(); it < vec_end; ++it)
		out << *it << (it == before ? endl : space);

	return out;
}

#define oo 1e9

pair<vector<int>, vector<int>> dijkstra(vector<vector<pair<int, int>>> &graph, int s, int n, vector<bool> &passed)
{
	vector<int>
		dist(n + 1, oo),
		pred(n + 1, oo);
	dist[s] = 0;
	pred[s] = s;

	vector<bool> processed(n + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, s);

	while (not pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();
		if (processed[u] or passed[u])
			continue;

		processed[u] = true;

		for (auto [v, w] : graph[u])
			if (dist[v] > d + w) {
				dist[v] = d + w;
				pred[v] = u;
				pq.emplace(dist[v], v);
			}
	}

	return { dist, pred };
}

vector<pair<int, int>> path (int s, int u, const vector<int>& pred)
{
  vector<pair<int, int>> p;
  int v = u;
  
  do {
    p.push_back(make_pair(pred[v], v));
    v = pred[v];
  } while (v != s);

  reverse(p.begin(), p.end());

  return p;
}

void solve ()
{
	auto [n, m] = read<int, int>();

	vector<vector<pair<int, int>>> graph(n + 1);

	for (int i = 1, u, v, w; i <= n; ++i)
	{
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);
	}

	int t = 0;

	vector<bool> passed(n, false);

	// caminho de ida
	auto [dist, pred] = dijkstra(graph, 1, n, passed);
	debug(dist);
	debug(pred);
	debug(path(1, n, pred));
	// for (auto [v, w] : way_1)
	// 	t += w,
	// 	passed[v] = true;

	// // caminho de volta
	// auto way_2 = dijkstra(graph, n, 1, passed);
	// for (auto [_, w] : way_2)
	// 	t += w;

	// // saída
	// print << t << space << way_1.size() << space << way_2.size();
	// for (auto l : {way_1, way_2})
	// 	for (auto it = begin(l); it != end(l) ; ++it)
	// 		print << *it << (it == end(l) ? endl : space);
}

int main ()
{
	fast_io();

	auto t = read<int>();
	while (t--)
		solve();
}
