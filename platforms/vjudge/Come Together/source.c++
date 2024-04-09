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
 * Read integer from standard input and return it.
 */
template<
	typename T,
	enable_if_t<is_arithmetic<T>::value, bool> = true
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
 * Read string from standard input and return it.
 */
template<
	typename T,
	enable_if_t<is_same_v<T, string>, bool> = true
>
inline auto
read ()
-> T
{
	T str;
	cin >> str;
	return str;
}

/*
 * Read pair of perhaps different somethings from standard input and return it.
 */
template<
	typename T,
	typename K
>
inline auto
read ()
-> pair<T, K>
{
	pair<T, K> P;
	cin >> P.first >> P.second;
	return P;
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

auto solve ()
{
	auto A = read<int, int>(),
		 B = read<int, int>(),
		 C = read<int, int>();

	B = make_pair(B.first - A.first, B.second - A.second);
	C = make_pair(C.first - A.first, C.second - A.second);

	auto Q = 1;

	debug(A, B, C);

	if (
		// Not parallel.
		B.first + C.first and (
			// After/before vertical axis.
			((B.first > 0 and C.first > 0) or (B.first < 0 and C.first < 0))
			or
			// Different across vertical axis.
			((B.first < 0 and C.first > 0) or (B.first > 0 and C.first < 0))
		)
	)
	{
		auto y = min(abs(B.second), abs(C.second));
		Q += y;
		B.second -= y;
		C.second -= y;

		debug(A, B, C);
	}

	if (
		// Not parallel.
		B.second + C.second and (
			// After/before horizontal axis.
			((B.second > 0 and C.second > 0) or (B.second < 0 and C.second < 0))
			or
			// Different across horizontal axis.
			((B.second < 0 and C.second > 0) or (B.second > 0 and C.second < 0))
		)
	)
		Q += min(abs(B.first), abs(C.first));

	return Q;
}

int main ()
{
	fast_io();

	auto T = read<int>();
	
	while (T--)
		print << solve() << endl;
}
