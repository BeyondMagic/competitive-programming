#include <bits/stdc++.h>

#ifdef LOCAL
	#include <debug.hpp>
#else
	#define debug(...)
#endif

using namespace std;

constexpr auto &print = cout;

/* Make code more humane. */
#define endl '\n'
#define space ' '
#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<

/* Disconnect C. */
inline auto
fast_io (void)
-> void {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

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


using namespace std;

struct UnionFind {

	int largest = 0, components;

	vector<int> size, parent;

	UnionFind (int N) : size(N + 1, 1), parent(N + 1)
	{
		components = N;
		iota(parent.begin(), parent.end(), 0);
	}

	int find_set (int x)
	{
		return x == parent[x] ? x : (parent[x] = find_set(parent[x]));
	}

	bool same_set (int x, int y)
	{
		return find_set(x) == find_set(y);
	}

	void union_set (int x, int y)
	{
		if (same_set(x, y))
			return;

		auto P = find_set(x);
		auto Q = find_set(y);

		if (size[P] < size[Q])
			swap(P, Q);

		parent[Q] = P;
		size[P] += size[Q];

		// New processing to get the number of components every time there is a union between vertices.
		--components;

		// New processing for getting the quantity of vertices in the largest component:
		if (size[P] > largest)
			largest = size[P];
	}
};

int main ()
{
	auto [N, M] = read<int, int>();

	UnionFind graph(N);

	for (int a, b; cin >> a >> b;)
		graph.union_set(a, b),
		print << graph.components << space << graph.largest << endl;
}
