/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#define endl '\n'

#define MIN 10
#define MAX 2 * 100'000 + MIN
#define oo SIZE_MAX / 2

bitset<MAX> visited;

void depth_first_search (vector<vector<size_t>> &graph, vector<size_t> &answers, size_t root)
{
	if (visited[root])
		return;

	visited[root] = true;

	// process
	cout << ' ' << root;
	++answers[root];

	for (auto next : graph[root])
		depth_first_search(graph, answers, next);
}

void connected_components(vector<vector<size_t>> &graph, vector<size_t> &answers)
{
	visited.reset();

	for (size_t i = 1, count = 0; i + 1 <= graph.size(); ++i)
		if (not visited[i] and graph[i].size())
		{
			cout << "Component " << ++count << " : ";
			depth_first_search(graph, answers, i);
			cout << endl;
		}
}

struct UnionFind
{
	vector<long long> data;

	UnionFind(size_t n)
	{
		data.assign(n, -1);
	}

	long long find (long long x)
	{
		const size_t p = size_t(x);
		if (data[p] < 0)
			return x;
		return data[p] = find(data[p]);
	}

	bool unite (long long a, long long b)
	{
		a = find(a),
		b = find(b);

		if (a == b)
			return false;

		size_t pa = size_t(a),
			   pb = size_t(b);

		if (data[pa] > data[pb])
			swap(a, b), swap(pa, pb);

		data[pa] += data[pb];
		return data[pb] = a, true;
	}
};

vector<size_t> breadth_first_search(vector<vector<size_t>> &graph, size_t &source)
{
	const auto N = graph.size();

	vector<size_t> dist(N, oo);
	dist[source] = 0;
	
	queue<size_t> fila;
	fila.push(source);

	while (not fila.empty())
	{
		auto root = fila.front(); fila.pop();

		for (auto next : graph[root])
		{
			if (dist[next] == oo)
			{
				dist[next] = dist[root] + 1;
				fila.push(next);
			}
		}
	}

	return dist;
}

// Ideia: juntamos em uma "arvore" onde escolhemos um elemento aleatório para ser a cabeça de um componente
//        para cada vertice, dizemos qual é cabeça comum, MENOS se ele estiver sozinho.
//        A partir dai podemos contar 4 (vezes) em quantos componentes estão ligadas.
//        Para então cada componente dos dois grafos adicionamos em quantos componentes eles estão ligados.
//        É como se fosse uma ligação pareada de componente para componente.
//        Se vertices podem estar sozinhas, o mímimo de resposta para cada é 0 e o máximo 2.
//        !!!
//        A estrutura de dados UnionFind faz verificação de componentes em modo constante, assim esquivo do TLE.
int solve()
{
	size_t n;
	long long k, l;
	cin >> n >> k >> l;

	UnionFind roads(n + 1);
	UnionFind railways(n + 1);

	for (long long i = 1, p, q; i <= k; ++i)
		cin >> p >> q,
		roads.unite(p, q);

	for (long long i = 1, r, s; i <= l; ++i)
		cin >> r >> s,
		railways.unite(r, s);

	vector<long long> roads_heads(n + 1);
	vector<long long> railways_heads(n + 1);

	for (size_t i = 1; i <= n; i++)
		roads_heads[i] = roads.find((long long)i),
		railways_heads[i] = railways.find((long long)i);

	//       A          B         = componentes ligados
	map<pair<long long, long long>, size_t> components;

	// Calculamos a quantidade de componentes para cada vertice conectada...
	for (size_t i = 1; i <= n; ++i)
		++components[make_pair(roads_heads[i], railways_heads[i])];

	// Então resposta!
	for (size_t i = 1; i <= n; ++i)
		cout << components[make_pair(roads_heads[i], railways_heads[i])] << (i == n ? endl : ' ');

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	// cin >> t;
	while (t--)
		solve();
}
