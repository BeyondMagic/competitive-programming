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

struct UFDS
{
	vector<int> size, ps;

	UFDS (int N) : size(N, 1), ps(N)
	{
		iota(ps.begin(), ps.end(), 0);
	}

	int find_set(int x)
	{
		return x == ps[x] ? x : (ps[x] = find_set(ps[x]));
		// return x == ps[x] ? x : find_set(ps[x]);
	}

	bool same_set(int x, int y)
	{
		return find_set(x) == find_set(y);
	}

	void union_set(int x, int y)
	{
		if (same_set(x, y))
			return;

		int p = find_set(x);
		int q = find_set(y);

		//if (size[p] < size[q])
		//	std::swap(p, q);

		ps[q] = p;
		size[p] += size[q];
	}
};

int main ()
{
	fast_io();

	print << ":)" << endl;
}
