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

int main ()
{
	fast_io();

	auto [S, K] = read<string, int>();
	auto N = int(S.length());

	// sums[r] - sums[l] : quantity of dots between these two places
	vector<int> sums(N + 1, 0);
	for (int i = 0; i < N; ++i)
		if (S[i] == '.')
			sums[i + 1] = sums[i] + 1;
		else
			sums[i + 1] = sums[i];

	auto ans = 0;

	for (int l = 0, r = 0; l < N; ++l)
	{
		while (r < N and sums[r + 1] - sums[l] <= K)
			++r;
		ans = max(ans, r - l);
	}

	print << ans << endl;
}
