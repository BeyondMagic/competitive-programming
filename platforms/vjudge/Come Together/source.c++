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

	auto Q = 1;

	if (
			(B.second - A.second >= 0 and C.second - A.second >= 0) or
			(B.second - A.second <= 0 and C.second - A.second <= 0)
		)
		Q += min(abs(A.second - B.second), abs(A.second - C.second));

	if (
			(B.first - A.first >= 0 and C.first - A.first >= 0) or
			(B.first - A.first <= 0 and C.first - A.first <= 0)
		)
		Q += min(abs(A.first - B.first), abs(A.first - C.first));

	return Q;
}

int main ()
{
	fast_io();

	auto T = read<int>();
	
	while (T--)
		print << solve() << endl;
}
