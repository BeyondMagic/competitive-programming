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

int main ()
{
	auto n = read<size_t>();
	vector<size_t> ids(n);
	for (auto &id : ids)
		cin >> id;

	queue<tuple<size_t, size_t, vector<size_t>>> Q;
	for (size_t i = 0; i < n; ++i)
	{
		vector<size_t> C(ids[i]);
		for (auto &c : C)
			cin >> c;

		Q.emplace(i + 1, ids[i], C);
	}

	for (int i = 0, ans = 0; not Q.empty(); i = 0)
	{
		auto [id, k, C] = Q.front();
		Q.pop();

		// trocar para for
		while (k and C[i] != 1)
			k--,
			ans += 10,
			++i;

		if (not k)
			print << id << " (" << ans << ")\n";
		else
		{
			C[i] = 0;
			for (size_t j = 0; j < k; ++j)
				C[j] = C[i++];

			Q.emplace(id, k, C);
		}

	}

}
